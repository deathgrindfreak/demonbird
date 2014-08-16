#include "graphics.h"


SDL_Surface *load_image(char *name) {

	/* Load the image using SDL Image */
	
	SDL_Surface *temp = IMG_Load(name);
	SDL_Surface *image;
	
	if (temp == NULL) {

		printf("Failed to load image %s\n", name);
		
		return NULL;
	}
	
	/* Make the background transparent */
	
	SDL_SetColorKey(temp, (SDL_SRCCOLORKEY|SDL_RLEACCEL), SDL_MapRGB(temp->format, 0, 0, 0));
	
	/* Convert the image to the screen's native format */
	
	image = SDL_DisplayFormat(temp);
	
	SDL_FreeSurface(temp);
	
	if (image == NULL) {

		printf("Failed to convert image %s to native format\n", name);
		
		return NULL;
	}
	
	/* Return the processed image */
	
	return image;
}


/* draw_image - draws an image to the buffer */
void draw_image(SDL_Surface *image, int x, int y) {

	SDL_Rect dest;
	
	/* Set the blitting rectangle to the size of the src image */
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;
	
	/* Blit the entire image onto the screen at coordinates x and y */
	
	SDL_BlitSurface(image, NULL, game.screen, &dest);
}


/* apply_surface - applies a frame to an image */
void apply_surface(SDL_Surface *image, int x, int y, SDL_Rect *clip) {

	SDL_Rect dest;
	
	/* Set the blitting rectangle to the size of the src image */
	dest.x = x;
	dest.y = y;
	dest.w = image->w;
	dest.h = image->h;
	
	/* Blit the entire image onto the screen at coordinates x and y */
	SDL_BlitSurface(image, clip, game.screen, &dest);
}


/* load_bird - load the bird sprite */
void load_bird() {
	
	bird.bird = load_image("img/bird.png");
	
	/* Instantiate the clip regions */
	bird.clips[0].x = 0;
	bird.clips[0].y = 0;
	bird.clips[0].w = BIRD_WIDTH - 1;
	bird.clips[0].h = bird.bird->h;
	
	bird.clips[1].x = BIRD_WIDTH - 1;
	bird.clips[1].y = 0;
	bird.clips[1].w = BIRD_WIDTH - 1;
	bird.clips[1].h = bird.bird->h;

	bird.clips[2].x = 2 * BIRD_WIDTH - 2;
	bird.clips[2].y = 0;
	bird.clips[2].w = BIRD_WIDTH - 1;
	bird.clips[2].h = bird.bird->h;
}


/* draw_bird - draws the bird on the screen */
void draw_bird() {
	apply_surface(bird.bird, bird.x, bird.y, &bird.clips[bird.flap]);
}


/* load_background - loads all of the background sprites */
void load_background() {

	/* building sprite */
	background.sprite[1] = load_image("img/flats.png");
	background.y[1] = (GROUND_HEIGHT - 10) - background.sprite[1]->h;
	
	/* cloud sprite */
	background.sprite[0] = load_image("img/cloud.png");
	background.y[0] = (GROUND_HEIGHT - 10) - (background.sprite[1]->h + 
	                                   background.sprite[0]->h);
	
	/* bush sprite */
	background.sprite[2] = load_image("img/bush.png");
	background.y[2] = (GROUND_HEIGHT - 10) - background.sprite[2]->h;

	/* grass sprite */
	background.sprite[3] = load_image("img/grass.png");
	background.y[3] = GROUND_HEIGHT;
}


/* draw_background - draws the background onto the screen */
void draw_background() {
	
	SDL_Rect ground, ground_border, grass_border, asphalt;
	int i, x = 0;
	
	/* increment the timer */
    if (!game.over) {
        background.timer++;
        background.grass_offset++;
    }
	
	/* Draw the ground */
	ground.x = ground_border.x = grass_border.x = asphalt.x = 0;
	ground.y = ground_border.y = background.y[3] + background.sprite[3]->h + 5;
	ground.w = ground_border.w = grass_border.w = asphalt.w = SCREEN_WIDTH;
	ground.h = SCREEN_HEIGHT - background.y[3];
	
	ground_border.h = asphalt.h = 5;
	
	grass_border.y = background.y[3] - 5;
	grass_border.h = background.sprite[3]->h + 10;
	
	asphalt.y = grass_border.y - 5;
	
	SDL_FillRect(game.screen, &ground, SDL_MapRGB(game.screen->format,
	                                              GROUND_R,
	                                              GROUND_G,
	                                              GROUND_B));
	
	SDL_FillRect(game.screen, &ground_border, SDL_MapRGB(game.screen->format,
	                                                     GROUND_R,
	                                                     GROUND_G + 30,
	                                                     GROUND_B + 30));
	
	SDL_FillRect(game.screen, &grass_border, SDL_MapRGB(game.screen->format, 50, 205, 50));
	
	SDL_FillRect(game.screen, &asphalt, SDL_MapRGB(game.screen->format, 68, 68, 68));
	
	
	/* increment the offset every ten cycles of the game loop */
	if (background.timer % 3 == 0) {
		background.offset++;
	}
	
	if (background.sprite[0]->w == background.offset) {
		background.offset = background.timer = 0;
	}
	                                              
	if (background.sprite[3]->w == background.grass_offset) {
		background.grass_offset = 0;
	}
	
	/* Draw the sprites */
	for (i = 0; i < 4; i++) {
		while (x - background.sprite[i]->w < SCREEN_WIDTH) {
			
			if (i != 3) {
				draw_image(background.sprite[i], x - background.offset, background.y[i]);
				x += background.sprite[i]->w;
			} else {
				draw_image(background.sprite[i], x - background.grass_offset, background.y[i]);
				x += background.sprite[i]->w;
			}
		}
		
		x = 0;
	}
}


/* draw_pipe - draws all active pipes on the screen */
void draw_pipe() {
	
	int i, j, len = 0, actives[MAX_PIPES], offset = 12, bottom_height, cur_ind;
	
	for (i = 0; i < MAX_PIPES; i++)
		if (pipes[i].active)
			actives[len++] = i;
	
	
	for (j = 0; j < len; j++) {
		
		cur_ind = actives[j];
		
		bottom_height = (GROUND_HEIGHT - offset - (PIPE_GAP + 
						pipes[cur_ind].height * pipes[cur_ind].pipe->h)) / pipes[cur_ind].pipe->h;

		for (i = 0; i < pipes[cur_ind].height - 2; i++) {
			draw_image(pipes[cur_ind].pipe, pipes[cur_ind].x, i * pipes[cur_ind].pipe->h);
		}

		for (i = pipes[cur_ind].height - 2; i <= pipes[cur_ind].height; i++) {
			draw_image(pipes[cur_ind].pipe_top, pipes[cur_ind].x - 2, i * pipes[cur_ind].pipe->h - 1);
		}

		for (i = 0; i < bottom_height - 2; i++) {
			draw_image(pipes[cur_ind].pipe, pipes[cur_ind].x, 
			           GROUND_HEIGHT - offset - i * pipes[cur_ind].pipe->h);
		}

		for (i = bottom_height - 2; i <= bottom_height; i++) {
			draw_image(pipes[cur_ind].pipe_top, pipes[cur_ind].x - 2, 
					   GROUND_HEIGHT - offset - i * pipes[cur_ind].pipe->h - 1);
		}
	}
}
