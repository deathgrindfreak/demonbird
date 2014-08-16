#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

#define GROUND_HEIGHT 400

#define BIRD_WIDTH 33

#define FLAP_TIME 6 
#define FALL_SPEED 5
#define FLAP_SPEED 15
#define GRAVITY 3.5

#define BACKGROUND_R 0 
#define BACKGROUND_G 168
#define BACKGROUND_B 168

#define GROUND_R 254
#define GROUND_G 174
#define GROUND_B 106

#define MAX_PIPES 10
#define PIPE_GAP 100
#define PIPE_SPACING 100
#define HEIGHT_OFFSET 25
#define HEIGHT_RANGE 100

/* determined at runtime, since it depends on the size of the bird sprite */
int BOTTOM_LIMIT;

enum {
	ANGEL_OF_DEATH,
	DETH_SOUND,
	MAX_SOUNDS
};

typedef struct Game {
    bool paused;
	int score;
    SDL_Surface *screen;
	TTF_Font *score_font;
} Game;

typedef struct Sound {
	Mix_Chunk *effect;
} Sound;

typedef struct Bird {
	int x, y, flap; 
	int fall_timer, fall_time, timer;
	bool is_flapping;
	SDL_Rect clips[3];
    SDL_Surface *bird;
} Bird;

typedef struct Background {
	int timer, offset;
	int grass_offset;
	int y[4];
	SDL_Surface *sprite[4];
} Background;

typedef struct Pipe {
	bool active;
	int time;
	int x, height;
	SDL_Surface *pipe, *pipe_top;
} Pipe;

Game game;
Sound sound[MAX_SOUNDS];
Bird bird;
Background background;
Pipe pipes[MAX_PIPES];

#endif
