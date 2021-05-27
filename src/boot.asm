[org 0x7c00]

mov sp, 0x7c00

push dx

mov si, BootString
call BiosPrint

pop dx

mov ecx, 1  ; LBA
;CHANGE_THIS_WHEN_NEWER_CODE_IS_ADDED
mov ax, 24   ; amount
mov ebx, 0x7e00
call ReadSectorsLBA
jc ReadSectorError

jmp 0x7e00

BootString:
	db 'Bootloader Has been Started.',0xA,0xD,0

;************************;
; Parameters:            ;
;   si => string pointer ;
;************************;
BiosPrint:
    pusha
    .loop:
        lodsb
        or al, al
        jz .done
        mov ah, 0x0E
        int 0x10
        jmp .loop
    .done:
    popa
    ret

;***********************************;
; Reads a series of sectors         ;
; Parameters:                       ;
;   dl => bootdrive                 ;
;   ax => sectors count             ;
;   ebx => address to load to       ;
;   ecx => LBA address              ;
; Returns:                          ;
;   cf => set if error              ;
;***********************************;
ReadSectorsLBA:
    push ebx
    mov word [LBA_Packet.block_cout], ax
    mov dword [LBA_Packet.transfer_buffer], ebx
    mov dword [LBA_Packet.lba_value], ecx
    mov si, LBA_Packet
    mov ah, 0x42    ; Read sectors function
    int 0x13
    pop ebx
    ret

align 4
LBA_Packet:
    .packet_size     db 0x10 ; use_transfer_64 ? 10h : 18h
    .reserved        db 0x00 ; always zero
    .block_cout      dw 0x32 ; number of sectors to read
    .transfer_buffer dd 0x00 ; address to load in ram
    .lba_value       dq 0x00 ; LBA addres value   

ReadSectorError:
	mov si, ReadError
	call BiosPrint
	jmp $

ReadError:
	db 'Read Failed',0xA,0xD,0

times 510-($-$$) db 0

dw 0xaa55