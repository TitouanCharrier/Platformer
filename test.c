#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Salut");
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
}
