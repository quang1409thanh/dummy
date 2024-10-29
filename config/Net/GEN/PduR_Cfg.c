/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "PduR.h"
#include "PduR_Cfg.h"
#include "PduR_Priv.h"
#include "DoIP.h"
#include "DoIP_Cfg.h"
#include "Dcm.h"
#include "CanTp.h"
#include "CanTp_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static uint32_t MC_PduR_small_Buffer[(4096+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static uint32_t MC_PduR_middle_Buffer[(11200+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static uint32_t MC_PduR_large_Buffer[(8192+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static const mem_cluster_cfg_t MC_PduRCfgs[] = {
  {
    (uint8_t*)MC_PduR_small_Buffer,
    128,
    32,
  },
  {
    (uint8_t*)MC_PduR_middle_Buffer,
    1400,
    8,
  },
  {
    (uint8_t*)MC_PduR_large_Buffer,
    4096,
    2,
  },
};

static mempool_t MC_PduRPools[3];
static const mem_cluster_t MC_PduR = {
  MC_PduRPools,
  MC_PduRCfgs,
  3,
};

const PduR_ApiType PduR_DcmApi = {
  Dcm_StartOfReception,
  Dcm_CopyRxData,
  { (void_ptr_t)Dcm_TpRxIndication },
  NULL,
  Dcm_CopyTxData,
  Dcm_TpTxConfirmation,
};

const PduR_ApiType PduR_DoIPApi = {
  PduR_DoIPGwStartOfReception,
  PduR_DoIPGwCopyRxData,
  { (void*)PduR_DoIPGwRxIndication },
  DoIP_TpTransmit,
  PduR_DoIPGwCopyTxData,
  PduR_DoIPGwTxConfirmation,
};

const PduR_ApiType PduR_CanTpApi = {
  PduR_CanTpGwStartOfReception,
  PduR_CanTpGwCopyRxData,
  { (void*)PduR_CanTpGwRxIndication },
  CanTp_Transmit,
  PduR_CanTpGwCopyTxData,
  PduR_CanTpGwTxConfirmation,
};

static const PduR_PduType PduR_SrcPdu_DoIP_Dcm_P2P_RX = {
  PDUR_MODULE_DOIP,
  DOIP_P2P_RX,
  &PduR_DoIPApi,
};

static const PduR_PduType PduR_DstPdu_DoIP_Dcm_P2P_RX[]={
  {
    PDUR_MODULE_DCM,
    DCM_P2P_RX,
    &PduR_DcmApi,
  },
};

static const PduR_PduType PduR_SrcPdu_Dcm_DoIP_P2P_TX = {
  PDUR_MODULE_DCM,
  DCM_P2P_TX,
  &PduR_DcmApi,
};

static const PduR_PduType PduR_DstPdu_Dcm_DoIP_P2P_TX[]={
  {
    PDUR_MODULE_DOIP,
    DOIP_P2P_TX,
    &PduR_DoIPApi,
  },
};

static const PduR_PduType PduR_SrcPdu_DoIP_CanTp_GW_P2P_RX = {
  PDUR_MODULE_DOIP,
  DOIP_GW_P2P_RX,
  &PduR_DoIPApi,
};

static const PduR_PduType PduR_DstPdu_DoIP_CanTp_GW_P2P_RX[]={
  {
    PDUR_MODULE_CANTP,
    CANTP_GW_P2P_RX,
    &PduR_CanTpApi,
  },
};

static PduR_BufferType PduR_Buffer_GW_P2P_RX = { NULL, 0, 0 };
static const PduR_PduType PduR_SrcPdu_CanTp_DoIP_GW_P2P_TX = {
  PDUR_MODULE_CANTP,
  CANTP_GW_P2P_TX,
  &PduR_CanTpApi,
};

static const PduR_PduType PduR_DstPdu_CanTp_DoIP_GW_P2P_TX[]={
  {
    PDUR_MODULE_DOIP,
    DOIP_GW_P2P_TX,
    &PduR_DoIPApi,
  },
};

static PduR_BufferType PduR_Buffer_GW_P2P_TX = { NULL, 0, 0 };
static const PduR_PduType PduR_SrcPdu_DoIP_CanTp_GW_P2A_RX = {
  PDUR_MODULE_DOIP,
  DOIP_GW_P2A_RX,
  &PduR_DoIPApi,
};

