#pragma once
#include "types.h"
#include "print.c"
extern uint_8 MemRegCounts;

#define SET_BIT(BF, N) BF |= ((uint_64)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint_64)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)
#define USEMEMALL 0xb00000
#define KERMEMEND 0x600000
#define DIVMEMSIZE 4096
#define HEAPMEMSTART 0x100000
#define KERMEMMAPSIZE 10485760

struct MemoryRegionEntry {
	uint_64 Address;
	uint_64 Length;
	uint_32 MemoryType;
	uint_32 Attr_Types;
};

uint_64 *MemoryMap = (uint_64 *) 0x1fc000;

int ValidMemoryIndex[10];
struct MemoryRegionEntry* MemRegs = (struct MemoryRegionEntry *) 0x500;
struct MemoryRegionEntry heapMemory;

void ValidMemRegs() { 
	int j = 0;
	for(int i = 0;i < MemRegCounts;i++){
		if(MemRegs[i].MemoryType == 1){
			ValidMemoryIndex[j] = i;
			j++;
		}
	}
	heapMemory.Address = MemRegs[ValidMemoryIndex[1]].Address;
	heapMemory.Length = MemRegs[ValidMemoryIndex[1]].Length;
	heapMemory.MemoryType = MemRegs[ValidMemoryIndex[1]].MemoryType;
	heapMemory.Attr_Types = MemRegs[ValidMemoryIndex[1]].Attr_Types;
	return;
}

void InitiateMemoryMap() {
	int j,k;
	k = 0;
	j = 0;
	for (int i = 0;i < ((heapMemory.Length-KERMEMMAPSIZE)/DIVMEMSIZE);i++){
		if(j > 63){
			k++;
			j = 0;
		}
		CLR_BIT(MemoryMap[k],j);
		j++;
	}
	return;
}

void* malloc() {
	void* returnaddr;
	int j,k;
	k = 0;
	j = 0;
	for(int i = 0;i < 4194304;i++){
		if(j > 63){
			k++;
			j = 0;
		}
		if(IS_BIT_SET(MemoryMap[k],j) == 0){

		}
		j++;
	}
}