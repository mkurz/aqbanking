/* This file is auto-generated from "transaction.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef TRANSACTION_H
#define TRANSACTION_H

/** @page P_AB_TRANSACTION_PUBLIC AB_Transaction (public)
This page describes the properties of AB_TRANSACTION
This type contains all important information about transactions. All text fields are in UTF-8. Please note: Since version 0.9.9.1 of AqBanking a transaction may contain splits. If an AB_TRANSACTION actually does contain splits then some variables (like
<i>localCountry</i>
) are stored within the AB_SPLITs rather than in AB_TRANSACTION. So your application should first check for splits and read the information (marked as
<i>in AB_SPLIT</i>
below) from them.<h3>Local Account Info</h3>
<p>
This group contains information about the local account. Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.</p>
@anchor AB_TRANSACTION_LocalCountry
<h4>LocalCountry</h4>
<p>
This is the two-character country code according to ISO 3166-1 (Alpha-2). This is also used in DNS toplevel domain names. For Germany use &quot;DE&quot; (not case-sensitive).</p>
<p>
Set this property with @ref AB_Transaction_SetLocalCountry, 
get it with @ref AB_Transaction_GetLocalCountry
</p>

@anchor AB_TRANSACTION_LocalBankCode
<h4>LocalBankCode</h4>
<p>
This is the code of the local bank (i.e.
<b>your</b>
bank).</p>
<p>
Set this property with @ref AB_Transaction_SetLocalBankCode, 
get it with @ref AB_Transaction_GetLocalBankCode
</p>

@anchor AB_TRANSACTION_LocalBranchId
<h4>LocalBranchId</h4>
<p>
This is the branch id of the local bank (OFX only)</p>
<p>
Set this property with @ref AB_Transaction_SetLocalBranchId, 
get it with @ref AB_Transaction_GetLocalBranchId
</p>

@anchor AB_TRANSACTION_LocalAccountNumber
<h4>LocalAccountNumber</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetLocalAccountNumber, 
get it with @ref AB_Transaction_GetLocalAccountNumber
</p>

@anchor AB_TRANSACTION_LocalSuffix
<h4>LocalSuffix</h4>
<p>
If your account has subaccounts which are distinguished by different suffixes, then this is that suffix. Otherwise it&apos;s empty. (HBCI only)</p>
<p>
Set this property with @ref AB_Transaction_SetLocalSuffix, 
get it with @ref AB_Transaction_GetLocalSuffix
</p>

@anchor AB_TRANSACTION_LocalName
<h4>LocalName</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetLocalName, 
get it with @ref AB_Transaction_GetLocalName
</p>

<h3>Remote Account Info</h3>
<p>
This group contains information about the remote account. Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.</p>
@anchor AB_TRANSACTION_RemoteCountry
<h4>RemoteCountry</h4>
<p>
This is the two-character ISO country code (as used in toplevel domains). For Germany use &quot;DE&quot;.</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteCountry, 
get it with @ref AB_Transaction_GetRemoteCountry
</p>

@anchor AB_TRANSACTION_RemoteBankName
<h4>RemoteBankName</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteBankName, 
get it with @ref AB_Transaction_GetRemoteBankName
</p>

@anchor AB_TRANSACTION_RemoteBankLocation
<h4>RemoteBankLocation</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteBankLocation, 
get it with @ref AB_Transaction_GetRemoteBankLocation
</p>

@anchor AB_TRANSACTION_RemoteBankCode
<h4>RemoteBankCode</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteBankCode, 
get it with @ref AB_Transaction_GetRemoteBankCode
</p>

@anchor AB_TRANSACTION_RemoteBranchId
<h4>RemoteBranchId</h4>
<p>
This is the branch id of the remote bank (OFX only)</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteBranchId, 
get it with @ref AB_Transaction_GetRemoteBranchId
</p>

@anchor AB_TRANSACTION_RemoteAccountNumber
<h4>RemoteAccountNumber</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteAccountNumber, 
get it with @ref AB_Transaction_GetRemoteAccountNumber
</p>

@anchor AB_TRANSACTION_RemoteSuffix
<h4>RemoteSuffix</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteSuffix, 
get it with @ref AB_Transaction_GetRemoteSuffix
</p>

@anchor AB_TRANSACTION_RemoteIban
<h4>RemoteIban</h4>
<p>
International Bank Account Number according to ECBS EBS 204.
<table>
  <tr>
    <th>Pos</th>
    <th>Meaning</th>
  </tr>
  <tr>
    <td>0-1</td>
    <td>Country code according to ISO 3166</td>
  </tr>
  <tr>
    <td>2-3</td>
    <td>Checksum</td>
  </tr>
  <tr>
    <td>4-33</td>
    <td>Country specific account info</td>
  </tr>
</table>
Examples:
<ul>
  <li>BE62510007547061</li>
  <li>FR1420041010050500013M02606</li>
</ul></p>
<p>
Set this property with @ref AB_Transaction_SetRemoteIban, 
get it with @ref AB_Transaction_GetRemoteIban
</p>

@anchor AB_TRANSACTION_RemoteName
<h4>RemoteName</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetRemoteName, 
get it with @ref AB_Transaction_GetRemoteName
</p>

@anchor AB_TRANSACTION_UniqueId
<h3>UniqueId</h3>
<p>
This is a unique id assigned by the application. However, when adding a transaction to a job (like JobTransfer) this id is assigned by AqBanking to make sure that this id is unique across all applications.</p>
<p>
Set this property with @ref AB_Transaction_SetUniqueId, 
get it with @ref AB_Transaction_GetUniqueId
</p>

<h3>Dates</h3>
<p>
</p>
@anchor AB_TRANSACTION_ValutaDate
<h4>ValutaDate</h4>
<p>
The date when the transaction was really executed (Datum Valuta/Wertstellung)</p>
<p>
Set this property with @ref AB_Transaction_SetValutaDate, 
get it with @ref AB_Transaction_GetValutaDate
</p>

@anchor AB_TRANSACTION_Date
<h4>Date</h4>
<p>
The date when the transaction was booked (but sometimes it is unused). (Buchungsdatum)</p>
<p>
Set this property with @ref AB_Transaction_SetDate, 
get it with @ref AB_Transaction_GetDate
</p>

<h3>Value</h3>
<p>
Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.</p>
@anchor AB_TRANSACTION_Value
<h4>Value</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetValue, 
get it with @ref AB_Transaction_GetValue
</p>

@anchor AB_TRANSACTION_Splits
<h3>Splits</h3>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetSplits, 
get it with @ref AB_Transaction_GetSplits
</p>

<h3>Info Which Is Not Supported by All Backends</h3>
<p>
<p>This group contains information which differ between backends.</p>
<p>
  Some of this information might not even be<b>supported</b>
  by every backends.</p></p>
@anchor AB_TRANSACTION_TextKey
<h4>TextKey</h4>
<p>
<p>A 3 digit numerical transaction code, defined for all kinds of different actions. (Textschluessel)</p>
<p>For a normal transfer you should set it to 51. For debit notes the values 04 or 05 may be used. For other values please refer to your credit institute. (HBCI only)</p></p>
<p>
Set this property with @ref AB_Transaction_SetTextKey, 
get it with @ref AB_Transaction_GetTextKey
</p>

@anchor AB_TRANSACTION_TransactionKey
<h4>TransactionKey</h4>
<p>
this is the transaction id that tells you more about the type of transaction (3 character code) (Buchungsschluessel) (HBCI only)</p>
<p>
Set this property with @ref AB_Transaction_SetTransactionKey, 
get it with @ref AB_Transaction_GetTransactionKey
</p>

@anchor AB_TRANSACTION_CustomerReference
<h4>CustomerReference</h4>
<p>
Reference string, if the customer (you) has specified one. (E.g. the cheque number.) Otherwise &quot;NONREF&quot; or empty (Kundenreferenz)</p>
<p>
Set this property with @ref AB_Transaction_SetCustomerReference, 
get it with @ref AB_Transaction_GetCustomerReference
</p>

@anchor AB_TRANSACTION_BankReference
<h4>BankReference</h4>
<p>
Reference string for this transaction given by the bank, if it has given one. Otherwise empty. (Bankreferenz)</p>
<p>
Set this property with @ref AB_Transaction_SetBankReference, 
get it with @ref AB_Transaction_GetBankReference
</p>

@anchor AB_TRANSACTION_TransactionCode
<h4>TransactionCode</h4>
<p>
A 3 digit numerical transaction code, defined for all kinds of different actions. (Geschaeftsvorfallcode)</p>
<p>
Set this property with @ref AB_Transaction_SetTransactionCode, 
get it with @ref AB_Transaction_GetTransactionCode
</p>

@anchor AB_TRANSACTION_TransactionText
<h4>TransactionText</h4>
<p>
Transaction text (e.g. STANDING ORDER) (Buchungstext)</p>
<p>
Set this property with @ref AB_Transaction_SetTransactionText, 
get it with @ref AB_Transaction_GetTransactionText
</p>

@anchor AB_TRANSACTION_Primanota
<h4>Primanota</h4>
<p>
</p>
<p>
Set this property with @ref AB_Transaction_SetPrimanota, 
get it with @ref AB_Transaction_GetPrimanota
</p>

@anchor AB_TRANSACTION_FiId
<h4>FiId</h4>
<p>
<p>This is an id optionally assigned by the Financial Institute. It is mostly used by OFX.</p></p>
<p>
Set this property with @ref AB_Transaction_SetFiId, 
get it with @ref AB_Transaction_GetFiId
</p>

@anchor AB_TRANSACTION_Purpose
<h4>Purpose</h4>
<p>
<p>This string list contains the purpose of the transaction. Every entry of this list represents a single purpose line.</p></p>
<p>
Set this property with @ref AB_Transaction_SetPurpose, 
get it with @ref AB_Transaction_GetPurpose
</p>

@anchor AB_TRANSACTION_Category
<h4>Category</h4>
<p>
<p>This string list contains the categories this transaction belongs to. This element is not used by AqBanking itself but some im/exporter plugins may choose to use these.</p></p>
<p>
Set this property with @ref AB_Transaction_SetCategory, 
get it with @ref AB_Transaction_GetCategory
</p>

<h3>Additional Information for Standing Orders</h3>
<p>
<p>This group contains information which is used with standing orders. It is not needed for other usage of this type.</p></p>
@anchor AB_TRANSACTION_Period
<h4>Period</h4>
<p>
This variable contains the execution period (e.g. whether a standing order is to be executed weekly or monthly etc).</p>
<p>
Set this property with @ref AB_Transaction_SetPeriod, 
get it with @ref AB_Transaction_GetPeriod
</p>

@anchor AB_TRANSACTION_Cycle
<h4>Cycle</h4>
<p>
The standing order is executed every
<i>cycle</i>
x
<i>period</i>
. So if
<i>period</i>
is
<i>weekly</i>
and
<i>cycle</i>
is
<i>2</i>
then the standing order is executed every 2 weeks.</p>
<p>
Set this property with @ref AB_Transaction_SetCycle, 
get it with @ref AB_Transaction_GetCycle
</p>

@anchor AB_TRANSACTION_ExecutionDay
<h4>ExecutionDay</h4>
<p>
The execution day. The meaning of this variable depends on the content of
<i>period</i>
:
<ul>
  <li>
    monthly: day of the month (starting with<i>1</i>
    )</li>
  <li>
    weekly: day of the week (starting with<i>1</i>
    =Monday)</li>
</ul></p>
<p>
Set this property with @ref AB_Transaction_SetExecutionDay, 
get it with @ref AB_Transaction_GetExecutionDay
</p>

@anchor AB_TRANSACTION_FirstExecutionDate
<h4>FirstExecutionDate</h4>
<p>
The date when the standing order is to be executed for the first time.</p>
<p>
Set this property with @ref AB_Transaction_SetFirstExecutionDate, 
get it with @ref AB_Transaction_GetFirstExecutionDate
</p>

@anchor AB_TRANSACTION_LastExecutionDate
<h4>LastExecutionDate</h4>
<p>
The date when the standing order is to be executed for the last time.</p>
<p>
Set this property with @ref AB_Transaction_SetLastExecutionDate, 
get it with @ref AB_Transaction_GetLastExecutionDate
</p>

@anchor AB_TRANSACTION_NextExecutionDate
<h4>NextExecutionDate</h4>
<p>
The date when the standing order is to be executed next (this field is only interesting when retrieving the list of currently active standing orders)</p>
<p>
Set this property with @ref AB_Transaction_SetNextExecutionDate, 
get it with @ref AB_Transaction_GetNextExecutionDate
</p>

<h3>Additional Information for Transfers</h3>
<p>
<p>This group contains information which is used with all kinds of transfers. It is setup by the function @ref AB_Banking_GatherResponses for transfers but not used by AqBanking otherwise.</p></p>
@anchor AB_TRANSACTION_Type
<h4>Type</h4>
<p>
This variable contains the type of transfer (transfer, debit note etc).</p>
<p>
Set this property with @ref AB_Transaction_SetType, 
get it with @ref AB_Transaction_GetType
</p>

@anchor AB_TRANSACTION_Status
<h4>Status</h4>
<p>
This variable contains the status of the transfer (accepted, rejected, pending). etc).</p>
<p>
Set this property with @ref AB_Transaction_SetStatus, 
get it with @ref AB_Transaction_GetStatus
</p>

*/
#include <gwenhywfar/db.h>
#include <gwenhywfar/inherit.h>
#include <gwenhywfar/list2.h>
#include <gwenhywfar/types.h>
#include <gwenhywfar/gwentime.h>
#include <gwenhywfar/stringlist.h>
#include <aqbanking/value.h>
#include <aqbanking/split.h>
#include <aqbanking/transactionlimits.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  AB_Transaction_PeriodUnknown=-1,
  /** No period.  */
  AB_Transaction_PeriodNone=0,
  /** The standing order is to be executed every month.  */
  AB_Transaction_PeriodMonthly,
  /** The standing order is to be executed every week.  */
  AB_Transaction_PeriodWeekly
} AB_TRANSACTION_PERIOD;

