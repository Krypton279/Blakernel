#pragma once
#include "cursor.c"

int X,Y;

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
			xyToVideoAddresses(x+i,y,array[i]);
	}
	return 0;
}

