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
				xyToVideoAddresses(X,Y,'!');
				return;
			}
			xyToVideoAddresses(X,Y,'1');
			return;
			break;
		case KEY_PRESSED_2:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'@');
				return;
			}
			xyToVideoAddresses(X,Y,'2');
			return;
			break;
		case KEY_PRESSED_3:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'#');
				return;
			}
			xyToVideoAddresses(X,Y,'3');
			return;
			break;
		case KEY_PRESSED_4:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'$');
				return;
			}
			xyToVideoAddresses(X,Y,'4');
			return;
			break;
		case KEY_PRESSED_5:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'%');
				return;
			}
			xyToVideoAddresses(X,Y,'5');
			return;
			break;
		case KEY_PRESSED_6:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'^');
				return;
			}
			xyToVideoAddresses(X,Y,'6');
			return;
			break;
		case KEY_PRESSED_7:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'&');
				return;
			}
			xyToVideoAddresses(X,Y,'7');
			return;
			break;
		case KEY_PRESSED_8:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'*');
				return;
			}
			xyToVideoAddresses(X,Y,'8');
			return;
			break;
		case KEY_PRESSED_9:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'(');
				return;
			}
			xyToVideoAddresses(X,Y,'9');
			return;
			break;
		case KEY_PRESSED_0:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,')');
				return;
			}
			xyToVideoAddresses(X,Y,'X');
			return;
			break;
		case KEY_PRESSED_MINUS:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'_');
				return;
			}
			xyToVideoAddresses(X,Y,'-');
			return;
			break;
		case KEY_PRESSED_EQUALS:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'+');
				return;
			}
			xyToVideoAddresses(X,Y,'=');
			return;
			break;
		case KEY_PRESSED_BACKSPACE:
			xyToVideoAddresses(X-1,Y,' ');
			update_cursor(X-1,Y);
			X = X - 1;
			return;
			break;
		case KEY_PRESSED_Q:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'Q');
				return;
			}
			xyToVideoAddresses(X,Y,'q');
			return;
			break;
		case KEY_PRESSED_W:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'W');
				return;
			}
			xyToVideoAddresses(X,Y,'w');
			return;
			break;
		case KEY_PRESSED_E:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'E');
				return;
			}
			xyToVideoAddresses(X,Y,'e');
			return;
			break;
		case KEY_PRESSED_R:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'R');
				return;
			}
			xyToVideoAddresses(X,Y,'r');
			return;
			break;
		case KEY_PRESSED_T:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'T');
				return;
			}
			xyToVideoAddresses(X,Y,'t');
			return;
			break;
		case KEY_PRESSED_Y:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'Y');
				return;
			}
			xyToVideoAddresses(X,Y,'y');
			return;
			break;
		case KEY_PRESSED_U:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'U');
				return;
			}
			xyToVideoAddresses(X,Y,'u');
			return;
			break;
		case KEY_PRESSED_I:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'I');
				return;
			}
			xyToVideoAddresses(X,Y,'i');
			return;
			break;
		case KEY_PRESSED_O:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'O');
				return;
			}
			xyToVideoAddresses(X,Y,'o');
			return;
			break;
		case KEY_PRESSED_P:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'P');
				return;
			}
			xyToVideoAddresses(X,Y,'p');
			return;
			break;
		case KEY_PRESSED_OPEN_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'{');
				return;
			}
			xyToVideoAddresses(X,Y,'[');
			return;
			break;
		case KEY_PRESSED_CLOSE_SQUARE_BRACKET:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'}');
				return;
			}
			xyToVideoAddresses(X,Y,']');
			return;
			break;
		case KEY_PRESSED_A:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'A');
				return;
			}
			xyToVideoAddresses(X,Y,'a');
			return;
			break;
		case KEY_PRESSED_S:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'S');
				return;
			}
			xyToVideoAddresses(X,Y,'s');
			return;
			break;
		case KEY_PRESSED_D:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'D');
				return;
			}
			xyToVideoAddresses(X,Y,'d');
			return;
			break;
		case KEY_PRESSED_F:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'F');
				return;
			}
			xyToVideoAddresses(X,Y,'f');
			return;
			break;
		case KEY_PRESSED_G:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'G');
				return;
			}
			xyToVideoAddresses(X,Y,'g');
			return;
			break;
		case KEY_PRESSED_H:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'H');
				return;
			}
			xyToVideoAddresses(X,Y,'h');
			return;
			break;
		case KEY_PRESSED_J:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'J');
				return;
			}
			xyToVideoAddresses(X,Y,'j');
			return;
			break;
		case KEY_PRESSED_K:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'K');
				return;
			}
			xyToVideoAddresses(X,Y,'k');
			return;
			break;
		case KEY_PRESSED_L:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'L');
				return;
			}
			xyToVideoAddresses(X,Y,'l');
			return;
			break;
		case KEY_PRESSED_SEMICOLON:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,':');
				return;
			}
			xyToVideoAddresses(X,Y,';');
			return;
			break;
		case KEY_PRESSED_SINGLE_QUOTE:
			xyToVideoAddresses(X,Y,'\'');
			return;
			break;
		case KEY_PRESSED_TILDE:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'~');
				return;
			}
			xyToVideoAddresses(X,Y,'`');
			return;
			break;
		case KEY_PRESSED_BACK_SLASH:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'|');
				return;
			}
			xyToVideoAddresses(X,Y,'\\');
			return;
			break;
		case KEY_PRESSED_Z:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'Z');
				return;
			}
			xyToVideoAddresses(X,Y,'z');
			return;
			break;
		case KEY_PRESSED_X:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'X');
				return;
			}
			xyToVideoAddresses(X,Y,'x');
			return;
			break;
		case KEY_PRESSED_C:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'C');
				return;
			}
			xyToVideoAddresses(X,Y,'c');
			return;
			break;
		case KEY_PRESSED_V:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'V');
				return;
			}
			xyToVideoAddresses(X,Y,'v');
			return;
			break;
		case KEY_PRESSED_B:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'B');
				return;
			}
			xyToVideoAddresses(X,Y,'b');
			return;
			break;
		case KEY_PRESSED_N:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'N');
				return;
			}
			xyToVideoAddresses(X,Y,'n');
			return;
			break;
		case KEY_PRESSED_M:
			if(CapOn == 1 | ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'M');
				return;
			}
			xyToVideoAddresses(X,Y,'m');
			return;
			break;
		case KEY_PRESSED_COMMA:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'<');
				return;
			}
			xyToVideoAddresses(X,Y,',');
			return;
			break;
		case KEY_PRESSED_PERIOD:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'>');
				return;
			}
			xyToVideoAddresses(X,Y,'.');
			return;
			break;
		case KEY_PRESSED_FORWARD_SLASH:
			if(ShiftHolded == 1){
				xyToVideoAddresses(X,Y,'?');
				return;
			}
			xyToVideoAddresses(X,Y,'/');
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
		case KEY_RELEASED_ENTER:
			update_cursor(0,Y+1);
			Y = Y + 1;
			X = 0;
		case KEY_PRESSED_SPACE:
			xyToVideoAddresses(X,Y,' ');
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