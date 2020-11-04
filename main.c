#include "lib/mainfunc.h"

int main(int argc, char *argv[]) {
	
	//initiatilsation SDL2
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;

	//définition de la fenètre et du renderer
	window = SDL_CreateWindow("name",0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
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
        	ListObstacle[i].centry = SCREEN_HEIGHT - 50*i;
        	ListObstacle[i].sizex = 75;
       		ListObstacle[i].sizey = 75;
        	ListObstacle[i].r = 0;
        	ListObstacle[i].g = 255;
        	ListObstacle[i].b = 0;
        	ListObstacle[i].a = 255;
        	ListObstacle[i].fill = 0;

	}
	
	//Image
	char ListImage[NBR_IMAGE][40] = {"rsc/external-content.bmp", 
		"rsc/linux-1598424452826-2734.bmp", "rsc/mouton.bmp"};
	
	
	//charger les images
	SDL_Texture *ListTexture[NBR_IMAGE];
	for (int i=0; i<NBR_IMAGE; i++) {
		ListTexture[i] = Loading(renderer, ListImage[i]);
	}
	
	//struct pour faire sortir les info de la fonction MH
	PrintHero(renderer, HeroBox, ListObstacle, ListTexture);
	
	while (run) {
		while (SDL_PollEvent(&event)) {
			HeroBox = (MoveHero(renderer, HeroBox, ListObstacle, event, ListTexture));
			if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;
		}
		//debug
		/*	
		for (int i=0; i<5; i++) {
			printf("%d", (CompareHitbox(HeroBox, ListObstacle)).direction[i]);
		}*/
		//wait
                SDL_Delay(16);      
	}	
	//quit SDL
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


