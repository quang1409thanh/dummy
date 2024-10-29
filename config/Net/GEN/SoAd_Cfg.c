/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "SoAd.h"
#include "SoAd_Cfg.h"
#include "SoAd_Priv.h"
#include "DoIP.h"
#include "DoIP_Cfg.h"
#include "Sd.h"
#include "Sd_Cfg.h"
#include "SomeIp.h"
#include "SomeIp_Cfg.h"
#include "UdpNm.h"
#include "../UdpNm_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static const SoAd_IfInterfaceType SoAd_DoIP_IF = {
  DoIP_SoAdIfRxIndication,
  NULL,
  DoIP_SoAdIfTxConfirmation,
};

static const SoAd_TpInterfaceType SoAd_DoIP_TP_IF = {
  DoIP_SoAdTpStartOfReception,
  DoIP_SoAdTpCopyRxData,
  NULL,
  NULL,
  NULL,
};

static const SoAd_IfInterfaceType SoAd_SD_IF = {
  Sd_RxIndication,
  NULL,
  NULL,
};

static const SoAd_IfInterfaceType SoAd_UdpNm_IF = {
  UdpNm_SoAdIfRxIndication,
  NULL,
  UdpNm_SoAdIfTxConfirmation,
};

static const SoAd_IfInterfaceType SoAd_SOMEIP_IF = {
  SomeIp_RxIndication,
  NULL,
  NULL,
};

static const SoAd_SocketConnectionType SoAd_SocketConnections[] = {
  {
    UDPNM_RX_PID_CHL0, /* RxPduId */
    SOAD_SOCKID_UDPNM_CHL0, /* SoConId */
    0, /* GID */
    SOAD_SOCON_UDP_SERVER, /* SoConType */
  },
  {
    DOIP_RX_PID_UDP, /* RxPduId */
    SOAD_SOCKID_DOIP_UDP, /* SoConId */
    1, /* GID */
    SOAD_SOCON_UDP_SERVER, /* SoConType */
  },
  {
    -1, /* RxPduId */
    SOAD_SOCKID_DOIP_TCP_SERVER, /* SoConId */
    2, /* GID */
    SOAD_SOCON_TCP_SERVER, /* SoConType */
  },
  {
    DOIP_RX_PID_TCP0, /* RxPduId */
    SOAD_SOCKID_DOIP_TCP_APT0, /* SoConId */
    2, /* GID */
    SOAD_SOCON_TCP_ACCEPT, /* SoConType */
  },
  {
    DOIP_RX_PID_TCP1, /* RxPduId */
    SOAD_SOCKID_DOIP_TCP_APT1, /* SoConId */
    2, /* GID */
    SOAD_SOCON_TCP_ACCEPT, /* SoConType */
  },
  {
    DOIP_RX_PID_TCP2, /* RxPduId */
    SOAD_SOCKID_DOIP_TCP_APT2, /* SoConId */
    2, /* GID */
    SOAD_SOCON_TCP_ACCEPT, /* SoConType */
  },
  {
    SD_RX_PID_MULTICAST, /* RxPduId */
    SOAD_SOCKID_SD_MULTICAST, /* SoConId */
    3, /* GID */
    SOAD_SOCON_UDP_SERVER, /* SoConType */
  },
  {
    SD_RX_PID_UNICAST, /* RxPduId */
    SOAD_SOCKID_SD_UNICAST, /* SoConId */
    4, /* GID */
    SOAD_SOCON_UDP_SERVER, /* SoConType */
  },
  {
    SOMEIP_RX_PID_SOMEIP_SERVER_0, /* RxPduId */
    SOAD_SOCKID_SOMEIP_SERVER_0, /* SoConId */
    5, /* GID */
    SOAD_SOCON_UDP_SERVER, /* SoConType */
  },
  {
    SOMEIP_RX_PID_SOMEIP_CLIENT_0, /* RxPduId */
    SOAD_SOCKID_SOMEIP_CLIENT_0, /* SoConId */
    6, /* GID */
    SOAD_SOCON_UDP_CLIENT, /* SoConType */
  },
};

static SoAd_SocketContextType SoAd_SocketContexts[ARRAY_SIZE(SoAd_SocketConnections)];

