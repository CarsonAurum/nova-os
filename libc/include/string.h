#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// MARK: - MEMORY
void* memchr(const void*, int, size_t);
int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memset(void*, int, size_t);
void* memmove(void*, const void*, size_t);
// MARK: - STRINGS
size_t strlen(const char*);
int strcmp(const char*, const char*);
int strncmp(const char*, const char*, size_t);
char* strchr(const char*, int);
char* strrchr(const char*, int);
size_t strspan(const char*, const char*);
size_t strcspn(const char*, const char*);
char* strpbrk(const char*, const char*);
char* strstr(const char*, const char*);
char* strtok(char*, const char*);
#ifdef __cplusplus
}
#endif

#endif
