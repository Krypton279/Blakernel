nasm -f bin boot.asm -o boot.bin
nasm -f elf64 Sector2+.asm -o sector2.o
bash -c "gcc -c -ffreestanding -m64 kernel.c -o kernel.o"
bash -c "ld -nostdlib -T ld_script sector2.o kernel.o -o kernel.bin"
copy /b boot.bin+kernel.bin boot.flp
qemu-system-x86_64 -m 512M boot.flp -no-reboot -no-shutdown