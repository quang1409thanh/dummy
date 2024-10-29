/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef CANTP_CFG_H
#define CANTP_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#ifndef CANIF_CANTP_BASEID
#define CANIF_CANTP_BASEID 0
#endif

#define CANTP_GW_P2P_RX 0
#define CANTP_GW_P2P_TX 0
#ifndef USE_CANIF
#define CANIF_GW_P2P_TX (CANIF_CANTP_BASEID+0)
#endif
#define CANTP_GW_P2A_RX 1
#define CANTP_GW_P2A_TX 1
#ifndef USE_CANIF
#define CANIF_GW_P2A_TX (CANIF_CANTP_BASEID+1)
#endif

#define CANTP_MAIN_FUNCTION_PERIOD 10
#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x)  \
  ((x + CANTP_MAIN_FUNCTION_PERIOD - 1) / CANTP_MAIN_FUNCTION_PERIOD)
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* CANTP_CFG_H */
