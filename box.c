#include <libgte.h>
#include <libgpu.h>
#include "box.h"
#include "libs/constants.h"
#include "libs/controller.h"

static Box box;
static int box_x;
static int box_y;

void box_initialize(void) {
    box_x = 100;
    box_y = 100;
    box = createBox(createColor(255, 255, 0), box_x, box_y, 200, 200);
}

void box_update(void) {
    padUpdate();
    if (padCheck(Pad1Up)){
        FntPrint("Pad1Up pressed\n\n");
        box_move(0, -2);
        static int first_time = 1;
        if (first_time) {
            printMessage("Pad1Up pressed for the first time!", 100); // Show for x centiseconds
            first_time = 0;
        }
    }
}

void box_move(int dx, int dy) {
    box_x += dx;
    box_y += dy;
    box = moveBox(box, box_x, box_y);
}

void box_draw(void) {
    drawBox(box);
}