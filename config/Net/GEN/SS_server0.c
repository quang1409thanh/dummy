/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* TODO: This is default demo code */
/* ================================ [ INCLUDES  ] ============================================== */
#include "SS_server0.h"
#include "SomeIp_Cfg.h"
#include "Std_Debug.h"
#include <string.h>
/* ================================ [ MACROS    ] ============================================== */
#define AS_LOG_SERVER_0 1
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static uint8_t server0_method1TpRxBuf[1048576];
static uint8_t server0_method1TpTxBuf[1048576];
static uint8_t server0_event_group1_event0TpTxBuf[1048576];
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void SomeIp_server0_OnConnect(uint16_t conId, boolean isConnected) {
}

Std_ReturnType SomeIp_server0_method1_OnRequest(uint32_t requestId, SomeIp_MessageType* req, SomeIp_MessageType* res) {
  res->data = server0_method1TpTxBuf;
  memcpy(res->data, req->data, req->length);
  res->length = req->length;
  ASLOG(SERVER_0, ("method1 OnRequest %X: len=%d, data=[%02X %02X %02X %02X ...]\n",
    requestId, req->length, req->data[0], req->data[1], req->data[2], req->data[3]));
  return E_OK;
}

Std_ReturnType SomeIp_server0_method1_OnFireForgot(uint32_t requestId,SomeIp_MessageType* req) {
  ASLOG(SERVER_0, ("method1 OnFireForgot %X: len=%d, data=[%02X %02X %02X %02X ...]\n",
    requestId, req->length, req->data[0], req->data[1], req->data[2], req->data[3]));
  return E_OK;
}

Std_ReturnType SomeIp_server0_method1_OnAsyncRequest(uint32_t requestId, SomeIp_MessageType* res) {
  return E_OK;
}

Std_ReturnType SomeIp_server0_method1_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length)) < sizeof(server0_method1TpRxBuf)) {
    memcpy(&server0_method1TpRxBuf[msg->offset], msg->data, msg->length);
    if (FALSE == msg->moreSegmentsFlag) {
      msg->data = server0_method1TpRxBuf;
    }
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

Std_ReturnType SomeIp_server0_method1_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length) < sizeof(server0_method1TpTxBuf))) {
    memcpy(msg->data, &server0_method1TpTxBuf[msg->offset], msg->length);
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

void SomeIp_server0_event_group1_OnSubscribe(boolean isSubscribe, TcpIp_SockAddrType* RemoteAddr) {
  ASLOG(SERVER_0, ("event_group1 %ssubscribed by %d.%d.%d.%d:%d\n", isSubscribe ? "" : "stop ",
        RemoteAddr->addr[0], RemoteAddr->addr[1], RemoteAddr->addr[2], RemoteAddr->addr[3], RemoteAddr->port));
}

Std_ReturnType SomeIp_server0_event_group1_event0_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length) < sizeof(server0_event_group1_event0TpTxBuf))) {
    memcpy(msg->data, &server0_event_group1_event0TpTxBuf[msg->offset], msg->length);
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

Std_ReturnType server0_event_group1_event0_notify(uint8_t *data, uint32_t length) {
  Std_ReturnType ercd = E_NOT_OK;
  static uint16_t sessionId = 0;
  uint32_t requestId = ((uint32_t)SOMEIP_TX_EVT_SERVER_0_EVENT_GROUP_1_EVENT_0 << 16) + (++sessionId);
  memcpy(server0_event_group1_event0TpTxBuf, data, length);
  data = server0_event_group1_event0TpTxBuf;
  length = 8000;
  ercd = SomeIp_Notification(requestId, data, length);
  return ercd;
}

