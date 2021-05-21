#include "print.c"
#include "idt.c"
#include "outb_inb.c"
#include "cursor.c"
#include "keyboard.c"

extern void StartIDT();

int _start()
{
	enable_cursor(0,25);
	char String[20] = "Kernel Loaded...    ";
    PrintStringXY(String,20,0,10);
    InitializeIDT();
    PrintStringXY("IDT Loaded",10,0,11);
    //Enabled Cursor and Remember Text Mode Stays in 80x25
    while(1);
}