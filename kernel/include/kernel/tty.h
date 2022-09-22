#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void terminalInit(void);
void terminalPutChar(char c);
void terminalWrite(const char* data, size_t size);
void terminalWriteString(const char* data);

#endif
