/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
extern "C" {
#include "SS_server0.h"
#include "SomeIp_Cfg.h"
#include "Sd_Cfg.h"
}
#include "usomeip/usomeip.hpp"
#include "usomeip/server.hpp"
#include "Std_Debug.h"
#include <string.h>
/* ================================ [ MACROS    ] ============================================== */
#define AS_LOG_SERVER_0 1
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
extern "C" {
void SomeIp_server0_OnConnect(uint16_t conId, boolean isConnected) {
  as::usomeip::server::on_connect(SOMEIP_SSID_SERVER_0, conId, isConnected);
}

Std_ReturnType SomeIp_server0_method1_OnRequest(uint32_t requestId, SomeIp_MessageType* req, SomeIp_MessageType* res) {
  return as::usomeip::server::on_request(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, requestId, req, res);
}

Std_ReturnType SomeIp_server0_method1_OnFireForgot(uint32_t requestId,SomeIp_MessageType* req) {
  return as::usomeip::server::on_fire_forgot(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, requestId, req);
}

Std_ReturnType SomeIp_server0_method1_OnAsyncRequest(uint32_t requestId, SomeIp_MessageType* res) {
  return as::usomeip::server::on_async_request(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, requestId, res);
}

Std_ReturnType SomeIp_server0_method1_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::server::on_method_tp_rx_data(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, requestId, msg);
}

Std_ReturnType SomeIp_server0_method1_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::server::on_method_tp_tx_data(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, requestId, msg);
}

void SomeIp_server0_event_group1_OnSubscribe(boolean isSubscribe, TcpIp_SockAddrType* RemoteAddr) {
return as::usomeip::server::on_subscribe(SD_EVENT_HANDLER_SERVER_0_EVENT_GROUP_1, isSubscribe, RemoteAddr);
}

Std_ReturnType SomeIp_server0_event_group1_event0_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::server::on_event_tp_tx_data(requestId, msg);
}

}
