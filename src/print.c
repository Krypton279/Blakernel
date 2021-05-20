#pragma once

int xyToVideoAddresses(int x,int y,char character) {
	char *VIDMEM = (char *)0xb8000;
	VIDMEM[(160 * y) + (x * 2)] = character;
	// This Expression "(160 * y) + (x * 2)" was simplified by borrrden in Discord , Thanks :D
	return 0;
}

int PrintStringXY(char *array,int array_size,int x,int y) {
	for (int i = 0;i < array_size;i++){
			xyToVideoAddresses(x+i,y,array[i]);
	}
	return 0;
}