#ifndef PIPE_H
#define PIPE_H

#include <stdlib.h>

#include "graphics.h"
#include "types.h"

void init_pipes();
int get_free_pipe();
void move_pipes();

#endif
