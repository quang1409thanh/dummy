/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef NET_MEM_H
#define NET_MEM_H
/* ================================ [ INCLUDES  ] ============================================== */
#include "mempool.h"
/* ================================ [ MACROS    ] ============================================== */
#define MEMPOOL_NET_SMALL_SIZE 128
#define MEMPOOL_NET_MIDDLE_SIZE 1420
#define MEMPOOL_NET_LARGE_SIZE 4096
#define MEMPOOL_NET_MAX_SIZE 4096

/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
void Net_MemInit(void);
void* Net_MemAlloc(uint32_t size);
void* Net_MemGet(uint32_t* size);
void Net_MemFree(void* buffer);
#endif /* NET_MEM_H */
