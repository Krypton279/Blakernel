nasm -f bin boot.asm -o boot.bin
nasm -f bin Sector2+.asm -o sector2.bin
copy /b boot.bin+sector2.bin boot.flp
pause