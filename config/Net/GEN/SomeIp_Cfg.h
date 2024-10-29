/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef _SOMEIP_CFG_H
#define _SOMEIP_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#define SOMEIP_SSID_SERVER_0 0
#define SOMEIP_CSID_CLIENT_0 1

#define SOMEIP_RX_PID_SOMEIP_SERVER_0 0
#define SOMEIP_TX_PID_SOMEIP_SERVER_0 0
#define SOMEIP_RX_PID_SOMEIP_CLIENT_0 1
#define SOMEIP_TX_PID_SOMEIP_CLIENT_0 1

#define SOMEIP_RX_METHOD_SERVER_0_METHOD_1 0

#define SOMEIP_TX_METHOD_CLIENT_0_METHOD_2 0

#define SOMEIP_TX_EVT_SERVER_0_EVENT_GROUP_1_EVENT_0 0

#define SOMEIP_RX_EVT_CLIENT_0_EVENT_GROUP_2_EVENT_0 0

#define SOMEIP_MAIN_FUNCTION_PERIOD 10
#define SOMEIP_CONVERT_MS_TO_MAIN_CYCLES(x) \
  ((x + SOMEIP_MAIN_FUNCTION_PERIOD - 1) / SOMEIP_MAIN_FUNCTION_PERIOD)
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* _SOMEIP_CFG_H */
