/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef _CS_CLIENT_0_H
#define _CS_CLIENT_0_H
/* ================================ [ INCLUDES  ] ============================================== */
#include "SomeIp.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void SomeIp_client0_OnAvailability(boolean isAvailable);
Std_ReturnType SomeIp_client0_method2_OnResponse(uint32_t requestId, SomeIp_MessageType* res);
Std_ReturnType SomeIp_client0_method2_OnError(uint32_t requestId, Std_ReturnType ercd);
Std_ReturnType SomeIp_client0_method2_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg);
Std_ReturnType SomeIp_client0_method2_OnTpCopyTxData(uint32_t requestId, SomeIp_TpMessageType *msg);
Std_ReturnType SomeIp_client0_event_group2_event0_OnNotification(uint32_t requestId, SomeIp_MessageType* evt);
Std_ReturnType SomeIp_client0_event_group2_event0_OnTpCopyRxData(uint32_t requestId, SomeIp_TpMessageType *msg);
#endif /* _CS_CLIENT_0_H */