AB_TRANSACTION_PERIOD AB_Transaction_Period_fromString(const char *s);
const char *AB_Transaction_Period_toString(AB_TRANSACTION_PERIOD v);

typedef enum {
  AB_Transaction_TypeUnknown=-1,
  /** Simple transaction (as in transaction statements)  */
  AB_Transaction_TypeTransaction=0,
  /** Transfer type of transaction (as used with transfer jobs)  */
  AB_Transaction_TypeTransfer,
  /** Debit note type of transaction (as used with debit note jobs)  */
  AB_Transaction_TypeDebitNote,
  /** EU-Transfer type of transaction (as used for with transfer jobs)  */
  AB_Transaction_TypeEuTransfer
} AB_TRANSACTION_TYPE;

AB_TRANSACTION_TYPE AB_Transaction_Type_fromString(const char *s);
const char *AB_Transaction_Type_toString(AB_TRANSACTION_TYPE v);

typedef enum {
  AB_Transaction_StatusUnknown=-1,
  /** No status.  */
  AB_Transaction_StatusNone=0,
  /** The transfer has been accepted by the bank  */
  AB_Transaction_StatusAccepted,
  /** The transfer has been rejected by the bank (or was errornous)  */
  AB_Transaction_StatusRejected,
  /** The transfer is still pending.  */
  AB_Transaction_StatusPending
} AB_TRANSACTION_STATUS;

