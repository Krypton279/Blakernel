#pragma once 
#include "outb_inb.c"
#include "types.h"
#include "idt.h"

void InitializeIDT(){
	// IRQ1
	IDTEntries[0].offset_1 = (uint_16) ((uint_64) isr1);
	IDTEntries[0].selector = 8;
	IDTEntries[0].ist = 0;
	IDTEntries[0].type_attr = 143;
	IDTEntries[0].offset_2 = (uint_16) (((uint_64) isr1) >> 16);
	IDTEntries[0].offset_3 = (uint_32) (((uint_64) isr1) >> 32);
	IDTEntries[0].zero = 0;
	// IRQ2
	IDTEntries[1].offset_1 = (uint_16) ((uint_64) isr2);
	IDTEntries[1].selector = 8;
	IDTEntries[1].ist = 0;
	IDTEntries[1].type_attr = 143;
	IDTEntries[1].offset_2 = (uint_16) (((uint_64) isr2) >> 16);
	IDTEntries[1].offset_3 = (uint_32) (((uint_64) isr2) >> 32);
	IDTEntries[1].zero = 0;
	// IRQ3
	IDTEntries[2].offset_1 = (uint_16) ((uint_64) isr3);
	IDTEntries[2].selector = 8;
	IDTEntries[2].ist = 0;
	IDTEntries[2].type_attr = 143;
	IDTEntries[2].offset_2 = (uint_16) (((uint_64) isr3) >> 16);
	IDTEntries[2].offset_3 = (uint_32) (((uint_64) isr3) >> 32);
	IDTEntries[2].zero = 0;
	// IRQ4
	IDTEntries[3].offset_1 = (uint_16) ((uint_64) isr4);
	IDTEntries[3].selector = 8;
	IDTEntries[3].ist = 0;
	IDTEntries[3].type_attr = 143;
	IDTEntries[3].offset_2 = (uint_16) (((uint_64) isr4) >> 16);
	IDTEntries[3].offset_3 = (uint_32) (((uint_64) isr4) >> 32);
	IDTEntries[3].zero = 0;
	// IRQ5
	IDTEntries[4].offset_1 = (uint_16) ((uint_64) isr5);
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = 0;
	IDTEntries[4].type_attr = 143;
	IDTEntries[4].offset_2 = (uint_16) (((uint_64) isr5) >> 16);
	IDTEntries[4].offset_3 = (uint_32) (((uint_64) isr5) >> 32);
	IDTEntries[4].zero = 0;
	// IRQ6
	IDTEntries[5].offset_1 = (uint_16) ((uint_64) isr6);
	IDTEntries[5].selector = 8;
	IDTEntries[5].ist = 0;
	IDTEntries[5].type_attr = 143;
	IDTEntries[5].offset_2 = (uint_16) (((uint_64) isr6) >> 16);
	IDTEntries[5].offset_3 = (uint_32) (((uint_64) isr6) >> 32);
	IDTEntries[5].zero = 0;
	// IRQ7
	IDTEntries[6].offset_1 = (uint_16) ((uint_64) isr7);
	IDTEntries[6].selector = 8;
	IDTEntries[6].ist = 0;
	IDTEntries[6].type_attr = 143;
	IDTEntries[6].offset_2 = (uint_16) (((uint_64) isr7) >> 16);
	IDTEntries[6].offset_3 = (uint_32) (((uint_64) isr7) >> 32);
	IDTEntries[6].zero = 0;
	// IRQ8
	IDTEntries[7].offset_1 = (uint_16) ((uint_64) isr8);
	IDTEntries[7].selector = 8;
	IDTEntries[7].ist = 0;
	IDTEntries[7].type_attr = 143;
	IDTEntries[7].offset_2 = (uint_16) (((uint_64) isr8) >> 16);
	IDTEntries[7].offset_3 = (uint_32) (((uint_64) isr8) >> 32);
	IDTEntries[7].zero = 0;
	// IRQ9
	IDTEntries[8].offset_1 = (uint_16) ((uint_64) isr9);
	IDTEntries[8].selector = 8;
	IDTEntries[8].ist = 0;
	IDTEntries[8].type_attr = 143;
	IDTEntries[8].offset_2 = (uint_16) (((uint_64) isr9) >> 16);
	IDTEntries[8].offset_3 = (uint_32) (((uint_64) isr9) >> 32);
	IDTEntries[8].zero = 0;
	// IRQ10
	IDTEntries[9].offset_1 = (uint_16) ((uint_64) isr10);
	IDTEntries[9].selector = 8;
	IDTEntries[9].ist = 0;
	IDTEntries[9].type_attr = 143;
	IDTEntries[9].offset_2 = (uint_16) (((uint_64) isr10) >> 16);
	IDTEntries[9].offset_3 = (uint_32) (((uint_64) isr10) >> 32);
	IDTEntries[9].zero = 0;
	// IRQ11
	IDTEntries[10].offset_1 = (uint_16) ((uint_64) isr11);
	IDTEntries[10].selector = 8;
	IDTEntries[10].ist = 0;
	IDTEntries[10].type_attr = 143;
	IDTEntries[10].offset_2 = (uint_16) (((uint_64) isr11) >> 16);
	IDTEntries[10].offset_3 = (uint_32) (((uint_64) isr11) >> 32);
	IDTEntries[10].zero = 0;
	// IRQ12
	IDTEntries[11].offset_1 = (uint_16) ((uint_64) isr12);
	IDTEntries[11].selector = 8;
	IDTEntries[11].ist = 0;
	IDTEntries[11].type_attr = 143;
	IDTEntries[11].offset_2 = (uint_16) (((uint_64) isr12) >> 16);
	IDTEntries[11].offset_3 = (uint_32) (((uint_64) isr12) >> 32);
	IDTEntries[11].zero = 0;
	// IRQ1
	IDTEntries[12].offset_1 = (uint_16) ((uint_64) isr13);
	IDTEntries[12].selector = 8;
	IDTEntries[12].ist = 0;
	IDTEntries[12].type_attr = 143;
	IDTEntries[12].offset_2 = (uint_16) (((uint_64) isr13) >> 16);
	IDTEntries[12].offset_3 = (uint_32) (((uint_64) isr13) >> 32);
	IDTEntries[12].zero = 0;
	// IRQ14
	IDTEntries[13].offset_1 = (uint_16) ((uint_64) isr14);
	IDTEntries[13].selector = 8;
	IDTEntries[13].ist = 0;
	IDTEntries[13].type_attr = 143;
	IDTEntries[13].offset_2 = (uint_16) (((uint_64) isr14) >> 16);
	IDTEntries[13].offset_3 = (uint_32) (((uint_64) isr14) >> 32);
	IDTEntries[13].zero = 0;
	// IRQ15
	IDTEntries[14].offset_1 = (uint_16) ((uint_64) isr15);
	IDTEntries[14].selector = 8;
	IDTEntries[14].ist = 0;
	IDTEntries[14].type_attr = 143;
	IDTEntries[14].offset_2 = (uint_16) (((uint_64) isr15) >> 16);
	IDTEntries[14].offset_3 = (uint_32) (((uint_64) isr15) >> 32);
	IDTEntries[14].zero = 0;
	// IRQ16
	IDTEntries[15].offset_1 = (uint_16) ((uint_64) isr16);
	IDTEntries[15].selector = 8;
	IDTEntries[15].ist = 0;
	IDTEntries[15].type_attr = 143;
	IDTEntries[15].offset_2 = (uint_16) (((uint_64) isr16) >> 16);
	IDTEntries[15].offset_3 = (uint_32) (((uint_64) isr16) >> 32);
	IDTEntries[15].zero = 0;
	// IRQ17
	IDTEntries[16].offset_1 = (uint_16) ((uint_64) isr17);
	IDTEntries[16].selector = 8;
	IDTEntries[16].ist = 0;
	IDTEntries[16].type_attr = 143;
	IDTEntries[16].offset_2 = (uint_16) (((uint_64) isr17) >> 16);
	IDTEntries[16].offset_3 = (uint_32) (((uint_64) isr17) >> 32);
	IDTEntries[16].zero = 0;
	// IRQ18
	IDTEntries[17].offset_1 = (uint_16) ((uint_64) isr18);
	IDTEntries[17].selector = 8;
	IDTEntries[17].ist = 0;
	IDTEntries[17].type_attr = 143;
	IDTEntries[17].offset_2 = (uint_16) (((uint_64) isr18) >> 16);
	IDTEntries[17].offset_3 = (uint_32) (((uint_64) isr18) >> 32);
	IDTEntries[17].zero = 0;
	// IRQ19
	IDTEntries[18].offset_1 = (uint_16) ((uint_64) isr19);
	IDTEntries[18].selector = 8;
	IDTEntries[18].ist = 0;
	IDTEntries[18].type_attr = 143;
	IDTEntries[18].offset_2 = (uint_16) (((uint_64) isr19) >> 16);
	IDTEntries[18].offset_3 = (uint_32) (((uint_64) isr19) >> 32);
	IDTEntries[18].zero = 0;
	// IRQ20
	IDTEntries[19].offset_1 = (uint_16) ((uint_64) isr20);
	IDTEntries[19].selector = 8;
	IDTEntries[19].ist = 0;
	IDTEntries[19].type_attr = 143;
	IDTEntries[19].offset_2 = (uint_16) (((uint_64) isr20) >> 16);
	IDTEntries[19].offset_3 = (uint_32) (((uint_64) isr20) >> 32);
	IDTEntries[19].zero = 0;
	//Keyboard IRQ
	IDTEntries[33].offset_1 = (uint_16) ((uint_64) keyboard_handler);
	IDTEntries[33].selector = 8;
	IDTEntries[33].ist = 0;
	IDTEntries[33].type_attr = 142;
	IDTEntries[33].offset_2 = (uint_16) (((uint_64) keyboard_handler) >> 16);
	IDTEntries[33].offset_3 = (uint_32) (((uint_64) keyboard_handler) >> 32);
	//IDTinfo
	IDTinfo.limit = sizeof(struct IDTEntry) * 256;
	IDTinfo.base = &IDTEntries[0];
	//Init IDT
	//THIS IS THE PIC STUFF
    unsigned char a1, a2;
    a1 = inb(PIC1_DATA);                      
    a2 = inb(PIC2_DATA);
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC1_DATA, 32);                
    outb(PIC2_DATA, 40);                 
    outb(PIC1_DATA, 4);                       
    outb(PIC2_DATA, 2);                       
    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);
    outb(PIC1_DATA, a1);                   
    outb(PIC2_DATA, a2);
    outb(0x21,0xfd);
    outb(0xa1,0xff);
	//LOAD IDT !!
	asm volatile("lidtq (%0)" :: "r"(&IDTinfo) : "memory");
	asm("sti");
	return;
}