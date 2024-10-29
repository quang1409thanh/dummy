/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef _SD_CFG_H
#define _SD_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#define SD_RX_PID_MULTICAST 0
#define SD_RX_PID_UNICAST 0

#define SD_SERVER_SERVICE_HANDLE_ID_SERVER_0 0
#define SD_CLIENT_SERVICE_HANDLE_ID_CLIENT_0 0

#define SD_EVENT_HANDLER_SERVER_0_EVENT_GROUP_1 0
#define SD_CONSUMED_EVENT_GROUP_CLIENT_0_EVENT_GROUP_2 0

#define SD_MAIN_FUNCTION_PERIOD 10
#define SD_CONVERT_MS_TO_MAIN_CYCLES(x) \
  ((x + SD_MAIN_FUNCTION_PERIOD - 1) / SD_MAIN_FUNCTION_PERIOD)
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* _SD_CFG_H */
