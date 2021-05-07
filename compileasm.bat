nasm boot.asm -f bin -o bootloader.bin

nasm Extended_Disk.asm -f bin -o Extended_Disk.bin

copy /b bootloader.bin+Extended_Disk.bin bootloader.flp

pause