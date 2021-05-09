nasm -f bin boot.asm -o boot.bin
nasm -f elf64 Sector2+.asm -o sector2.o
wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-gcc -c -ffreestanding -m64 kernel.c -o kernel.o
wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-ld -nostdlib -T ld_script sector2.o kernel.o -o kernel.bin
copy /b boot.bin+kernel.bin boot.flp
pause