/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "NetMem.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static uint32_t MC_Net_small_Buffer[(4096+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static uint32_t MC_Net_middle_Buffer[(11360+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static uint32_t MC_Net_large_Buffer[(8192+sizeof(uint32_t) - 1)/sizeof(uint32_t)];
static const mem_cluster_cfg_t MC_NetCfgs[] = {
  {
    (uint8_t*)MC_Net_small_Buffer,
    128,
    32,
  },
  {
    (uint8_t*)MC_Net_middle_Buffer,
    1420,
    8,
  },
  {
    (uint8_t*)MC_Net_large_Buffer,
    4096,
    2,
  },
};

static mempool_t MC_NetPools[3];
static const mem_cluster_t MC_Net = {
  MC_NetPools,
  MC_NetCfgs,
  3,
};

/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void Net_MemInit(void) {
  mc_init(&MC_Net);
}

void* Net_MemAlloc(uint32_t size) {
  return (void*)mc_alloc(&MC_Net, size);
}

void* Net_MemGet(uint32_t *size) {
  return (void*)mc_get(&MC_Net, size);
}

void Net_MemFree(void* buffer) {
  mc_free(&MC_Net, (uint8_t*)buffer);
}