AB_TRANSACTION_STATUS AB_Transaction_Status_fromString(const char *s);
const char *AB_Transaction_Status_toString(AB_TRANSACTION_STATUS v);

typedef struct AB_TRANSACTION AB_TRANSACTION;

GWEN_INHERIT_FUNCTION_LIB_DEFS(AB_TRANSACTION, AQBANKING_API)
GWEN_LIST2_FUNCTION_LIB_DEFS(AB_TRANSACTION, AB_Transaction, AQBANKING_API)

/** Destroys all objects stored in the given LIST2 and the list itself
*/
AQBANKING_API void AB_Transaction_List2_freeAll(AB_TRANSACTION_LIST2 *stl);
/** Creates a deep copy of the given LIST2.
*/
AQBANKING_API AB_TRANSACTION_LIST2 *AB_Transaction_List2_dup(const AB_TRANSACTION_LIST2 *stl);

/** Creates a new object.
*/
AQBANKING_API AB_TRANSACTION *AB_Transaction_new();
/** Destroys the given object.
*/
AQBANKING_API void AB_Transaction_free(AB_TRANSACTION *st);
/** Increments the usage counter of the given object, so an additional free() is needed to destroy the object.
*/
AQBANKING_API void AB_Transaction_Attach(AB_TRANSACTION *st);
/** Creates and returns a deep copy of thegiven object.
*/
AQBANKING_API AB_TRANSACTION *AB_Transaction_dup(const AB_TRANSACTION*st);
/** Creates an object from the data in the given GWEN_DB_NODE
*/
AQBANKING_API AB_TRANSACTION *AB_Transaction_fromDb(GWEN_DB_NODE *db);
/** Stores an object in the given GWEN_DB_NODE
*/
AQBANKING_API int AB_Transaction_toDb(const AB_TRANSACTION*st, GWEN_DB_NODE *db);
/** Returns 0 if this object has not been modified, !=0 otherwise
*/
AQBANKING_API int AB_Transaction_IsModified(const AB_TRANSACTION *st);
/** Sets the modified state of the given object
*/
AQBANKING_API void AB_Transaction_SetModified(AB_TRANSACTION *st, int i);



