  
nasm boot.asm -f bin -o bootloader.bin

nasm Extended_Disk.asm -f elf64 -o Extended_Disk.o

wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "Kernel.c" -o "Kernel.o"

wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-ld -o kernel.tmp -Ttext 0x7e00 Extended_Disk.o Kernel.o

wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-objcopy -O binary kernel.tmp kernel.bin

copy /b bootloader.bin+kernel.bin bootloader.flp

pause