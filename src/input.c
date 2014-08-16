#include "input.h"


/* get_input - get input from the user and perform appropriate actions */
void get_input() {

    SDL_Event event;

    /* Loop through events */
    while (SDL_PollEvent(&event)) {

        switch(event.type) {

            case SDL_QUIT:
                exit(0);
                break;

            /* In case of a key press */
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {

                    case SDLK_UP:
	                    bird.is_flapping = true;
						bird.fall_time = bird.fall_timer = 0;
                        break;
                        
                    case SDLK_SPACE:
	                    bird.is_flapping = true;
						bird.fall_time = bird.fall_timer = 0;
                        break;
                        
					case 'p':
						game.paused = !game.paused;
						break;

					case SDLK_ESCAPE:
						game.paused = !game.paused;
						break;
						
					case SDLK_RETURN:
						if (game.paused) {
						}
						break;

                    default:
                        break;
                }
                break;
        }
    }
}
