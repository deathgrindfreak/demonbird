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

        /* if the game is over */
        if (game.over) {

            /* pause for a bit */
            SDL_Delay(1000);

            /* start a new game */
            new_game();
        }

        /* Sleep for a bit */
        delay(frame_limit);
        frame_limit = SDL_GetTicks() + 16;
    }

    /* Exit the program */
    exit(0);
}


/* init_game - initialize the game struct */
void init_game() {
	
	/* load the score font and set the score to zero */
	game.score_font = load_font("font/blackWolf.ttf", 24);
	game.score = 0;
    game.paused = game.over = false;
	
	/* load all of the sounds */
	load_all_sounds();
	/*play_sound(ANGEL_OF_DEATH);*/
	
	/* Initialize the pipe structs */
	init_pipes();
	
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


/* new_game - initialize a new game struct */
void new_game() {

	/* load the score font and set the score to zero */
	game.score = 0;
    game.paused = game.over = false;
	
	/* Initialize the pipe structs */
	init_pipes();
	
	/* initialize the bird struct */
	init_bird();

	/* inititalize the background timers */
	background.timer = background.offset = 0;
}
