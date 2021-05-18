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
}
