#include "controller.h"

unsigned long pad_raw[2]      = {0,0};
unsigned long pad_pressed[2]  = {0,0};
unsigned long pad_released[2] = {0,0};
int SysPad;
int SysPadT;

void padUpdate(void) {
    static unsigned long prev[2] = {0,0};
    for (int i = 0; i < 2; ++i) {
        pad_raw[i] = PadRead(i);
        unsigned long change = pad_raw[i] ^ prev[i];
        pad_pressed[i]  = change & pad_raw[i];
        pad_released[i] = change & prev[i];
        prev[i] = pad_raw[i];
    }
}

void initializePad() {
	PadInit(0);
}

void padReset(void) {
	SysPad = 0;
	SysPadT = 0;
}


int padCheck(unsigned long button) {
    return (pad_raw[0] & button) != 0;
}

int padPressed(unsigned long button) {
    return (pad_pressed[0] & button) != 0;
}

int padReleased(unsigned long button) {
    return (pad_released[0] & button) != 0;
}