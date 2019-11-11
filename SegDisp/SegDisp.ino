#include "display.h"

void setup() {
	Display.init();
}


void loop() {
	Display.show(1, A, B, true, false, false);
}