static const SoAd_SocketConnectionGroupType SoAd_SocketConnectionGroups[] = {
  {
    /* 0: UDPNM_CHL0 */
    &SoAd_UdpNm_IF, /* Interface */
    NULL, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    TCPIP_IPV4_ADDR(224,244,224,245), /* Remote */
    -1, /* SoConId */
    12345, /* Port */
    0, /* LocalAddrId */
    1, /* numOfConnections */
    TRUE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    TRUE, /* IsMulitcast */
  },
  {
    /* 1: DOIP_UDP */
    &SoAd_DoIP_IF, /* Interface */
    DoIP_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    TCPIP_IPV4_ADDR(224,244,224,245), /* Remote */
    -1, /* SoConId */
    13400, /* Port */
    0, /* LocalAddrId */
    1, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    TRUE, /* IsMulitcast */
  },
  {
    /* 2: DOIP_TCP */
    &SoAd_DoIP_TP_IF, /* Interface */
    DoIP_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_TCP, /* ProtocolType */
    0, /* Remote */
    SOAD_SOCKID_DOIP_TCP_APT0, /* SoConId */
    13400, /* Port */
    TCPIP_LOCALADDRID_ANY, /* LocalAddrId */
    3, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    TRUE, /* IsTP */
    FALSE, /* IsMulitcast */
  },
  {
    /* 3: SD_MULTICAST */
    &SoAd_SD_IF, /* Interface */
    Sd_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    TCPIP_IPV4_ADDR(224,244,224,245), /* Remote */
    -1, /* SoConId */
    30490, /* Port */
    0, /* LocalAddrId */
    1, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    TRUE, /* IsMulitcast */
  },
  {
    /* 4: SD_UNICAST */
    &SoAd_SD_IF, /* Interface */
    Sd_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    0, /* Remote */
    -1, /* SoConId */
    30490, /* Port */
    TCPIP_LOCALADDRID_ANY, /* LocalAddrId */
    1, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    FALSE, /* IsMulitcast */
  },
  {
    /* 5: SOMEIP_SERVER_0 */
    &SoAd_SOMEIP_IF, /* Interface */
    SomeIp_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    0, /* Remote */
    -1, /* SoConId */
    30560, /* Port */
    TCPIP_LOCALADDRID_ANY, /* LocalAddrId */
    1, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    FALSE, /* IsMulitcast */
  },
  {
    /* 6: SOMEIP_CLIENT_0 */
    &SoAd_SOMEIP_IF, /* Interface */
    SomeIp_SoConModeChg, /* SoConModeChgNotification */
    TCPIP_IPPROTO_UDP, /* ProtocolType */
    0, /* Remote */
    -1, /* SoConId */
    30568, /* Port */
    TCPIP_LOCALADDRID_ANY, /* LocalAddrId */
    1, /* numOfConnections */
    FALSE, /* AutomaticSoConSetup */
    FALSE, /* IsTP */
    FALSE, /* IsMulitcast */
  },
};

static const SoAd_SoConIdType TxPduIdToSoCondIdMap[] = {
  SOAD_SOCKID_UDPNM_CHL0, /* SOAD_TX_PID_UDPNM_CHL0 */
  SOAD_SOCKID_DOIP_UDP, /* SOAD_TX_PID_DOIP_UDP */
  SOAD_SOCKID_DOIP_TCP_APT0, /* SOAD_TX_PID_DOIP_TCP_APT0 */
  SOAD_SOCKID_DOIP_TCP_APT1, /* SOAD_TX_PID_DOIP_TCP_APT1 */
  SOAD_SOCKID_DOIP_TCP_APT2, /* SOAD_TX_PID_DOIP_TCP_APT2 */
  SOAD_SOCKID_SD_MULTICAST, /* SOAD_TX_PID_SD_MULTICAST */
  SOAD_SOCKID_SD_UNICAST, /* SOAD_TX_PID_SD_UNICAST */
  SOAD_SOCKID_SOMEIP_SERVER_0, /* SOAD_TX_PID_SOMEIP_SERVER_0 */
  SOAD_SOCKID_SOMEIP_CLIENT_0, /* SOAD_TX_PID_SOMEIP_CLIENT_0 */
};

const SoAd_ConfigType SoAd_Config = {
  SoAd_SocketConnections,
  SoAd_SocketContexts,
  ARRAY_SIZE(SoAd_SocketConnections),
  TxPduIdToSoCondIdMap,
  ARRAY_SIZE(TxPduIdToSoCondIdMap),
  SoAd_SocketConnectionGroups,
  ARRAY_SIZE(SoAd_SocketConnectionGroups),
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