/** @name Local Account Info
 *
This group contains information about the local account. Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_LocalCountry
*/
AQBANKING_API const char *AB_Transaction_GetLocalCountry(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalCountry
*/
AQBANKING_API void AB_Transaction_SetLocalCountry(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_LocalBankCode
*/
AQBANKING_API const char *AB_Transaction_GetLocalBankCode(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalBankCode
*/
AQBANKING_API void AB_Transaction_SetLocalBankCode(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_LocalBranchId
*/
AQBANKING_API const char *AB_Transaction_GetLocalBranchId(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalBranchId
*/
AQBANKING_API void AB_Transaction_SetLocalBranchId(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_LocalAccountNumber
*/
AQBANKING_API const char *AB_Transaction_GetLocalAccountNumber(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalAccountNumber
*/
AQBANKING_API void AB_Transaction_SetLocalAccountNumber(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_LocalSuffix
*/
AQBANKING_API const char *AB_Transaction_GetLocalSuffix(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalSuffix
*/
AQBANKING_API void AB_Transaction_SetLocalSuffix(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_LocalName
*/
AQBANKING_API const char *AB_Transaction_GetLocalName(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LocalName
*/
AQBANKING_API void AB_Transaction_SetLocalName(AB_TRANSACTION *el, const char *d);

/*@}*/

/** @name Remote Account Info
 *
This group contains information about the remote account. Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_RemoteCountry
*/
AQBANKING_API const char *AB_Transaction_GetRemoteCountry(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteCountry
*/
AQBANKING_API void AB_Transaction_SetRemoteCountry(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteBankName
*/
AQBANKING_API const char *AB_Transaction_GetRemoteBankName(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteBankName
*/
AQBANKING_API void AB_Transaction_SetRemoteBankName(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteBankLocation
*/
AQBANKING_API const char *AB_Transaction_GetRemoteBankLocation(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteBankLocation
*/
AQBANKING_API void AB_Transaction_SetRemoteBankLocation(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteBankCode
*/
AQBANKING_API const char *AB_Transaction_GetRemoteBankCode(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteBankCode
*/
AQBANKING_API void AB_Transaction_SetRemoteBankCode(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteBranchId
*/
AQBANKING_API const char *AB_Transaction_GetRemoteBranchId(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteBranchId
*/
AQBANKING_API void AB_Transaction_SetRemoteBranchId(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteAccountNumber
*/
AQBANKING_API const char *AB_Transaction_GetRemoteAccountNumber(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteAccountNumber
*/
AQBANKING_API void AB_Transaction_SetRemoteAccountNumber(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteSuffix
*/
AQBANKING_API const char *AB_Transaction_GetRemoteSuffix(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteSuffix
*/
AQBANKING_API void AB_Transaction_SetRemoteSuffix(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteIban
*/
AQBANKING_API const char *AB_Transaction_GetRemoteIban(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteIban
*/
AQBANKING_API void AB_Transaction_SetRemoteIban(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_RemoteName
*/
AQBANKING_API const GWEN_STRINGLIST *AB_Transaction_GetRemoteName(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_RemoteName
*/
AQBANKING_API void AB_Transaction_SetRemoteName(AB_TRANSACTION *el, const GWEN_STRINGLIST *d);
AQBANKING_API void AB_Transaction_AddRemoteName(AB_TRANSACTION *st, const char *d, int chk);
AQBANKING_API void AB_Transaction_RemoveRemoteName(AB_TRANSACTION *st, const char *d);
AQBANKING_API void AB_Transaction_ClearRemoteName(AB_TRANSACTION *st);
AQBANKING_API int AB_Transaction_HasRemoteName(const AB_TRANSACTION *st, const char *d);

/*@}*/

/**
* Returns the property @ref AB_TRANSACTION_UniqueId
*/
AQBANKING_API GWEN_TYPE_UINT32 AB_Transaction_GetUniqueId(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_UniqueId
*/
AQBANKING_API void AB_Transaction_SetUniqueId(AB_TRANSACTION *el, GWEN_TYPE_UINT32 d);

/** @name Dates
*/
/*@{*/
/**
* Returns the property @ref AB_TRANSACTION_ValutaDate
*/
AQBANKING_API const GWEN_TIME *AB_Transaction_GetValutaDate(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_ValutaDate
*/
AQBANKING_API void AB_Transaction_SetValutaDate(AB_TRANSACTION *el, const GWEN_TIME *d);

/**
* Returns the property @ref AB_TRANSACTION_Date
*/
AQBANKING_API const GWEN_TIME *AB_Transaction_GetDate(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Date
*/
AQBANKING_API void AB_Transaction_SetDate(AB_TRANSACTION *el, const GWEN_TIME *d);

/*@}*/

/** @name Value
 *
Functions of this group are also available in AB_SPLIT, please make your application check for splits first and use the values here as a fallback.*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_Value
*/
AQBANKING_API const AB_VALUE *AB_Transaction_GetValue(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Value
*/
AQBANKING_API void AB_Transaction_SetValue(AB_TRANSACTION *el, const AB_VALUE *d);

/*@}*/

/**
* Returns the property @ref AB_TRANSACTION_Splits
*/
AQBANKING_API AB_SPLIT_LIST *AB_Transaction_GetSplits(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Splits
*/
AQBANKING_API void AB_Transaction_SetSplits(AB_TRANSACTION *el, AB_SPLIT_LIST *d);

/** @name Info Which Is Not Supported by All Backends
 *
<p>This group contains information which differ between backends.</p>
<p>
  Some of this information might not even be<b>supported</b>
  by every backends.</p>*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_TextKey
*/
AQBANKING_API int AB_Transaction_GetTextKey(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_TextKey
*/
AQBANKING_API void AB_Transaction_SetTextKey(AB_TRANSACTION *el, int d);

/**
* Returns the property @ref AB_TRANSACTION_TransactionKey
*/
AQBANKING_API const char *AB_Transaction_GetTransactionKey(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_TransactionKey
*/
AQBANKING_API void AB_Transaction_SetTransactionKey(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_CustomerReference
*/
AQBANKING_API const char *AB_Transaction_GetCustomerReference(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_CustomerReference
*/
AQBANKING_API void AB_Transaction_SetCustomerReference(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_BankReference
*/
AQBANKING_API const char *AB_Transaction_GetBankReference(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_BankReference
*/
AQBANKING_API void AB_Transaction_SetBankReference(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_TransactionCode
*/
AQBANKING_API int AB_Transaction_GetTransactionCode(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_TransactionCode
*/
AQBANKING_API void AB_Transaction_SetTransactionCode(AB_TRANSACTION *el, int d);

/**
* Returns the property @ref AB_TRANSACTION_TransactionText
*/
AQBANKING_API const char *AB_Transaction_GetTransactionText(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_TransactionText
*/
AQBANKING_API void AB_Transaction_SetTransactionText(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_Primanota
*/
AQBANKING_API const char *AB_Transaction_GetPrimanota(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Primanota
*/
AQBANKING_API void AB_Transaction_SetPrimanota(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_FiId
*/
AQBANKING_API const char *AB_Transaction_GetFiId(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_FiId
*/
AQBANKING_API void AB_Transaction_SetFiId(AB_TRANSACTION *el, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_Purpose
*/
AQBANKING_API const GWEN_STRINGLIST *AB_Transaction_GetPurpose(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Purpose
*/
AQBANKING_API void AB_Transaction_SetPurpose(AB_TRANSACTION *el, const GWEN_STRINGLIST *d);
AQBANKING_API void AB_Transaction_AddPurpose(AB_TRANSACTION *st, const char *d, int chk);
AQBANKING_API void AB_Transaction_RemovePurpose(AB_TRANSACTION *st, const char *d);
AQBANKING_API void AB_Transaction_ClearPurpose(AB_TRANSACTION *st);
AQBANKING_API int AB_Transaction_HasPurpose(const AB_TRANSACTION *st, const char *d);

/**
* Returns the property @ref AB_TRANSACTION_Category
*/
AQBANKING_API const GWEN_STRINGLIST *AB_Transaction_GetCategory(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Category
*/
AQBANKING_API void AB_Transaction_SetCategory(AB_TRANSACTION *el, const GWEN_STRINGLIST *d);
AQBANKING_API void AB_Transaction_AddCategory(AB_TRANSACTION *st, const char *d, int chk);
AQBANKING_API void AB_Transaction_RemoveCategory(AB_TRANSACTION *st, const char *d);
AQBANKING_API void AB_Transaction_ClearCategory(AB_TRANSACTION *st);
AQBANKING_API int AB_Transaction_HasCategory(const AB_TRANSACTION *st, const char *d);

/*@}*/

/** @name Additional Information for Standing Orders
 *
<p>This group contains information which is used with standing orders. It is not needed for other usage of this type.</p>*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_Period
*/
AQBANKING_API AB_TRANSACTION_PERIOD AB_Transaction_GetPeriod(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Period
*/
AQBANKING_API void AB_Transaction_SetPeriod(AB_TRANSACTION *el, AB_TRANSACTION_PERIOD d);

/**
* Returns the property @ref AB_TRANSACTION_Cycle
*/
AQBANKING_API int AB_Transaction_GetCycle(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Cycle
*/
AQBANKING_API void AB_Transaction_SetCycle(AB_TRANSACTION *el, int d);

/**
* Returns the property @ref AB_TRANSACTION_ExecutionDay
*/
AQBANKING_API int AB_Transaction_GetExecutionDay(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_ExecutionDay
*/
AQBANKING_API void AB_Transaction_SetExecutionDay(AB_TRANSACTION *el, int d);

/**
* Returns the property @ref AB_TRANSACTION_FirstExecutionDate
*/
AQBANKING_API const GWEN_TIME *AB_Transaction_GetFirstExecutionDate(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_FirstExecutionDate
*/
AQBANKING_API void AB_Transaction_SetFirstExecutionDate(AB_TRANSACTION *el, const GWEN_TIME *d);

/**
* Returns the property @ref AB_TRANSACTION_LastExecutionDate
*/
AQBANKING_API const GWEN_TIME *AB_Transaction_GetLastExecutionDate(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_LastExecutionDate
*/
AQBANKING_API void AB_Transaction_SetLastExecutionDate(AB_TRANSACTION *el, const GWEN_TIME *d);

/**
* Returns the property @ref AB_TRANSACTION_NextExecutionDate
*/
AQBANKING_API const GWEN_TIME *AB_Transaction_GetNextExecutionDate(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_NextExecutionDate
*/
AQBANKING_API void AB_Transaction_SetNextExecutionDate(AB_TRANSACTION *el, const GWEN_TIME *d);

/*@}*/

/** @name Additional Information for Transfers
 *
<p>This group contains information which is used with all kinds of transfers. It is setup by the function @ref AB_Banking_GatherResponses for transfers but not used by AqBanking otherwise.</p>*/
/*@{*/

/**
* Returns the property @ref AB_TRANSACTION_Type
*/
AQBANKING_API AB_TRANSACTION_TYPE AB_Transaction_GetType(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Type
*/
AQBANKING_API void AB_Transaction_SetType(AB_TRANSACTION *el, AB_TRANSACTION_TYPE d);

/**
* Returns the property @ref AB_TRANSACTION_Status
*/
AQBANKING_API AB_TRANSACTION_STATUS AB_Transaction_GetStatus(const AB_TRANSACTION *el);
/**
* Set the property @ref AB_TRANSACTION_Status
*/
AQBANKING_API void AB_Transaction_SetStatus(AB_TRANSACTION *el, AB_TRANSACTION_STATUS d);

/*@}*/


#ifdef __cplusplus
} /* __cplusplus */
#endif


#endif /* TRANSACTION_H */
