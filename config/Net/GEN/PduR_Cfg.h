/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef PDUR_CFG_H
#define PDUR_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#define PDUR_USE_MEMPOOL
#define PDUR_USE_TP_GATEWAY
#define PDUR_DCM_TX_BASE_ID 3
#define PDUR_DOIP_RX_BASE_ID 0
#define PDUR_DOIP_TX_BASE_ID 3
#define PDUR_CANTP_RX_BASE_ID 4
#define PDUR_CANTP_TX_BASE_ID 1
#define PDUR_LINTP_RX_BASE_ID -1
#define PDUR_LINTP_TX_BASE_ID -1

#define PDUR_P2P_RX 0
#define PDUR_GW_P2P_RX 1
#define PDUR_GW_P2A_RX 2
#define PDUR_P2P_TX 3
#define PDUR_GW_P2P_TX 4
#define PDUR_GW_P2A_TX 5
#define MEMPOOL_PDUR_SMALL_SIZE 128
#define MEMPOOL_PDUR_MIDDLE_SIZE 1400
#define MEMPOOL_PDUR_LARGE_SIZE 4096
#define MEMPOOL_PDUR_MAX_SIZE 4096

/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* PDUR_CFG_H */
