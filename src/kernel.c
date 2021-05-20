#include "print.c"
#include "idt.h"

extern void StartIDT();

int _start()
{
	char String[20] = "Kernel Loaded...    ";
    PrintStringXY(String,20,0,10);
    InitializeIDT();
    StartIDT();
    PrintStringXY("IDT Loaded",10,0,11);
    while(1);
}