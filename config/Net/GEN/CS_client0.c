/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* TODO: This is default demo code */
/* ================================ [ INCLUDES  ] ============================================== */
#include "CS_client0.h"
#include "Std_Debug.h"
#include "SomeIp_Cfg.h"
#include <string.h>
/* ================================ [ MACROS    ] ============================================== */
#define AS_LOG_CLIENT_0 1
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static boolean lIsAvailable = FALSE;
static uint8_t client0_method2TpRxBuf[1048576];
static uint8_t client0_method2TpTxBuf[1048576];
static uint8_t client0_event_group2_event0TpRxBuf[1048576];
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void SomeIp_client0_OnAvailability(boolean isAvailable) {
  ASLOG(CLIENT_0, ("%s\n", isAvailable?"online":"offline"));
  lIsAvailable = isAvailable;
}

Std_ReturnType client0_method2_request(uint8_t *data, uint32_t length) {
  Std_ReturnType ercd = E_NOT_OK;
  static uint16_t sessionId = 0;
  uint32_t requestId = ((uint32_t)SOMEIP_TX_METHOD_CLIENT_0_METHOD_2 << 16) | (++sessionId);
  memcpy(client0_method2TpTxBuf, data, length);
  data = client0_method2TpTxBuf;
  length = 5000;
  if (lIsAvailable) {
    ASLOG(CLIENT_0, ("method2 Request %X: len=%d, data=[%02X %02X %02X %02X ...]\n",
          requestId, length, data[0], data[1], data[2], data[3]));
    ercd = SomeIp_Request(requestId, data, length);
  }
  return ercd;
}

Std_ReturnType SomeIp_client0_method2_OnResponse(uint32_t requestId, SomeIp_MessageType* res) {
  ASLOG(CLIENT_0, ("method2 OnResponse %X: len=%d, data=[%02X %02X %02X %02X ...]\n",
        requestId, res->length, res->data[0], res->data[1], res->data[2], res->data[3]));
  return E_OK;
}

Std_ReturnType SomeIp_client0_method2_OnError(uint32_t requestId, Std_ReturnType ercd) {
  ASLOG(CLIENT_0, ("method2 OnError %X: %d\n", requestId, ercd));
  return E_OK;
}

Std_ReturnType SomeIp_client0_method2_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length)) < sizeof(client0_method2TpRxBuf)) {
    memcpy(&client0_method2TpRxBuf[msg->offset], msg->data, msg->length);
    if (FALSE == msg->moreSegmentsFlag) {
      msg->data = client0_method2TpRxBuf;
    }
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

Std_ReturnType SomeIp_client0_method2_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length) < sizeof(client0_method2TpTxBuf))) {
    memcpy(msg->data, &client0_method2TpTxBuf[msg->offset], msg->length);
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

Std_ReturnType SomeIp_client0_event_group2_event0_OnNotification(uint32_t requestId, SomeIp_MessageType* evt) {
  ASLOG(CLIENT_0, ("event0 OnNotification %X: len=%d, data=[%02X %02X %02X %02X ...]\n",
        requestId, evt->length, evt->data[0], evt->data[1], evt->data[2], evt->data[3]));
  return E_OK;
}

Std_ReturnType SomeIp_client0_event_group2_event0_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  Std_ReturnType ret = E_OK;
  if ((NULL != msg) && ((msg->offset + msg->length)) < sizeof(client0_event_group2_event0TpRxBuf)) {
    memcpy(&client0_event_group2_event0TpRxBuf[msg->offset], msg->data, msg->length);
    if (FALSE == msg->moreSegmentsFlag) {
      msg->data = client0_event_group2_event0TpRxBuf;
    }
  } else {
    ret = E_NOT_OK;
  }
  return ret;
}

