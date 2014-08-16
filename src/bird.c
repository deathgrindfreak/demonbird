#include "bird.h"


/* init_bird - initialize the bird */
void init_bird() {

	bird.x = (SCREEN_WIDTH - BIRD_WIDTH) / 2;
	bird.y = (GROUND_HEIGHT - bird.bird->h) / 2;
	bird.flap = bird.timer = bird.fall_time = bird.fall_timer = 0;
	bird.is_flapping = false;
}


/* get_bird_position - is mostly responsible for animated the birds wings */
void get_bird_position() {

	bird.timer++;
	
	if (bird.timer >= FLAP_TIME) {

		if (bird.flap != 2) {
			bird.flap++;
		} else {
			bird.flap = 0;
		}

		bird.timer = 0;
	}
}


/* move_bird - moves the bird down continously */
void move_bird() {
	
	int y_increment;
	
	/* bird is on the screen */
	if (bird.y >= 0 && bird.y <= BOTTOM_LIMIT) {
		
		bird.fall_timer++;
			
		/* If the user never presses the up key, the bird should free fall */
		if (bird.is_flapping) {
			
			y_increment = GRAVITY * (bird.fall_time + 0.5) - FLAP_SPEED;
			
			/* ensure that it doesn't flap offscreen */
			if (bird.y + y_increment <= BOTTOM_LIMIT && bird.y + y_increment >= 0) {
				
				/* ensure that the bird is still moving upwards */
				if (bird.fall_timer % FALL_SPEED == 0) {
					bird.fall_time++;
					bird.y += y_increment;
				} 
				
			} else if (bird.y + y_increment < 0) {
				bird.y = 0;
				bird.fall_time++;
				
			} else if (bird.y + y_increment > BOTTOM_LIMIT) {
				bird.y = BOTTOM_LIMIT;
			}
			
		} else {
			
			y_increment = GRAVITY * (bird.fall_time + 0.5);
			
			/* check to make sure the increment wouldn't force the bird below the BOTTOM_LIMIT */
			if (bird.y + y_increment <= BOTTOM_LIMIT) {
				if (bird.fall_timer % FALL_SPEED == 0) {
					bird.fall_time++;
					bird.y += y_increment;
				}
			} else {
				bird.y = BOTTOM_LIMIT;
			}
		}
	}
}


/* check_score - controls the score of the game */
void check_score() {

	int i;
	for (i = 0; i < MAX_PIPES; i++) {
		if (pipes[i].active && pipes[i].x == bird.x + BIRD_WIDTH / 2) {
			game.score++;
			play_sound(DETH_SOUND);
		}
	}
}
