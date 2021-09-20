#pragma once
#include "cursor.c"

int X,Y;
int isNull;

int xyToVideoAddresses(int x,int y,char character) {
	char *VIDMEM = (char *)0xb8000;
	VIDMEM[(160 * y) + (x * 2)] = character;
	// This Expression "(160 * y) + (x * 2)" was simplified by borrrden in Discord , Thanks :D
	update_cursor(x+1,y);
	X = x + 1;
	Y = y;
	return 0;
}

int PrintStringXY(char *array,int array_size,int x,int y) {
	int i;
	for (i = 0;i < array_size;i++){
			if (array[i] == NULL){
				return 0;
			}
			xyToVideoAddresses(x+i,y,array[i]);
	}
	return 0;
}

//Conversion-Strings

char hexToStringOutput[128];

char* HexToString(int value){
  int* valPtr = &value;
  uint_8* ptr;
  uint_8 temp;
  uint_8 size = (sizeof(int)) * 2 - 1;
  uint_8 i;
  for (i = 0; i < size; i++){
    ptr = ((uint_8*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  hexToStringOutput[size + 1] = 0;
  return hexToStringOutput;
}

char integerToStringOutput[128];
char* IntegerToString(int value) {

	uint_8 isNegative = 0;

	if (value < 0) {
		isNegative = 1;
		value *= -1;
		integerToStringOutput[0] = '-';
	}

	uint_8 size = 0;
	uint_64 sizeTester = (uint_64)value;
	while (sizeTester / 10 > 0) {
		sizeTester /= 10;
		size++;
	}

	uint_8 index = 0;
	uint_64 newValue = (uint_64)value;
	while (newValue / 10 > 0) {
		uint_8 remainder = newValue % 10;
		newValue /= 10;
		integerToStringOutput[isNegative + size - index] = remainder + 48; 
		index++;
	}
	uint_8 remainder = newValue % 10;
	integerToStringOutput[isNegative + size - index] = remainder + 48;
	integerToStringOutput[isNegative + size + 1] = 0;
	return integerToStringOutput;
}
