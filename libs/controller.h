//Thanks to ORION for his amazing PSX library.
//This is almost directly taken from his library, from System.h and System.c.
//A good resource from ORION -> http://onorisoft.free.fr/retro.htm?psx/tutorial/tuto.htm

#include <libetc.h>
#include <libgpu.h>
#include <libgte.h>
#include <stdlib.h>

#pragma once
#include <libetc.h>

// Extern globals (adjust to what you actually had in the header)
extern unsigned long pad_raw[2];      // raw pad data
extern unsigned long pad_pressed[2];  // edge (pressed this frame)
extern unsigned long pad_released[2]; // edge (released this frame)

// Button query helpers
void initializePad(void);
void padUpdate(void);
int  padCheck(unsigned long button);   // returns non-zero if button currently down
int  padPressed(unsigned long button); // pressed this frame
int  padReleased(unsigned long button);// released this frame

#define	padCheckRaw(_p_)	(SysPad & (_p_))//added "raw"
#define	padCheckPressed(_p_)	(SysPadT & (_p_))
#define Pad1Up			_PAD(0, PADLup)
#define Pad1Down		_PAD(0, PADLdown)
#define Pad1Left		_PAD(0, PADLleft)
#define Pad1Right		_PAD(0, PADLright)
#define Pad1Triangle	_PAD(0, PADRup)
#define Pad1Cross		_PAD(0, PADRdown)
#define Pad1Square		_PAD(0, PADRleft)
#define Pad1Circle		_PAD(0, PADRright)
#define Pad1L1			_PAD(0, PADL1)
#define Pad1L2			_PAD(0, PADL2)
#define Pad1R1			_PAD(0, PADR1)
#define Pad1R2			_PAD(0, PADR2)
#define Pad1Start		_PAD(0, PADstart)
#define Pad1Select		_PAD(0, PADselect)
#define Pad2Up			_PAD(1, PADLup)
#define Pad2Down		_PAD(1, PADLdown)
#define Pad2Left		_PAD(1, PADLleft)
#define Pad2Right		_PAD(1, PADLright)
#define Pad2Triangle	_PAD(1, PADRup)
#define Pad2Cross		_PAD(1, PADRdown)
#define Pad2Square		_PAD(1, PADRleft)
#define Pad2Circle		_PAD(1, PADRright)
#define Pad2L1			_PAD(1, PADL1)
#define Pad2L2			_PAD(1, PADL2)
#define Pad2R1			_PAD(1, PADR1)
#define Pad2R2			_PAD(1, PADR2)
#define Pad2Start		_PAD(1, PADstart)
#define Pad2Select		_PAD(1, PADselect)