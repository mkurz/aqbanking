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


#ifndef AQBANKING_BANKINFOPLUGIN_L_H
#define AQBANKING_BANKINFOPLUGIN_L_H

#define AB_BANKINFO_PLUGIN_FOLDER "bankinfo"

#include "bankinfoplugin_be.h"
#include <gwenhywfar/libloader.h>


GWEN_LIST_FUNCTION_LIB_DEFS(AB_BANKINFO_PLUGIN,
                            AB_BankInfoPlugin,
                            AQBANKING_API)


void AB_BankInfoPlugin_SetLibLoader(AB_BANKINFO_PLUGIN *bip,
                                    GWEN_LIBLOADER *ll);



#endif /* AQBANKING_BANKINFOPLUGIN_L_H */

