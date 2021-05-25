#pragma once
#include "outb_inb.c"

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
	return;
} 

void enable_cursor(uint_8 cursor_start, uint_8 cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
	return;
} 

void update_cursor(int x, int y)
{
	uint_16 pos = y * 80 + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint_8) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint_8) ((pos >> 8) & 0xFF));
}