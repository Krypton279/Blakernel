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

StartProtectedMode:
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

times (512*2)-($-$$) db 0