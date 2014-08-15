#ifndef INIT_H
#define INIT_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#include "types.h"

void init(char *title);
void cleanup();

#endif
