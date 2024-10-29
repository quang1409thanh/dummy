/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "CanIf.h"
#include "CanIf_Priv.h"
#include "CanTSyn.h"
#include "PduR_CanIf.h"
#include "PduR_Cfg.h"
#include "OsekNm.h"
#include "CanNm.h"
#include "CanTp.h"
#include "CanTp_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static const CanIf_RxPduType CanIf_RxPdus[] = {
  {
    CanTSyn_RxIndication,
    0, /* NetId */
    0x100, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
  {
    PduR_CanIfRxIndication,
    PDUR_CAN0_RX_MSG_ABS_INFO,
    0x102, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
  {
    OsekNm_RxIndication,
    0, /* NetId */
    0x400, /* canid */
    0x700, /* mask */
    0, /* hoh */
  },
  {
    CanNm_RxIndication,
    0, /* NetId */
    0x500, /* canid */
    0x700, /* mask */
    0, /* hoh */
  },
  {
    CanTp_RxIndication,
    CANTP_P2P_RX,
    0x731, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
  {
    CanTp_RxIndication,
    CANTP_P2A_RX,
    0x7df, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
};

static Can_IdType canidOfOSEKNM_TX = 0x400;
static Can_IdType canidOfCANNM_TX = 0x500;
static const CanIf_TxPduType CanIf_TxPdus[] = {
  {
    CanTSyn_TxConfirmation,
    0, /* NetId */
    0x100, /* canid */
    NULL, /* p_canid */
    0, /* hoh */
  },
  {
    PduR_CanIfTxConfirmation,
    PDUR_CAN0_TX_MSG_TIME,
    0x101, /* canid */
    NULL, /* p_canid */
    0, /* hoh */
  },
  {
    OsekNm_TxConfirmation,
    0, /* NetId */
    0x400, /* canid */
    &canidOfOSEKNM_TX, /* p_canid */
    0, /* hoh */
  },
  {
    CanNm_TxConfirmation,
    0, /* NetId */
    0x500, /* canid */
    &canidOfCANNM_TX, /* p_canid */
    0, /* hoh */
  },
  {
    CanTp_TxConfirmation,
    CANTP_P2P_TX,
    0x732, /* canid */
    NULL, /* p_canid */
    0, /* hoh */
  },
  {
    CanTp_TxConfirmation,
    CANTP_P2A_TX,
    0x732, /* canid */
    NULL, /* p_canid */
    0, /* hoh */
  },
};

const CanIf_ConfigType CanIf_Config = {
  CanIf_RxPdus,
  CanIf_TxPdus,
  ARRAY_SIZE(CanIf_RxPdus),
  ARRAY_SIZE(CanIf_TxPdus),
};

/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
