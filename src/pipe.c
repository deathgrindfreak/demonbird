#include "pipe.h"


/* init_pipes - initializes the pipe struct */
void init_pipes() {
	
	int i;
	for (i = 0; i < MAX_PIPES; i++) {
		pipes[i].active = false;
		pipes[i].pipe = load_image("img/pipe.png");
		pipes[i].pipe_top = load_image("img/pipe_top.png");
		pipes[i].height = rand() % HEIGHT_RANGE + HEIGHT_OFFSET;
		pipes[i].x = SCREEN_WIDTH + pipes[i].pipe_top->w;
	}
	
	pipes[0].active = true;
}


/* get_free_pipe - gets the first free pipe */
int get_free_pipe() {
	
	int i;
	for (i = 0; i < MAX_PIPES; i++) {
		if (!pipes[i].active) {
			return i;
		}
	}
	
	/* if no pipes are available */
	printf("No pipes available!\n");
	return -1;
}


/* move_pipes - moves the pipes on the board */
void move_pipes() {
	
	int i, j, c, len = 0, actives[MAX_PIPES];
	
	for (i = 0; i < MAX_PIPES; i++)
		if (pipes[i].active)
			actives[len++] = i;
	
	/* move all active pipes */
	for (j = 0; j < len; j++) {
		
		c = actives[j];
		
		/* move the pipe left */
		pipes[c].x--;
		
		/* if the pipe moves offscreen */
		if (pipes[c].x < -1 * pipes[c].pipe_top->w) {
			pipes[c].active = false;
			pipes[c].height = rand() % HEIGHT_RANGE + HEIGHT_OFFSET;
			pipes[c].x = SCREEN_WIDTH + pipes[c].pipe_top->w;
		}
		
		/* if the pipe has moved far enough */
		if (pipes[c].x < SCREEN_WIDTH - PIPE_SPACING - pipes[c].pipe_top->w) {
			if (c < MAX_PIPES - 1) {
				pipes[c+1].active = true;
			} else {
				pipes[0].active = true;
			}
		}
	}
}
