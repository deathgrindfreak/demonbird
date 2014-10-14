#ifndef COLLISION_H
#define COLLISION_H

#include <stdbool.h>

#include "types.h"

typedef struct Rect {
    int x, y; /* top left corner of pipe */
    int width, height;
} Rect;

typedef struct Ellipse {
    int major, minor;
} Ellipse;

typedef struct PipeShape {
    Rect top_pipe, top_pipe_top;
    Rect bottom_pipe, bottom_pipe_top;
} PipeShape;

int is_collision();
void init_pipeshape(PipeShape *pipe);

#endif
