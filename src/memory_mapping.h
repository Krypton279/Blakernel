#pragma once
#include "types.h"
#include "print.c"
extern uint_8 MemRegCounts;

struct MemoryRegionEntry {
	uint_64 Address;
	uint_64 Length;
	uint_32 MemoryType;
	uint_32 Attr_Types;
};

struct HeapAddress {
	uint_64 Address;
	int isFree;
};

int ValidMemoryIndex[10];
struct MemoryRegionEntry* MemRegs = (struct MemoryRegionEntry *) 0x500;
struct MemoryRegionEntry heapMemory;
struct HeapAddress *HeapAddresses = (struct HeapAddress*)0x100000;

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

void DivideMemSectors(){
	int k;
	for(int k = 0;k <= 522240;k++){
		PrintStringXY(IntegerToString(k),8,0,16);
		//HeapAddresses[k].isFree = 0;
	}
	return;
}

void malloc(uint_64 size){
	int remainder = size % 8;
	size = size - remainder;
	if((size % 8) != 0){
		size = size - (2*remainder);
	}

	return;
}