#include "lib/mainfunc.h"

int main(int argc, char *argv[]) {
	//initiatilsation SDL2
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer *renderer = NULL;
	SDL_Renderer *renderbg = NULL;
	SDL_Window *window = NULL;

	//définition de la fenètre et du renderer
	window = SDL_CreateWindow("name",0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//création des listes de hitbox
	Hitbox ListBoxMv[5];
	Hitbox ListBoxSt[10];

	//création de la variable événement
	SDL_Event event;
	
	bool run = 1;
	
	//Hero
	Hitbox HeroBox;
        HeroBox.centrx = SCREEN_WIDTH/4;
        HeroBox.centry = SCREEN_HEIGHT/2;
        HeroBox.sizex = 447/10;
        HeroBox.sizey = 827/10;

	//Obstacles
	Hitbox ListObstacle[NBR_OBS];
	for (int i=0; i<NBR_OBS; i++) {
	        ListObstacle[i].centrx = 200 + 75*i;
        	ListObstacle[i].centry = 768 - 50*i;
        	ListObstacle[i].sizex = 75;
       		ListObstacle[i].sizey = 75;
        	ListObstacle[i].r = 0;
        	ListObstacle[i].g = 255;
        	ListObstacle[i].b = 0;
        	ListObstacle[i].a = 255;
        	ListObstacle[i].fill = 1;

	}
	//struct pour faire sortir les info de la fonction MH
	MoveHeroReturn MHR;
	MHR.HeroBox = HeroBox;
	MHR.Jump = JUMP_HEIGHT;
	MoveHeroReturn MHR2;
	PrintHero(renderer, HeroBox, ListObstacle, 0,255,255,255);
	
	float CountMoutons = 0;
	while (run) {
		while (SDL_PollEvent(&event)) {
			MHR2 = (MoveHero(renderer, MHR.HeroBox, ListObstacle, JUMP_HEIGHT, event));
			MHR.HeroBox = MHR2.HeroBox;
			MHR.Jump = JUMP_HEIGHT;
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


