#include <stdio.h>

#include <kernel/tty.h>

void kernelMain(void) {
    terminalInit();
	printf("Hello, kernel World!\n");
}
