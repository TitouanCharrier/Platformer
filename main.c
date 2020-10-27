#include "lib/mainfunc.h"
#include <pthread.h>

#define SCR_W 1920
#define SCR_H 1080
#define pi 3.14159265358979323846264338379
#define False 0
#define True 1
#define JUMP_H 30

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
	FloorBox.centry = SCR_H-300;
	FloorBox.sizex = 500;
	FloorBox.sizey = 100;
	FloorBox.r = 0;
	FloorBox.g = 255;
	FloorBox.b = 0;
	FloorBox.a = 255;
	FloorBox.fill = 1;

	//struct pour faire sortir les info de la fonction MH
	MoveHeroReturn MHR;
	MHR.HeroBox = HeroBox;
	MHR.Jump = JUMP_H;
	MoveHeroReturn MHR2;
	PrintHero(renderer, HeroBox, FloorBox, 0,255,255,255);

	while (run) {
		while (SDL_PollEvent(&event)) {
			MHR2 = (MoveHero(renderer, MHR.HeroBox, FloorBox, JUMP_H, 10, event));
			MHR.HeroBox = MHR2.HeroBox;
			MHR.Jump = JUMP_H;
			if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;
			SDL_RenderPresent(renderer);
			SDL_SetRenderDrawColor(renderer, 0,0,0,0);	
		}

                SDL_Delay(16);      
	}	
	//on quitte proprement (je crois) 
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


