#include<stdint.h>
#include"common.h"
#pragma once

#define ALLOC_CNT	16383 /* (__heap_end -__heap_start)/4096  - 1 block for usage*/	

#define PAGE_SIZE	4096 /*1 page:4096 bytes*/

static int heap[ALLOC_CNT];

static bool usage[ALLOC_CNT]={0};

struct sbiret {
	long error;
	long value;
};

struct trap_info {
	uint32_t ra;
	uint32_t gp;
	uint32_t tp;
	uint32_t t0;
	uint32_t t1;
	uint32_t t2;
	uint32_t t3;
	uint32_t t4;
	uint32_t t5;
	uint32_t t6;
	uint32_t a0;
	uint32_t a1;
	uint32_t a2;
	uint32_t a3;
	uint32_t a4;
	uint32_t a5;
	uint32_t a6;
	uint32_t a7;
	uint32_t s0;
	uint32_t s1;
	uint32_t s2;
	uint32_t s3;
	uint32_t s4;
	uint32_t s5;
	uint32_t s6;
	uint32_t s7;
	uint32_t s8;
	uint32_t s9;
	uint32_t s10;
	uint32_t s11;
	uint32_t sp;
};__attribute__((packed))

#define panic(fmt, ...)									\
	do {										\
		printf("PANIC:%s:%d "fmt"\n",__FILE__, __LINE__,##__VA_ARGS__);		\
		while(1){}								\
	}while(0)	

