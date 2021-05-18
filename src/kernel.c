#include "print.c"
#include "idt.h"

int _start()
{
	char String[20] = "Kernel Loaded...    ";
    PrintStringXY(String,20,0,10);
    InitializeIDT();
    while(1);
	return 0;
}