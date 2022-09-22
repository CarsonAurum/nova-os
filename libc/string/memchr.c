#include <string.h>
#include <limits.h>
#include <stddef.h>

void* memchr(void const* s, int cIn, size_t n)
{
    const unsigned char* charPtr;
    const unsigned long int* ptr;
    unsigned long int repeatedOne;
    unsigned long int repeatedC;
    unsigned char c;

    c = (unsigned char) cIn;
    for(charPtr = (const unsigned char*)s;
        n > 0 && (size_t)charPtr % sizeof(unsigned long int) != 0;
        --n, ++charPtr)
        if(*charPtr == c)
            return (void*)charPtr;

    repeatedOne = 0x01010101;
    repeatedC = c | (c << 8);
    repeatedC |= repeatedC << 16;
    if (0xfffffffU < (unsigned long int) - 1)
    {
        repeatedOne |= repeatedOne << 31 << 1;
        repeatedC |= repeatedC << 31 << 1;
        if (8 < sizeof(unsigned long int))
        {
            size_t i;
            for(i = 64; i < sizeof(unsigned long int) * 8; i *= 2)
            {
                repeatedOne |= repeatedOne << i;
                repeatedC |= repeatedC << i;
            }
        }
    }

    while (n >= sizeof(unsigned long int))
    {
        unsigned long int l1 = *ptr ^ repeatedC;
        if ((((l1 - repeatedOne) & ~l1) & (repeatedOne << 7)) != 0)
            break;
        ptr++;
        n-= sizeof(unsigned long int);
    }
    charPtr = (const unsigned char*)ptr;
    for(; n > 0; --n, ++charPtr)
        if (*charPtr == c)
            return (void*)charPtr;
    return NULL;
}