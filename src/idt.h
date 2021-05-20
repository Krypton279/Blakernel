#include "types.c"

struct idtr {
    uint_16 limit;
    uint_32 base;
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

struct IDTEntry IDTEntries[20];

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

void InitializeIDT(){
	// IRQ1
	IDTEntries[1].offset_1 = (uint_16) isr1;
	IDTEntries[1].selector = 8;
	IDTEntries[1].ist = "\0";
	IDTEntries[1].type_attr = 15;
	IDTEntries[1].offset_2 = (uint_16) (isr1 >> 16);
	IDTEntries[1].offset_3 = (uint_32) (isr1 >> 32);
	IDTEntries[1].zero = "\0";
	// IRQ2
	IDTEntries[2].offset_1 = (uint_16) isr2;
	IDTEntries[2].selector = 8;
	IDTEntries[2].ist = "\0";
	IDTEntries[2].type_attr = 15;
	IDTEntries[2].offset_2 = (uint_16) (isr2 >> 16);
	IDTEntries[2].offset_3 = (uint_32) (isr2 >> 32);
	IDTEntries[2].zero = "\0";
	// IRQ3
	IDTEntries[3].offset_1 = (uint_16) isr3;
	IDTEntries[3].selector = 8;
	IDTEntries[3].ist = "\0";
	IDTEntries[3].type_attr = 15;
	IDTEntries[3].offset_2 = (uint_16) (isr3 >> 16);
	IDTEntries[3].offset_3 = (uint_32) (isr3 >> 32);
	IDTEntries[3].zero = "\0";
	// IRQ4
	IDTEntries[4].offset_1 = (uint_16) isr4;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr4 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr4 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ5
	IDTEntries[4].offset_1 = (uint_16) isr5;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr5 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr5 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ6
	IDTEntries[4].offset_1 = (uint_16) isr6;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr6 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr6 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ7
	IDTEntries[4].offset_1 = (uint_16) isr7;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr7 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr7 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ8
	IDTEntries[4].offset_1 = (uint_16) isr8;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr8 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr8 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ9
	IDTEntries[4].offset_1 = (uint_16) isr9;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr9 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr9 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ10
	IDTEntries[4].offset_1 = (uint_16) isr10;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr10 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr10 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ11
	IDTEntries[4].offset_1 = (uint_16) isr11;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr11 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr11 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ12
	IDTEntries[4].offset_1 = (uint_16) isr12;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr12 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr12 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ13
	IDTEntries[4].offset_1 = (uint_16) isr13;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr13 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr13 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ14
	IDTEntries[4].offset_1 = (uint_16) isr14;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr14 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr14 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ15
	IDTEntries[4].offset_1 = (uint_16) isr15;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr15 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr15 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ16
	IDTEntries[4].offset_1 = (uint_16) isr16;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr16 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr16 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ17
	IDTEntries[4].offset_1 = (uint_16) isr17;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr17 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr17 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ18
	IDTEntries[4].offset_1 = (uint_16) isr18;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr18 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr18 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ19
	IDTEntries[4].offset_1 = (uint_16) isr19;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr19 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr19 >> 32);
	IDTEntries[4].zero = "\0";
	// IRQ20
	IDTEntries[4].offset_1 = (uint_16) isr20;
	IDTEntries[4].selector = 8;
	IDTEntries[4].ist = "\0";
	IDTEntries[4].type_attr = 15;
	IDTEntries[4].offset_2 = (uint_16) (isr20 >> 16);
	IDTEntries[4].offset_3 = (uint_32) (isr20 >> 32);
	IDTEntries[4].zero = "\0";
}
