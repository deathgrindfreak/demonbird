#include "collision.h"


/* is_collision - checks for a collision between the bird and a pipe */
bool is_collision() {

	int i;
    PipeShape cur_pipe;
    Ellipse bird_shape;

    init_pipeshape(&cur_pipe);

    bird_shape.major = BIRD_WIDTH - 4;
    bird_shape.minor = bird.bird->h;  

	for (i = 0; i < MAX_PIPES; i++) {

		if (pipes[i].active) {


            /* Instantiate the current pipe struct */
            cur_pipe.top_pipe.x = pipes[i].x;
            cur_pipe.top_pipe.y = 0;
            cur_pipe.top_pipe.width = pipes[i].pipe->w;
            cur_pipe.top_pipe.height = (pipes[i].height - 3) * pipes[i].pipe->h;

            cur_pipe.top_pipe_top.x = pipes[i].x - 2;
            cur_pipe.top_pipe_top.y = (pipes[i].height - 2) * pipes[i].pipe->h;
            cur_pipe.top_pipe_top.width = pipes[i].pipe_top->w;
            cur_pipe.top_pipe_top.height = 3 * pipes[i].pipe->h;

            cur_pipe.bottom_pipe.x = pipes[i].x;
            cur_pipe.bottom_pipe.y = (pipes[i].height + 3) * pipes[i].pipe->h + PIPE_GAP;
            cur_pipe.bottom_pipe.width = pipes[i].pipe->w;
            cur_pipe.bottom_pipe.height = BOTTOM_LIMIT - cur_pipe.bottom_pipe.y;

            cur_pipe.bottom_pipe_top.x = pipes[i].x - 2;
            cur_pipe.bottom_pipe_top.y = pipes[i].height * pipes[i].pipe->h + PIPE_GAP;
            cur_pipe.bottom_pipe_top.width = pipes[i].pipe_top->w;
            cur_pipe.bottom_pipe_top.height = 3 * pipes[i].pipe->h;
			
			/* check for collision on both tops of pipe */
			if (((bird.x + bird_shape.major >= cur_pipe.top_pipe_top.x &&
                  bird.x + bird_shape.major <= cur_pipe.top_pipe_top.x + cur_pipe.top_pipe_top.width) ||
			     (bird.x >= cur_pipe.top_pipe_top.x &&
                  bird.x <= cur_pipe.top_pipe_top.x + cur_pipe.top_pipe_top.width)) &&
			     (bird.y <= cur_pipe.top_pipe_top.y ||
			      bird.y + bird_shape.minor >= cur_pipe.bottom_pipe_top.y)) {
				return true;
			}
			
			/* check for collision on sides of pipe */
			if (((bird.x + bird_shape.major >= cur_pipe.top_pipe.x &&
                  bird.x + bird_shape.major <= cur_pipe.top_pipe.x + cur_pipe.top_pipe.width) ||
			     (bird.x >= cur_pipe.top_pipe.x &&
                  bird.x <= cur_pipe.top_pipe.x + cur_pipe.top_pipe.width)) &&
			     (bird.y <= cur_pipe.top_pipe.y ||
			      bird.y + bird_shape.minor >= cur_pipe.bottom_pipe.y)) {
				return true;
			}

			/* check for collision on corner of pipe */

		}
	}
	
	return false;
}


/* init_pipeshape - initializes a pipe shape */
void init_pipeshape(PipeShape *pipe) {

            pipe->top_pipe.x = 0;
            pipe->top_pipe.y = 0;
            pipe->top_pipe.width = 0;
            pipe->top_pipe.height = 0;

            pipe->top_pipe_top.x = 0;
            pipe->top_pipe_top.y = 0;
            pipe->top_pipe_top.width = 0;
            pipe->top_pipe_top.height = 0;

            pipe->bottom_pipe.x = 0;
            pipe->bottom_pipe.y = 0;
            pipe->bottom_pipe.width = 0;
            pipe->bottom_pipe.height = 0;

            pipe->bottom_pipe_top.x = 0;
            pipe->bottom_pipe_top.y = 0;
            pipe->bottom_pipe_top.width = 0;
            pipe->bottom_pipe_top.height = 0;
}
