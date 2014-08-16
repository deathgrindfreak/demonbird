#ifndef DRAW_H
#define DRAW_H

#include "SDL/SDL.h"

#include "bird.h"
#include "collision.h"
#include "fonts.h"
#include "types.h"
#include "graphics.h"
#include "pipe.h"

void draw();
void delay(unsigned int frame_limit);

#endif
