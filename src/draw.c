#include "draw.h"


/* draw - draws everything to a buffer, then flips buffer to game screen */
void draw() {

    /* Blank the screen */
    SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 
                                               BACKGROUND_R,
                                               BACKGROUND_G,
                                               BACKGROUND_B));

    /* draw the background */
    draw_background();
    
    /* draw the pipes */
    draw_pipe();
    
    /* get the current bird clip */
    get_bird_position();
    
    /* draw the bird */
    draw_bird();

    /* Flip the buffer */
    SDL_Flip(game.screen);

    /* Sleep Briefly */
    SDL_Delay(1);
}


/* delay - set a delay for the CPU (minimum of 60 FPS) */
void delay(unsigned int frame_limit) {
unsigned int ticks = SDL_GetTicks(); 
    if (frame_limit < ticks) {
        return;
    } else if (frame_limit > ticks + 16) {
        SDL_Delay(16);
    } else {
        SDL_Delay(frame_limit - ticks);
    }
}
