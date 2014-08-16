#include "audio.h"


void load_sound(int index, char *name) {
	
	/* Load the sound specified by the filename */
	if (index < 0 || index >= MAX_SOUNDS) {
		printf("Invalid index for sound! Index: %d Maximum: %d\n", index, MAX_SOUNDS);
		
		exit(1);
	}
	
	sound[index].effect = Mix_LoadWAV(name);

	if (sound[index].effect == NULL) {
		printf("Failed to load sound %s\n", name);
		
		exit(1);
	}
}

void play_sound(int index) {
	
	/* Play the sound on the first free channel and only play it once */
	if (index < 0 || index >= MAX_SOUNDS) {
		printf("Invalid index for sound! Index: %d Maximum: %d\n", index, MAX_SOUNDS);
		
		exit(1);
	}
	
	Mix_PlayChannel(-1, sound[index].effect, 0);
}

void load_all_sounds() {
	/*load_sound(ANGEL_OF_DEATH, "sounds/angel_of_death.ogg");*/
	load_sound(DETH_SOUND, "sounds/dethbleep.ogg");
}

void freeSounds() {
	int i;
	
	for (i=0;i<MAX_SOUNDS;i++) {
		if (sound[i].effect != NULL) {
			Mix_FreeChunk(sound[i].effect);
		}
	}
}
