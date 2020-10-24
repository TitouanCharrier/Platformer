#include "lib/mainfunc.h"


#define SCR_W 1920
#define SCR_H 1080
#define pi 3.14159265358979323846264338379
#define False 0
#define True 1

int main() {

	//initiatilsation SDL2
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer *renderer = NULL;
	SDL_Renderer *renderbg = NULL;
	SDL_Window *window = NULL;

	//définition de la fenètre et du renderer
	window = SDL_CreateWindow("name",0,0,SCR_W,SCR_H,SDL_RENDERER_ACCELERATED);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	//création des listes de hitbox
	Hitbox ListBoxMv[5];
	Hitbox ListBoxSt[10];

	//création de la variable événement
	SDL_Event event;
	
	bool run = 1;
	
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderPresent(renderer);

 	Hitbox HeroBox;
	HeroBox.centrx = SCR_W/4;
	HeroBox.centry = SCR_H/2;
	HeroBox.sizex = 25;
	HeroBox.sizey = 50;
	
	Hitbox FloorBox;
	FloorBox.centrx = SCR_W/2;
	FloorBox.centry = SCR_H/2;
	FloorBox.sizex = 100;
	FloorBox.sizey = 100;


	RegulPoly(renderer, 5, 100, 1366/2, 768/2,1, 255, 0,0,0, 0);

	PrintHero(renderer, HeroBox, 0,255,255,255);

	while (run) {
		while (SDL_PollEvent(&event)) {
			HeroBox = MoveHero(renderer, HeroBox, FloorBox, 10, event);
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				run = 0;
			}
		CreateRectangle(renderer, SCR_W/2, SCR_H/2, 100, 100, 0, 255, 0, 255, 1);
		SDL_RenderPresent(renderer);
		SDL_SetRenderDrawColor(renderer, 0,0,0,0);	
		SDL_Delay(16);
		}
	SDL_Delay(16);
	}	
	//on quitte proprement (je crois) SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


