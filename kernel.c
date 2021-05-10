int _start()
{
    char* VIDMEM = 0xb8000;
    VIDMEM[0] = 'K';
    VIDMEM[2] = 'E';
    VIDMEM[4] = 'R';
    VIDMEM[6] = 'N';
    VIDMEM[8] = 'E';
    VIDMEM[10] = 'L';
    VIDMEM[12] = ' ';
    VIDMEM[14] = ' ';
    VIDMEM[16] = ' ';
    VIDMEM[18] = ' ';
    VIDMEM[20] = ' ';
    while(1);
	return 0;
}