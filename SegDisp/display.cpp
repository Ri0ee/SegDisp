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

void DisplayClass::asyncshow(char d1, char d2, char d3, bool dot1, bool dot2, bool dot3) {
	unsigned long time = millis();
	if (time - prev_time < 5) return;
	prev_time = time;

	digitalWrite(10 + display, HIGH);

	unsigned char sym[3] = { 
		(dot1 ? symbol[d1] | 1 : symbol[d1]), 
		(dot2 ? symbol[d2] | 1 : symbol[d2]), 
		(dot3 ? symbol[d3] | 1 : symbol[d3]) };

	for (int seg = 0; seg < 8; seg++)
		digitalWrite(2 + seg, (sym[display] << seg & 128) / 128);

	digitalWrite(10 + display, LOW);

	display = (display + 1) % 3;
}

void DisplayClass::show(char d1, char d2, char d3, bool dot1, bool dot2, bool dot3) {
	unsigned char sym[3] = {
		(dot1 ? symbol[d1] | 1 : symbol[d1]),
		(dot2 ? symbol[d2] | 1 : symbol[d2]),
		(dot3 ? symbol[d3] | 1 : symbol[d3]) };

	for (int disp = 0; disp < 3; disp++) {
		for (int seg = 0; seg < 8; seg++)
			digitalWrite(2 + seg, (sym[disp] << seg & 128) / 128);

		digitalWrite(10 + disp, LOW);
		delay(5);
		digitalWrite(10 + disp, HIGH);
	}
}


DisplayClass Display;