static const PduR_PduType PduR_DstPdu_DoIP_CanTp_GW_P2A_RX[]={
  {
    PDUR_MODULE_CANTP,
    CANTP_GW_P2A_RX,
    &PduR_CanTpApi,
  },
};

static PduR_BufferType PduR_Buffer_GW_P2A_RX = { NULL, 0, 0 };
static const PduR_PduType PduR_SrcPdu_CanTp_DoIP_GW_P2A_TX = {
  PDUR_MODULE_CANTP,
  CANTP_GW_P2A_TX,
  &PduR_CanTpApi,
};

static const PduR_PduType PduR_DstPdu_CanTp_DoIP_GW_P2A_TX[]={
  {
    PDUR_MODULE_DOIP,
    DOIP_GW_P2A_TX,
    &PduR_DoIPApi,
  },
};

static PduR_BufferType PduR_Buffer_GW_P2A_TX = { NULL, 0, 0 };
static const PduR_RoutingPathType PduR_RoutingPaths[] = {
  { /* 0: PDU P2P_RX from DoIP to Dcm P2P_RX */
    &PduR_SrcPdu_DoIP_Dcm_P2P_RX,
    PduR_DstPdu_DoIP_Dcm_P2P_RX,
    ARRAY_SIZE(PduR_DstPdu_DoIP_Dcm_P2P_RX),
    NULL,
  },
  { /* 1: PDU GW_P2P_RX from DoIP to CanTp GW_P2P_RX */
    &PduR_SrcPdu_DoIP_CanTp_GW_P2P_RX,
    PduR_DstPdu_DoIP_CanTp_GW_P2P_RX,
    ARRAY_SIZE(PduR_DstPdu_DoIP_CanTp_GW_P2P_RX),
    &PduR_Buffer_GW_P2P_RX,
  },
  { /* 2: PDU GW_P2A_RX from DoIP to CanTp GW_P2A_RX */
    &PduR_SrcPdu_DoIP_CanTp_GW_P2A_RX,
    PduR_DstPdu_DoIP_CanTp_GW_P2A_RX,
    ARRAY_SIZE(PduR_DstPdu_DoIP_CanTp_GW_P2A_RX),
    &PduR_Buffer_GW_P2A_RX,
  },
  { /* 3: PDU P2P_TX from Dcm to DoIP P2P_TX */
    &PduR_SrcPdu_Dcm_DoIP_P2P_TX,
    PduR_DstPdu_Dcm_DoIP_P2P_TX,
    ARRAY_SIZE(PduR_DstPdu_Dcm_DoIP_P2P_TX),
    NULL,
  },
  { /* 4: PDU GW_P2P_TX from CanTp to DoIP GW_P2P_TX */
    &PduR_SrcPdu_CanTp_DoIP_GW_P2P_TX,
    PduR_DstPdu_CanTp_DoIP_GW_P2P_TX,
    ARRAY_SIZE(PduR_DstPdu_CanTp_DoIP_GW_P2P_TX),
    &PduR_Buffer_GW_P2P_TX,
  },
  { /* 5: PDU GW_P2A_TX from CanTp to DoIP GW_P2A_TX */
    &PduR_SrcPdu_CanTp_DoIP_GW_P2A_TX,
    PduR_DstPdu_CanTp_DoIP_GW_P2A_TX,
    ARRAY_SIZE(PduR_DstPdu_CanTp_DoIP_GW_P2A_TX),
    &PduR_Buffer_GW_P2A_TX,
  },
};

const PduR_ConfigType PduR_Config = {
#if defined(PDUR_USE_MEMPOOL)
  &MC_PduR,
#endif
  PduR_RoutingPaths,
  ARRAY_SIZE(PduR_RoutingPaths),
  PDUR_DCM_TX_BASE_ID,
  PDUR_DOIP_RX_BASE_ID,
  PDUR_DOIP_TX_BASE_ID,
  PDUR_CANTP_RX_BASE_ID,
  PDUR_CANTP_TX_BASE_ID,
  PDUR_LINTP_RX_BASE_ID,
  PDUR_LINTP_TX_BASE_ID,
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
