#include "collision.h"


/* is_collision - checks for a collision between the bird and a pipe */
bool is_collision() {

	int i; 
	for (i = 0; i < MAX_PIPES; i++) {

		if (pipes[i].active) {
			
			/* check for collision on top of pipe */
			if (bird.x + BIRD_WIDTH - 1 >= pipes[i].x &&
			    bird.x + BIRD_WIDTH - 1 <= pipes[i].x + pipes[i].pipe->w &&
			    (bird.y <= pipes[i].height * pipes[i].pipe->h ||
			     bird.y + bird.bird->h >= pipes[i].height * pipes[i].pipe->h + PIPE_GAP)) {
				return true;
			}
			
			/* check for collision on side of pipe */
			/* check for collision on corner of pipe */
		}
	}
	
	return false;
}
