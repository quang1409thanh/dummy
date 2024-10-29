/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "CanIf.h"
#include "CanIf_Priv.h"
#include "CanTp.h"
#include "CanTp_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static const CanIf_RxPduType CanIf_RxPdus[] = {
  {
    CanTp_RxIndication,
    CANTP_GW_P2P_RX,
    0x732, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
  {
    CanTp_RxIndication,
    CANTP_GW_P2A_RX,
    0x732, /* canid */
    0xffffffff, /* mask */
    0, /* hoh */
  },
};

static const CanIf_TxPduType CanIf_TxPdus[] = {
  {
    CanTp_TxConfirmation,
    CANTP_GW_P2P_TX,
    0x731, /* canid */
    NULL, /* p_canid */
    0, /* hoh */
  },
  {
    CanTp_TxConfirmation,
    CANTP_GW_P2A_TX,
    0x7df, /* canid */
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
