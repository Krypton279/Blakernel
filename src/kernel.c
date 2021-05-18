#include "print.c"

int _start()
{
	char String[20] = "Kernel Loaded...    ";
    PrintStringXY(String,20,0,10);
    while(1);
	return 0;
}