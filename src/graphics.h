#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "bird.h"
#include "types.h"

SDL_Surface *load_image(char *name);
void draw_image(SDL_Surface *image, int x, int y);
void apply_surface(SDL_Surface *image, int x, int y, SDL_Rect *clip);
void draw_bird();
void load_bird();
void draw_background();
void load_background();
void draw_pipe();

#endif
