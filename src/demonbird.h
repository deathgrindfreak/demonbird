#ifndef DEMONBIRD_H
#define DEMONBIRD_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "audio.h"
#include "draw.h"
#include "bird.h"
#include "fonts.h"
#include "init.h"
#include "input.h"
#include "pipe.h"
#include "types.h"

void init_game();
void new_game();

#endif
