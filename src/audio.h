#ifndef AUDIO_H
#define AUDIO_H

#include "SDL/SDL_mixer.h"

#include "types.h"

void load_sound(int index, char *name);
void play_sound(int index);
void load_all_sounds();
void freeSounds();

#endif
