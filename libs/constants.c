// filepath: c:\Users\acalv\Desktop\ps1_game\CH1\libs\constants.c
#include "constants.h"

int   SCREEN_WIDTH  = 0;
int   SCREEN_HEIGHT = 0;
GsOT  orderingTable[2];
short currentBuffer = 0;
Color systemBackgroundColor = {0,0,0};

Line createLine(Color color, int x1, int y1, int x2, int y2) {
    Line ln;
    ln.type = TYPE_LINE;
    SetLineF2(&ln.line);
    setRGB0(&ln.line, color.r, color.g, color.b);
    setXY2(&ln.line, x1, y1, x2, y2);
    return ln;
}

Box createBox(Color color, int x1, int y1, int x2, int y2) {
    Box b;
    b.type   = TYPE_BOX;
    b.edge[0] = createLine(color, x1, y1, x2, y1); // top
    b.edge[1] = createLine(color, x1, y2, x2, y2); // bottom
    b.edge[2] = createLine(color, x1, y1, x1, y2); // left
    b.edge[3] = createLine(color, x2, y1, x2, y2); // right
    return b;
}

Line moveLine(Line ln, int x1, int y1, int x2, int y2) {
    ln.line.x0 = x1; ln.line.y0 = y1;
    ln.line.x1 = x2; ln.line.y1 = y2;
    return ln;
}

Box moveBox(Box box, int x1, int y1) {
    int width  = box.edge[0].line.x1 - box.edge[0].line.x0;
    int height = box.edge[2].line.y1 - box.edge[2].line.y0; // corrected
    int x2 = x1 + width;
    int y2 = y1 + height;
    box.edge[0] = moveLine(box.edge[0], x1, y1, x2, y1);
    box.edge[1] = moveLine(box.edge[1], x1, y2, x2, y2);
    box.edge[2] = moveLine(box.edge[2], x1, y1, x1, y2);
    box.edge[3] = moveLine(box.edge[3], x2, y1, x2, y2);
    return box;
}

void drawLine(Line ln) {
    DrawPrim(&ln.line);
}

void drawBox(Box box) {
    for (int i = 0; i < 4; ++i)
        DrawPrim(&box.edge[i].line);
}

void setScreenMode(int mode) {
    if (mode == SCREEN_MODE_PAL) {
        SCREEN_WIDTH = 320;
        SCREEN_HEIGHT = 256;
        SetVideoMode(1);
    } else {
        SCREEN_WIDTH = 320;
        SCREEN_HEIGHT = 240;
        SetVideoMode(0);
    }
    GsInitGraph(SCREEN_WIDTH, SCREEN_HEIGHT, GsINTER|GsOFSGPU, 1, 0);
    GsDefDispBuff(0, 0, 0, SCREEN_HEIGHT);
}

void setBackgroundColor(Color color) {
    systemBackgroundColor = color;
}

void initializeScreen(void) {
    if (*(char*)0xbfc7ff52 == 'E')
        setScreenMode(SCREEN_MODE_PAL);
    else
        setScreenMode(SCREEN_MODE_NTSC);
    systemBackgroundColor = createColor(0,0,255);
}

void initializeDebugFont(void) {
    FntLoad(960, 256);
    SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512));
}

void initializeOrderingTable(GsOT* ot) {
    GsClearOt(0, 0, &ot[GsGetActiveBuff()]);
}

void display(void) {
    currentBuffer = GsGetActiveBuff();
    FntFlush(-1);
    GsClearOt(0, 0, &orderingTable[currentBuffer]);
    DrawSync(0);
    VSync(0);
    GsSwapDispBuff();
    GsSortClear(systemBackgroundColor.r,
                systemBackgroundColor.g,
                systemBackgroundColor.b,
                &orderingTable[currentBuffer]);
    GsDrawOt(&orderingTable[currentBuffer]);
}