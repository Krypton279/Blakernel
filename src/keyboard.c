#pragma once
#include "scancodes.h"
#include "types.h"
#include "print.c"

int ShiftHolded = 0;
int CapOn = 0;

void CheckAndPrintScanCodes(int ScanCode) {
	switch(ScanCode){
		case KEY_PRESSED_1:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'!');
				return;
			}
			xyToVideoAddresses(X,15,'1');
			return;
			break;
		case KEY_PRESSED_2:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'@');
				return;
			}
			xyToVideoAddresses(X,15,'2');
			return;
			break;
		case KEY_PRESSED_3:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'#');
				return;
			}
			xyToVideoAddresses(X,15,'3');
			return;
			break;
		case KEY_PRESSED_4:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'$');
				return;
			}
			xyToVideoAddresses(X,15,'4');
			return;
			break;
		case KEY_PRESSED_5:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'%');
				return;
			}
			xyToVideoAddresses(X,15,'5');
			return;
			break;
		case KEY_PRESSED_6:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'^');
				return;
			}
			xyToVideoAddresses(X,15,'6');
			return;
			break;
		case KEY_PRESSED_7:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'&');
				return;
			}
			xyToVideoAddresses(X,15,'7');
			return;
			break;
		case KEY_PRESSED_8:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'*');
				return;
			}
			xyToVideoAddresses(X,15,'8');
			return;
			break;
		case KEY_PRESSED_9:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'(');
				return;
			}
			xyToVideoAddresses(X,15,'9');
			return;
			break;
		case KEY_PRESSED_0:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,')');
				return;
			}
			xyToVideoAddresses(X,15,'X');
			return;
			break;
		case KEY_PRESSED_MINUS:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'_');
				return;
			}
			xyToVideoAddresses(X,15,'-');
			return;
			break;
		case KEY_PRESSED_EQUALS:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'+');
				return;
			}
			xyToVideoAddresses(X,15,'=');
			return;
			break;
		case KEY_PRESSED_BACKSPACE:
			xyToVideoAddresses(X,15,' ');
			return;
			break;
		case KEY_PRESSED_Q:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'Q');
				return;
			}
			xyToVideoAddresses(X,15,'q');
			return;
			break;
		case KEY_PRESSED_W:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'W');
				return;
			}
			xyToVideoAddresses(X,15,'w');
			return;
			break;
		case KEY_PRESSED_E:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'E');
				return;
			}
			xyToVideoAddresses(X,15,'e');
			return;
			break;
		case KEY_PRESSED_R:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'R');
				return;
			}
			xyToVideoAddresses(X,15,'r');
			return;
			break;
		case KEY_PRESSED_T:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'T');
				return;
			}
			xyToVideoAddresses(X,15,'t');
			return;
			break;
		case KEY_PRESSED_Y:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'Y');
				return;
			}
			xyToVideoAddresses(X,15,'y');
			return;
			break;
		case KEY_PRESSED_U:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'U');
				return;
			}
			xyToVideoAddresses(X,15,'u');
			return;
			break;
		case KEY_PRESSED_I:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'I');
				return;
			}
			xyToVideoAddresses(X,15,'i');
			return;
			break;
		case KEY_PRESSED_O:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'O');
				return;
			}
			xyToVideoAddresses(X,15,'o');
			return;
			break;
		case KEY_PRESSED_P:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'P');
				return;
			}
			xyToVideoAddresses(X,15,'p');
			return;
			break;
		case KEY_PRESSED_OPEN_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'{');
				return;
			}
			xyToVideoAddresses(X,15,'[');
			return;
			break;
		case KEY_PRESSED_CLOSE_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'}');
				return;
			}
			xyToVideoAddresses(X,15,']');
			return;
			break;
		case KEY_PRESSED_A:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'A');
				return;
			}
			xyToVideoAddresses(X,15,'a');
			return;
			break;
		case KEY_PRESSED_S:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'S');
				return;
			}
			xyToVideoAddresses(X,15,'s');
			return;
			break;
		case KEY_PRESSED_D:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'D');
				return;
			}
			xyToVideoAddresses(X,15,'d');
			return;
			break;
		case KEY_PRESSED_F:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'F');
				return;
			}
			xyToVideoAddresses(X,15,'f');
			return;
			break;
		case KEY_PRESSED_G:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'G');
				return;
			}
			xyToVideoAddresses(X,15,'g');
			return;
			break;
		case KEY_PRESSED_H:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'H');
				return;
			}
			xyToVideoAddresses(X,15,'h');
			return;
			break;
		case KEY_PRESSED_J:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'J');
				return;
			}
			xyToVideoAddresses(X,15,'j');
			return;
			break;
		case KEY_PRESSED_K:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'K');
				return;
			}
			xyToVideoAddresses(X,15,'k');
			return;
			break;
		case KEY_PRESSED_L:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'L');
				return;
			}
			xyToVideoAddresses(X,15,'l');
			return;
			break;
		case KEY_PRESSED_SEMICOLON:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,':');
				return;
			}
			xyToVideoAddresses(X,15,';');
			return;
			break;
		case KEY_PRESSED_SINGLE_QUOTE:
			xyToVideoAddresses(X,15,'\'');
			return;
			break;
		case KEY_PRESSED_TILDE:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'~');
				return;
			}
			xyToVideoAddresses(X,15,'`');
			return;
			break;
		case KEY_PRESSED_BACK_SLASH:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'|');
				return;
			}
			xyToVideoAddresses(X,15,'\\');
			return;
			break;
		case KEY_PRESSED_Z:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'Z');
				return;
			}
			xyToVideoAddresses(X,15,'z');
			return;
			break;
		case KEY_PRESSED_X:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'X');
				return;
			}
			xyToVideoAddresses(X,15,'x');
			return;
			break;
		case KEY_PRESSED_C:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'C');
				return;
			}
			xyToVideoAddresses(X,15,'c');
			return;
			break;
		case KEY_PRESSED_V:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'V');
				return;
			}
			xyToVideoAddresses(X,15,'v');
			return;
			break;
		case KEY_PRESSED_B:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'B');
				return;
			}
			xyToVideoAddresses(X,15,'b');
			return;
			break;
		case KEY_PRESSED_N:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'N');
				return;
			}
			xyToVideoAddresses(X,15,'n');
			return;
			break;
		case KEY_PRESSED_M:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,15,'M');
				return;
			}
			xyToVideoAddresses(X,15,'m');
			return;
			break;
		case KEY_PRESSED_COMMA:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'<');
				return;
			}
			xyToVideoAddresses(X,15,',');
			return;
			break;
		case KEY_PRESSED_PERIOD:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'>');
				return;
			}
			xyToVideoAddresses(X,15,'.');
			return;
			break;
		case KEY_PRESSED_FORWARD_SLASH:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,15,'?');
				return;
			}
			xyToVideoAddresses(X,15,'/');
			return;
			break;
		case KEY_PRESSED_CAPS_LOCK:
			if(CapOn == 1){
				CapOn = 0;
				return;
			}
			CapOn = 1;
			return;
			break;
		case KEY_PRESSED_LEFT_SHIFT:
			ShiftHolded = 1;
			return;
			break;
		case KEY_RELEASED_LEFT_SHIFT:
			ShiftHolded = 0;
			return;
			break;
		case KEY_PRESSED_RIGHT_SHIFT:
			ShiftHolded = 1;
			return;
			break;
		case KEY_RELEASED_RIGHT_SHIFT:
			ShiftHolded = 0;
			return;
			break;
	}
}

void keyboard_isr() {
	int keyPressed = inb(0x60);
	CheckAndPrintScanCodes(keyPressed);
	outb(PIC2_COMMAND,PIC_EOI);
	outb(PIC1_COMMAND,PIC_EOI);
	return;
}