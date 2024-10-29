/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef _SS_SERVER_0_H
#define _SS_SERVER_0_H
/* ================================ [ INCLUDES  ] ============================================== */
#include "SomeIp.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void SomeIp_server0_OnConnect(uint16_t conId, boolean isConnected);
Std_ReturnType SomeIp_server0_method1_OnRequest(uint32_t requestId, SomeIp_MessageType* req, SomeIp_MessageType* res);
Std_ReturnType SomeIp_server0_method1_OnFireForgot(uint32_t requestId, SomeIp_MessageType* res);
Std_ReturnType SomeIp_server0_method1_OnAsyncRequest(uint32_t requestId, SomeIp_MessageType* res);
Std_ReturnType SomeIp_server0_method1_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg);
Std_ReturnType SomeIp_server0_method1_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg);
void SomeIp_server0_event_group1_OnSubscribe(boolean isSubscribe, TcpIp_SockAddrType* RemoteAddr);
Std_ReturnType SomeIp_server0_event_group1_event0_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg);
#endif /* _SS_SERVER_0_H */
