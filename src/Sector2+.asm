[bits 16]

global entry

entry:
	mov bx, Sector2
	call PrintString
	call StartProtectedMode

	mov ax,10h
	mov ds,ax
	mov es,ax
	mov fs,ax
	mov gs,ax
	mov ss,ax
	jmp codeseg:EnterProtectedMode

Sector2:
	db 'Entering Sector 2+.',0xA,0xD,0

PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
	cmp [bx], byte 0
	je .Exit
		mov al, [bx]
		int 0x10
		inc bx
		jmp .Loop
	.Exit:

	pop ax
	pop bx
	ret

global MemRegCounts

MemRegCounts:
	db 0

DetectMemoryRegions:
	mov ax, 0
	mov es, ax
	mov di, 0x500
	mov edx, 0x534d4150
	mov ebx, 0

	.loop:
		mov eax, 0xE820
		mov ecx, 24
		int 0x15
		cmp ebx, 0
		je .fin
		add di, 24
		inc byte [MemRegCounts]
		jmp .loop

	.fin:
		ret

StartProtectedMode:
	call DetectMemoryRegions
	cli
	call EnableA20
	lgdt [gdt_descriptor]
	mov eax,cr0
	or eax,1
	mov cr0,eax
	ret

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

;GDT-Variables

gdt_nulldesc:
	dd 0
	dd 0	
gdt_codedesc:
	dw 0xFFFF			; Limit
	dw 0x0000			; Base (low)
	db 0x00				; Base (medium)
	db 10011010b		; Flags
	db 11001111b		; Flags + Upper Limit
	db 0x00				; Base (high)
gdt_datadesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00

gdt_end:

gdt_descriptor:
	gdt_size: 
		dw gdt_end - gdt_nulldesc - 1
		dq gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
dataseg equ gdt_datadesc - gdt_nulldesc

;32-bit

[bits 32]

EditGDT:
	mov [gdt_codedesc + 6], byte 10101111b

	mov [gdt_datadesc + 6], byte 10101111b
	ret

DetectCPUID:

	pushfd 
	pop eax

	mov ecx, eax

	xor eax, 1 << 21

	push eax
	popfd

	pushfd 
	pop eax

	push ecx 
	popfd

	xor eax,ecx
	jz NoCPUID
	ret

DetectLongMode:
	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz NoLongMode
	ret

NoLongMode:
	hlt ; No Long Mode Support

NoCPUID:

	hlt ; No CPUID support.

PageTableEntry equ 0x1000

SetUpIdentityPaging:

	mov edi, PageTableEntry
	mov cr3, edi

	mov dword [edi], 0x2003
	add edi, 0x1000
	mov dword [edi], 0x3003
	add edi, 0x1000
	mov dword [edi], 0x4003
	add edi, 0x1000

	mov ebx, 0x00000003
	mov ecx, 512

	.SetEntry:
		mov dword [edi], ebx
		add ebx, 0x1000
		add edi, 8
		loop .SetEntry

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax

	ret

EnterProtectedMode:
	mov [0xb8000], byte 'P'
	mov [0xb8002], byte 'R'
	mov [0xb8004], byte 'O'
	mov [0xb8006], byte 'T'
	mov [0xb8008], byte '-'
	mov [0xb800a], byte 'M'
	mov [0xb800c], byte 'O'
	mov [0xb800e], byte 'D'
	mov [0xb8010], byte 'E'
	mov [0xb8012], byte ' '
	mov [0xb8014], byte ' '
	mov [0xb8016], byte ' '
	mov [0xb8018], byte ' '
	mov [0xb802a], byte ' '
	mov [0xb802c], byte '.'
	mov eax, 1
	jmp StartLongMode

StartLongMode:
	call DetectCPUID
	call DetectLongMode
	call SetUpIdentityPaging
	call EditGDT
	jmp codeseg:Enter64

[bits 64]
[extern _start]

%macro PUSHALL 0
	push rax
	push rcx
	push rdx
	push r8
	push r9
	push r10
	push r11
%endmacro

%macro POPALL 0
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rcx
	pop rax
%endmacro

Enter64:

	call ActivateSSE
	mov [0xb8000], byte 'L'
	mov [0xb8002], byte 'O'
	mov [0xb8004], byte 'N'
	mov [0xb8006], byte 'G'
	mov [0xb8008], byte '-'
	mov [0xb800a], byte 'M'
	mov [0xb800c], byte 'O'
	mov [0xb800e], byte 'D'
	mov [0xb8010], byte 'E'
	mov [0xb8012], byte ' '
	mov [0xb8014], byte ' '
	mov [0xb8016], byte ' '
	mov [0xb8018], byte ' '
	mov [0xb802a], byte ' '
	mov [0xb802c], byte '.'
	mov rax, 1
	jmp _start
	jmp $

ActivateSSE:
	mov rax, cr0
	and ax, 0b11111101
	or ax, 0b00000001
	mov cr0, rax

	mov rax, cr4
	or ax, 0b1100000000
	mov cr4, rax

	ret

;EXCEPTION HANDLERS

[extern keyboard_isr]

global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global keyboard_handler

isr1: 
	mov [0xb8000], byte 'Z'
	mov [0xb8002], byte 'E'
	mov [0xb8004], byte 'R'
	mov [0xb8006], byte 'O'
	mov [0xb8008], byte '-'
	mov [0xb800a], byte 'E'
	mov [0xb800c], byte 'R'
	mov [0xb800e], byte 'R'
	mov [0xb8010], byte 'O'
	mov [0xb8012], byte 'R'
	mov [0xb8014], byte '-'
	mov [0xb8016], byte '0'
	mov [0xb8018], byte '!'
	mov [0xb802a], byte '!'
	mov [0xb802c], byte '.'
	jmp $
	iretq
isr2:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte ' '
	jmp $ 
	iretq
isr3:
	mov [0xb8000], byte '2'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr4:
	mov [0xb8000], byte '3'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr5:
	mov [0xb8000], byte '4'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr6:
	mov [0xb8000], byte '5'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr7:
	mov [0xb8000], byte '6'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr8:
	mov [0xb8000], byte '7'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr9:
	mov [0xb8000], byte '8'
	mov [0xb8002], byte ' '
	jmp $
	iretq
isr10:
	mov [0xb8000], byte '9'
	mov [0xb8002], byte ' '
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr11:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '0'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr12:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '1'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr13:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '2'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr14:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '3'
	mov [0xb8004], byte ' '
	pop rax
	jmp $
	iretq
isr15:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '4'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr16:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '5'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr17:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '6'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr18:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '7'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr19:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '8'
	mov [0xb8004], byte ' '
	jmp $
	iretq
isr20:
	mov [0xb8000], byte '1'
	mov [0xb8002], byte '9'
	mov [0xb8004], byte ' '
	jmp $
	iretq
keyboard_handler:
	PUSHALL
	call keyboard_isr
	POPALL
	iretq

times (1024*2)-($-$$) db 0