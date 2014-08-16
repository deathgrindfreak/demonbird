#include "draw.h"


/* draw - draws everything to a buffer, then flips buffer to game screen */
void draw() {
	
	char score[20];

    /* Blank the screen */
    SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 
                                               BACKGROUND_R,
                                               BACKGROUND_G,
                                               BACKGROUND_B));

    /* draw the background */
    draw_background();
    
    /* move the pipes */
    move_pipes();
    
    /* draw the pipes */
    draw_pipe();
    
    /* get the current bird clip */
    get_bird_position();
    
    /* check for a collision */
    printf("%s\n", is_collision() ? "true" : "false");
    
    /* draw the bird */
    draw_bird();
    
    /* draw the score */
    check_score();
    sprintf(score, "%d", game.score);
    draw_string(score, SCREEN_WIDTH / 2, 20, game.score_font, true, false);

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
