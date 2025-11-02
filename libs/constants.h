/*
 * constants.h
 *
 *  Created on: Oct 8, 2016
 *      Author: Wituz
 */

#pragma once

#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libgs.h>
#include <libetc.h>
#include "sys/types.h"
#define OT_LENGTH 8
#define PACKETMAX 18
#define __ramsize   0x00200000
#define __stacksize 0x00004000

#define TYPE_LINE 0
#define TYPE_BOX  1
#define SCREEN_MODE_PAL  0
#define SCREEN_MODE_NTSC 1
#define DEBUG 1

typedef struct {
    int r, g, b;
} Color;

typedef struct {
    LINE_F2 line;
    int type;
} Line;

typedef struct {
    Line edge[4];
    int type;
} Box;

// Extern declarations (single storage in constants.c)
extern int   SCREEN_WIDTH;
extern int   SCREEN_HEIGHT;
extern GsOT  orderingTable[2];
extern short currentBuffer;
extern Color systemBackgroundColor;

// If desired, small helpers can be static inline (avoid multiple defs while staying in header).
static inline Color createColor(int r, int g, int b) {
    Color c = { r, g, b };
    return c;
}

Line createLine(Color color, int x1, int y1, int x2, int y2);
Box  createBox(Color color, int x1, int y1, int x2, int y2);
Line moveLine(Line ln, int x1, int y1, int x2, int y2);
Box  moveBox(Box box, int x1, int y1);
void drawLine(Line ln);
void drawBox(Box box);

void setScreenMode(int mode);
void setBackgroundColor(Color color);
void initializeScreen(void);
void initializeDebugFont(void);
void initializeOrderingTable(GsOT* ot);
void display(void);