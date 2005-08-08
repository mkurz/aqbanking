/***************************************************************************
 $RCSfile$
 -------------------
 cvs         : $Id$
 begin       : Tue May 03 2005
 copyright   : (C) 2005 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include "globals.h"

#include <aqhbci/outbox.h>
#include <aqhbci/adminjobs.h>

#include <gwenhywfar/text.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int getKeys(AB_BANKING *ab,
            GWEN_DB_NODE *dbArgs,
            int argc,
            char **argv) {
  GWEN_DB_NODE *db;
  AB_PROVIDER *pro;
  AH_HBCI *hbci;
  AH_CUSTOMER_LIST2 *cl;
  AH_CUSTOMER *cu=0;
  int rv;
  const char *bankId;
  const char *userId;
  const char *customerId;
  const GWEN_ARGS args[]={
  {
    GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
    GWEN_ArgsTypeChar,            /* type */
    "bankId",                     /* name */
    0,                            /* minnum */
    1,                            /* maxnum */
    "b",                          /* short option */
    "bank",                       /* long option */
    "Specify the bank code",      /* short description */
    "Specify the bank code"       /* long description */
  },
  {
    GWEN_ARGS_FLAGS_HAS_ARGUMENT, /* flags */
    GWEN_ArgsTypeChar,            /* type */
    "customerId",                 /* name */
    0,                            /* minnum */
    1,                            /* maxnum */
    "c",                          /* short option */
    "customer",                   /* long option */
    "Specify the customer id",    /* short description */
    "Specify the customer id"     /* long description */
  },
  {
    GWEN_ARGS_FLAGS_HELP | GWEN_ARGS_FLAGS_LAST, /* flags */
    GWEN_ArgsTypeInt,             /* type */
    "help",                       /* name */
    0,                            /* minnum */
    0,                            /* maxnum */
    "h",                          /* short option */
    "help",                       /* long option */
    "Show this help screen",      /* short description */
    "Show this help screen"       /* long description */
  }
  };

  db=GWEN_DB_GetGroup(dbArgs, GWEN_DB_FLAGS_DEFAULT, "local");
  rv=GWEN_Args_Check(argc, argv, 1,
                     0 /*GWEN_ARGS_MODE_ALLOW_FREEPARAM*/,
                     args,
                     db);
  if (rv==GWEN_ARGS_RESULT_ERROR) {
    fprintf(stderr, "ERROR: Could not parse arguments\n");
    return 1;
  }
  else if (rv==GWEN_ARGS_RESULT_HELP) {
    GWEN_BUFFER *ubuf;

    ubuf=GWEN_Buffer_new(0, 1024, 0, 1);
    if (GWEN_Args_Usage(args, ubuf, GWEN_ArgsOutTypeTXT)) {
      fprintf(stderr, "ERROR: Could not create help string\n");
      return 1;
    }
    fprintf(stderr, "%s\n", GWEN_Buffer_GetStart(ubuf));
    GWEN_Buffer_free(ubuf);
    return 0;
  }

  rv=AB_Banking_Init(ab);
  if (rv) {
    DBG_ERROR(0, "Error on init (%d)", rv);
    return 2;
  }

  pro=AB_Banking_GetProvider(ab, "aqhbci");
  assert(pro);
  hbci=AH_Provider_GetHbci(pro);
  assert(hbci);

  bankId=GWEN_DB_GetCharValue(db, "bankId", 0, "*");
  userId=GWEN_DB_GetCharValue(db, "userId", 0, "*");
  customerId=GWEN_DB_GetCharValue(db, "customerId", 0, "*");

  cl=AH_HBCI_GetCustomers(hbci, 280, bankId, userId, customerId);
  if (cl) {
    if (AH_Customer_List2_GetSize(cl)!=1) {
      DBG_ERROR(0, "Ambiguous customer specification");
      AB_Banking_Fini(ab);
      return 3;
    }
    else {
      AH_CUSTOMER_LIST2_ITERATOR *cit;

      cit=AH_Customer_List2_First(cl);
      assert(cit);
      cu=AH_Customer_List2Iterator_Data(cit);
      AH_Customer_List2Iterator_free(cit);
    }
    AH_Customer_List2_free(cl);
  }
  if (!cu) {
    DBG_ERROR(0, "No matching customer");
    AB_Banking_Fini(ab);
    return 3;
  }
  else {
    AH_JOB *job;
    AH_OUTBOX *ob;

    job=AH_Job_GetKeys_new(cu);
    if (!job) {
      DBG_ERROR(0, "Job not supported, should not happen");
      AB_Banking_Fini(ab);
      return 3;
    }

    ob=AH_Outbox_new(hbci);
    AH_Outbox_AddJob(ob, job);

    if (AH_Outbox_Execute(ob, 1, 0)) {
      DBG_ERROR(0, "Could not execute outbox.\n");
      AH_Outbox_free(ob);
      AB_Banking_Fini(ab);
      return 3;
    }

    if (AH_Job_HasErrors(job) || AH_Job_GetStatus(job)!=AH_JobStatusAnswered) {
      DBG_ERROR(0, "Job has errors (%s)",
		AH_Job_StatusName(AH_Job_GetStatus(job)));
      // TODO: show errors
      AH_Outbox_free(ob);
      AB_Banking_Fini(ab);
      return 3;
    }
    else {
      if (AH_Job_Commit(job)) {
	DBG_ERROR(0, "Could not commit result.\n");
	AH_Outbox_free(ob);
        AB_Banking_Fini(ab);
	return 3;
      }
    }

    AH_Outbox_free(ob);

    /* check whether we got some accounts */
    if (!AH_Job_GetKeys_GetSignKey(job) &&
        !AH_Job_GetKeys_GetCryptKey(job)) {
      DBG_ERROR(0, "No server keys received");
      AB_Banking_Fini(ab);
      return 3;
    }
    else {
      fprintf(stderr, "Server key(s) received\n");
    }

    AH_Job_free(job);
  }


  rv=AB_Banking_Fini(ab);
  if (rv) {
    fprintf(stderr, "ERROR: Error on deinit (%d)\n", rv);
    return 5;
  }

  return 0;
}



