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