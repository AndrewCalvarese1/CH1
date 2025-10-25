#include <libetc.h>
#include <libgpu.h>
#include <libgte.h>
#include <stdlib.h>
#include <libgs.h>
#include "libs/controller.h"
#include "libs/constants.h"
#include "libs/print.h"

Line line;
Box box;
int box_x, box_y;

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
    FntPrint("update\n\n");
    padUpdate();
    if (padCheck(Pad1Up)){
        FntPrint("Pad1Up pressed\n\n");
        box_y -= 2;
        box = moveBox(box, box_x, box_y);
        static int first_time = 1;
        if (first_time) {
            printMessage("Pad1Up pressed for the first time!", 300); // Show for 5 seconds
            first_time = 0;
        }
    }
}

void initialize(){
    initializeScreen();
    initializePad();
    initializeDebugFont();
    initPrint(); // Initialize print system
    box_x = 100;
    box_y = 100;
    box = createBox(createColor(255, 255, 0), box_x, box_y, 200, 200);
    setBackgroundColor(createColor(255, 0, 255));
    line = createLine(createColor(0, 255, 0), 50, 50, 100, 100);
}

void draw() {
    drawLine(line);
    drawBox(box);
}