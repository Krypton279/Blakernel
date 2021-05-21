#pragma once
#include "types.h"
#include "print.c"

void keyboard_isr() {
	xyToVideoAddresses(0,15,'X');
	outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
	return;
}