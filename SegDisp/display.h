// display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum letters {
	A = 10, B = 11, C = 12, D = 13, E = 14, F = 15
};

class DisplayClass {
public:
	void init();
	void show(char d1, char d2, char d3, bool dot1, bool dot2, bool dot3);

private:
	unsigned char symbol[16];
	unsigned long prev_time = 0;

	int display = 0;
};

extern DisplayClass Display;

#endif

