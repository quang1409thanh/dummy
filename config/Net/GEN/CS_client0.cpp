/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* TODO: This is default demo code */
/* ================================ [ INCLUDES  ] ============================================== */
extern "C" {
#include "CS_client0.h"
#include "SomeIp_Cfg.h"
}
#include "usomeip/usomeip.hpp"
#include "usomeip/client.hpp"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void SomeIp_client0_OnAvailability(boolean isAvailable) {
  as::usomeip::client::on_availability(SOMEIP_CSID_CLIENT_0, isAvailable);
}

Std_ReturnType SomeIp_client0_method2_OnResponse(uint32_t requestId, SomeIp_MessageType* res) {
  return as::usomeip::client::on_response(SOMEIP_TX_METHOD_CLIENT_0_METHOD_2, requestId, res);
}

Std_ReturnType SomeIp_client0_method2_OnError(uint32_t requestId, Std_ReturnType ercd) {
  return as::usomeip::client::on_error(SOMEIP_TX_METHOD_CLIENT_0_METHOD_2, requestId, ercd);
}

Std_ReturnType SomeIp_client0_method2_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::client::on_method_tp_rx_data(SOMEIP_TX_METHOD_CLIENT_0_METHOD_2, requestId, msg);
}

Std_ReturnType SomeIp_client0_method2_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::client::on_method_tp_tx_data(SOMEIP_TX_METHOD_CLIENT_0_METHOD_2, requestId, msg);
}

Std_ReturnType SomeIp_client0_event_group2_event0_OnNotification(uint32_t requestId, SomeIp_MessageType* evt) {
  return as::usomeip::client::on_notification(SOMEIP_RX_EVT_CLIENT_0_EVENT_GROUP_2_EVENT_0, requestId, evt);
}

Std_ReturnType SomeIp_client0_event_group2_event0_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg) {
  return as::usomeip::client::on_event_tp_rx_data(SOMEIP_RX_EVT_CLIENT_0_EVENT_GROUP_2_EVENT_0, requestId, msg);
}

