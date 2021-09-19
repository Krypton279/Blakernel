# Blakernel
It is a Kernel made by a stranger on the internet to practise assembly and C and get a deep deep into Operating Systems learning about them. This kernel is not based on Linux or Windows or Mac , Its just a Kernel made by the ideas of a high school teenager who has its own takes on mechanisms in Kernel , You are free to make suggestions with issues as you like , you can also ask me questions about source code on Discord (Krypton#5577) , This is my First Project which became so ahead and was able to develop quite a bit so , you can expect some/many mistakes from me. I am starting to transition this from a fun project to a serious one with good details included so you can tell me if there is some mistake.

# Compilation
There are 2 ways you can compile this kernel : Windows and Linux

# Linux
NOTE : in Linux , you have to get gcc(x86_64_elfgcc and x86_64_elf_ld) compiled , and i am on Linux when i compiled that binaries , so i know what a big problem that is , so i am gonna upload the binaries in /bin which must have the binaries and you get them while cloning so you dont have to go throught what i went through :)
The commands will be in /src/compilelinux but still i am writing them down here :
nasm -f bin boot.asm -o boot.bin
nasm -f elf64 Sector2+.asm -o sector2.o
/usr/local/x86_64elfgcc/bin/x86_64-elf-gcc -c -ffreestanding -m64 kernel.c -o kernel.o
/usr/local/x86_64elfgcc/bin/x86_64-elf-ld -nostdlib -T ld_script sector2.o kernel.o -o kernel.bin
cat boot.bin kernel.bin > boot.flp

# Windows
NOTE : in Windows , its mandotory to get wsl setup and running to run custom gcc binaries , you have to put the binaries in specific locations , so the binaries for linux and wsl are the same , you just need to put the binaries in the "CORRECT" path for it to work , as always , /src/compilewindows.bat will be there but i am still posting the commands here:
nasm -f bin boot.asm -o boot.bin
nasm -f elf64 Sector2+.asm -o sector2.o
wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-gcc -c -ffreestanding -m64 kernel.c -o kernel.o
wsl /usr/local/x86_64elfgcc/bin/x86_64-elf-ld -nostdlib -T ld_script sector2.o kernel.o -o kernel.bin
copy /b boot.bin+kernel.bin boot.flp
pause

# Running the Kernel with Qemu
NOTE : You need to run either src/launchqemulinux or src/launchqemuwindowsbat to run QEMU with the kernel , well , truth to be said , both commands are the same but you need to make sure that QEMU is in your path , either in Windows or Linux , you can always google how include paths in your OS , meanwhile i am also writing the command for QEMU here aswell:
qemu-system-x86_64 -m 512M boot.flp -no-reboot -no-shutdown

# ScreenShots of BlaKernel
NOTE : They are coming soon , :)

# Any New Names !!
I am also Searching for new names for this kernel , you can send your suggestions in my DMs

# Things to keep in Mind when Editing the source code or tinkering with it

NOTE : REMEMBER TO INCREASE THE VALUE IN LINE 13 OF BOOT.ASM. 

NOTE : REMEMBER TO CHECK THE TOP-LEFT CORNER OF THE EMULATOR FOR EXCEPTION NUMBERS AND CHECK THE EXCEPTION FROM OSDEV WIKI.

NOTE : "Always remove the debug code after you use it"

NOTE : IF YOU ARE GETTING A PAGE FAULT TRY THE FIRST NOTE SOLUTION

# Discord Server
I am thinking to make it but still , let me know your views
