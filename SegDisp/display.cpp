#include "display.h"

void DisplayClass::init()
{
	for (int i = 2; i < 13; i++) {
		pinMode(i, OUTPUT);
		digitalWrite(i, LOW);
	}

	symbol[0] = 252;
	symbol[1] = 96;
	symbol[2] = 218;
	symbol[3] = 242;
	symbol[4] = 102;
	symbol[5] = 182;
	symbol[6] = 190;
	symbol[7] = 224;
	symbol[8] = 254;
	symbol[9] = 246;
	symbol[A] = 238;
	symbol[B] = 62;
	symbol[C] = 156;
	symbol[D] = 122;
	symbol[E] = 158;
	symbol[F] = 142;
}

void DisplayClass::show(char d1, char d2, char d3, bool dot1, bool dot2, bool dot3) {
	unsigned long time = millis();
	if (time - prev_time < 5) return;
	prev_time = time;

	digitalWrite(10 + display, HIGH);

	unsigned char sym[3] = { symbol[d1], symbol[d2], symbol[d3] };
	if (dot1) sym[0] |= 1;
	if (dot2) sym[1] |= 1;
	if (dot3) sym[2] |= 1;

	for (int seg = 0; seg < 8; seg++)
		digitalWrite(2 + seg, (sym[display] << seg & 128) / 128);

	digitalWrite(10 + display, LOW);

	display = (display + 1) % 3;
}


DisplayClass Display;