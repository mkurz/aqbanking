/***************************************************************************
 $RCSfile$
 -------------------
 cvs         : $Id$
 begin       : Mon Mar 01 2004
 copyright   : (C) 2004 by Martin Preuss
 email       : martin@libchipcard.de

 ***************************************************************************
 *          Please see toplevel file COPYING for license details           *
 ***************************************************************************/


#ifndef AQBANKING_BANKINFOPLUGIN_BE_H
#define AQBANKING_BANKINFOPLUGIN_BE_H

#include <aqbanking/bankinfoplugin.h>


typedef struct AB_BANKINFO_PLUGIN AB_BANKINFO_PLUGIN;

#include <aqbanking/banking.h>
#include <gwenhywfar/inherit.h>
#include <gwenhywfar/misc.h>
#include <gwenhywfar/list2.h>


GWEN_INHERIT_FUNCTION_LIB_DEFS(AB_BANKINFO_PLUGIN,
                               AQBANKING_API)
GWEN_LIST2_FUNCTION_LIB_DEFS(AB_BANKINFO_PLUGIN,
                             AB_BankInfoPlugin,
                             AQBANKING_API)


typedef AB_BANKINFO_PLUGIN*
  (*AB_BANKINFO_PLUGIN_FACTORY_FN)(AB_BANKING *ab,
                                   GWEN_DB_NODE *db);



/** @name Prototypes For Virtual Functions
 *
 */
/*@{*/
typedef AB_BANKINFO*
  (*AB_BANKINFOPLUGIN_GETBANKINFO_FN)(AB_BANKINFO_PLUGIN *bip,
                                      const char *branchId,
                                      const char *bankId);
typedef AB_BANKINFO_CHECKRESULT
  (*AB_BANKINFOPLUGIN_CHECKACCOUNT_FN)(AB_BANKINFO_PLUGIN *bip,
                                       const char *branchId,
                                       const char *bankId,
                                       const char *accountId);
/*@}*/



/** @name Constructors, Destructors
 *
 */
/*@{*/
AB_BANKINFO_PLUGIN *AB_BankInfoPlugin_new(const char *country);
void AB_BankInfoPlugin_free(AB_BANKINFO_PLUGIN *bip);
void AB_BankInfoPlugin_Attach(AB_BANKINFO_PLUGIN *bip);
/*@}*/



/** @name Informational Functions
 *
 */
/*@{*/
const char *AB_BankInfoPlugin_GetCountry(const AB_BANKINFO_PLUGIN *bip);
/*@}*/



/** @name Virtual Functions
 *
 */
/*@{*/
AB_BANKINFO *AB_BankInfoPlugin_GetBankInfo(AB_BANKINFO_PLUGIN *bip,
                                           const char *branchId,
                                           const char *bankId);

AB_BANKINFO_CHECKRESULT
  AB_BankInfoPlugin_CheckAccount(AB_BANKINFO_PLUGIN *bip,
                                 const char *branchId,
                                 const char *bankId,
                                 const char *accountId);
/*@}*/


/** @name Setters For Virtual Functions
 *
 */
/*@{*/
void AB_BankInfoPlugin_SetGetBankInfoFn(AB_BANKINFO_PLUGIN *bip,
                                        AB_BANKINFOPLUGIN_GETBANKINFO_FN f);
void AB_BankInfoPlugin_SetCheckAccountFn(AB_BANKINFO_PLUGIN *bip,
                                         AB_BANKINFOPLUGIN_CHECKACCOUNT_FN f);
/*@}*/


#endif /* AQBANKING_BANKINFOPLUGIN_BE_H */




