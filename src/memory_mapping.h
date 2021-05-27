#pragma once
#include "types.h"
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
uint_64 HeapLengthKB = 510;
uint_64 DividedHeapAddresses[HeapLengthKB];
struct HeapAddress HeapAddresses[HeapLengthKB]; 

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
	uint_64 OffsetFromFirstDivision[(heapMemory.Length)/1024];
	uint_64 LastAddress = (heapMemory.Address + heapMemory.Length) - (heapMemory.Length/1024);
	uint_64 Length = heapMemory.Length;
	uint_64 Address = heapMemory.Address;
	for(int i = 0;i < (heapMemory.Length/1024);i++){
		OffsetFromFirstDivision[i] = i;
	}
	for(int j = 0;j < (heapMemory.Length/1024);j++){
		HeapAddresses[j].Address = heapMemory.Address + OffsetFromFirstDivision[j];
		HeapAddresses[j].isFree = 0;
	}
}

void malloc(uint_64 size){
	int remainder = size % 8;
	size = size - remainder;
	if((size % 8) != 0){
		size = size - (2*remainder);
	}

	return;
}