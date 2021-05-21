#pragma once
#include "types.h"

__attribute__((always_inline)) 
void outb(uint_16 port, uint_8 val)
{
    asm volatile("outb %0, %1"
                :
                : "a"(val), "Nd"(port));
}

__attribute__((always_inline)) 
uint_8 inb(uint_16 port)
{
    uint_8 ret;
    asm volatile("inb %1, %0"
                : "=a"(ret)
                : "Nd"(port));
    return ret;
}