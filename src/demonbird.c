#include "demonbird.h"


int main(int argv, char *args[]) {

    /* Set the framelimit */
    unsigned int frame_limit = SDL_GetTicks() + 16;

    /* Game loop boolean */
    bool running = true;
    
    /* Seed for random numbers */
	srand(time(NULL));

    /* Start SDL */
    init("Demon Bird");

    /* Initialize the game struct */
    init_game();

    /* Clean up on exit */
    atexit(cleanup);


    /* Game loop */
    while (running) {
	    
        /* Get user input */
        get_input();
        
        /* move the bird */
        move_bird();

        /* Draw everything on the screen */
        draw();

        /* Sleep for a bit */
        delay(frame_limit);
        frame_limit = SDL_GetTicks() + 16;
    }

    /* Exit the program */
    exit(0);
}


/* init_game - initialize the game struct */
void init_game() {
	
	load_pipe();
	
	/* load the bird sprite */
	load_bird();
	
	/* initialize the bird struct */
	init_bird();

	/* determine the bottom limit that the bird can travel */
	BOTTOM_LIMIT = GROUND_HEIGHT - bird.bird->h - 10;
	
	/* load the background sprites */
	load_background();
	
	/* inititalize the background timers */
	background.timer = background.offset = 0;
}
