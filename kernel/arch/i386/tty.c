#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

#include "vga.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminalRow;
static size_t terminalCol;
static uint8_t terminalColor;
static uint16_t* terminalBuffer;

void terminalInit(void) {
	terminalRow = 0;
	terminalCol = 0;
	terminalColor = VGAEntryColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminalBuffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminalBuffer[index] = VGAEntry(' ', terminalColor);
		}
	}
}

void terminalSetColor(uint8_t color) {
	terminalColor = color;
}

void terminalPutEntryAt(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminalBuffer[index] = VGAEntry(c, color);
}

void terminalPutChar(char c) {
	unsigned char uc = c;
	terminalPutEntryAt(uc, terminalColor, terminalCol, terminalRow);
	if (++terminalCol == VGA_WIDTH) {
		terminalCol = 0;
		if (++terminalRow == VGA_HEIGHT)
			terminalRow = 0;
	}
}

void terminalWrite(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminalPutChar(data[i]);
}

void terminalWriteString(const char* data) {
	terminalWrite(data, strlen(data));
}
