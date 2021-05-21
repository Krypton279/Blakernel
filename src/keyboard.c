#pragma once
#include "types.h"
#include "print.c"

void keyboard_isr() {
	PrintStringXY("XV",2,0,14);
	outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
	return;
}