#pragma once
#include "types.h"
#include "print.c"
#include "outb_inb.c"

void keyboard_isr() {
	PrintStringXY((char *)((uint_64)(inb(0x60))),4,0,13);
	return;
}