
[bits 64]


NewCode:
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

	jmp $