#include <libetc.h>
#include <libgpu.h>
#include <libgte.h>
#include <stdlib.h>
#include <libgs.h>
#include "libs/controller.h"
#include "libs/constants.h"
#include "libs/print.h"
#include "box.h"

Line line;

int main(void) {
    initialize();

    while (1) {
        update();
        draw();
        display();
    }

    return 0;
}

void update() {
    updatePrint(); // Display persistent messages
    box_update();
}

void initialize(){
    initializeScreen();
    initializePad();
    initializeDebugFont();
    initPrint(); // Initialize print system
    box_initialize();
    setBackgroundColor(createColor(255, 0, 255));
    line = createLine(createColor(0, 255, 0), 50, 50, 100, 100);
    printMessage("init", 100);
}

void draw() {
    drawLine(line);
    box_draw();
}