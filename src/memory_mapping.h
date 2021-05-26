#pragma once
#include "types.h"
extern uint_8 MemRegCounts;

struct MemoryRegionEntry {
	uint_64 Address;
	uint_64 Length;
	uint_32 MemoryType;
	uint_32 Attr_Types;
};

int ValidMemoryIndex[10];

struct MemoryRegionEntry* MemRegs = (struct MemoryRegionEntry *) 0x500;

void ValidMemRegs() { 
	int j = 0;
	for(int i = 0;i < MemRegCounts;i++){
		if(MemRegs[i].MemoryType == 1){
			ValidMemoryIndex[j] = i;
		}
	}
	return;
}