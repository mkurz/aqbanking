/* This file is auto-generated from "message.xml" by the typemaker
   tool of Gwenhywfar. 
   Do not edit this file -- all changes will be lost! */
#ifndef MESSAGE_P_H
#define MESSAGE_P_H

#include "message_l.h"


struct AB_MESSAGE {
  GWEN_LIST_ELEMENT(AB_MESSAGE)
  int _usage;
  int _modified;

  uint32_t userId;
  uint32_t accountId;
  char *subject;
  char *text;
  GWEN_TIME *dateReceived;
};








#endif /* MESSAGE_P_H */
