#pragma once
#include "types.h"

struct idtr {
    uint_16 limit;
    struct IDTEntry* base;
} __attribute__ ((packed));

struct IDTEntry {
   uint_16 offset_1;
   uint_16 selector;
   uint_8 ist;
   uint_8 type_attr;
   uint_16 offset_2;
   uint_32 offset_3;
   uint_32 zero;
} __attribute__ ((packed));

struct IDTEntry IDTEntries[256];
struct idtr IDTinfo;

extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void keyboard_handler();