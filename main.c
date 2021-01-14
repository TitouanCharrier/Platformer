#include "src/mainfunc.h"

int main(int argc, char *argv[]) {
	
	//starting SL2
	SDL_Init(SDL_INIT_VIDEO);
	
	//starting TTF (to display text))
	TTF_Init();
	
	//Display menu
	Play_menu();

	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;

	//set window and renderer
	window = SDL_CreateWindow("name",0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//set event var to store events
	SDL_Event event;
	
	//set var to run the main while
	bool run = 1;
	
	//Hero is a Hitbox, type defined in src/struct.h 
	Hitbox HeroBox;
        HeroBox.centrx = SCREEN_WIDTH/4;
        HeroBox.centry = SCREEN_HEIGHT/2;
        HeroBox.sizex = 447/10;
        HeroBox.sizey = 827/10;

	//Obstacles same
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
	
	//set list of images paths
	char ListImage[NBR_IMAGE][40] = {"rsc/external-content.bmp", 
		"rsc/linux-1598424452826-2734.bmp", "rsc/mouton.bmp"};
	
	//loading texture
	SDL_Texture *ListTexture[NBR_IMAGE];
	for (int i=0; i<NBR_IMAGE; i++) {
		ListTexture[i] = Loading(renderer, ListImage[i]);
	}

	//printing scene
	PrintHero(renderer, HeroBox, ListObstacle, ListTexture);
	
	//main while
	while (run) {
		
		//event while
		while (SDL_PollEvent(&event)) {
			//call to the function who manage hero's movements
			HeroBox = (MoveHero(renderer, HeroBox, ListObstacle, event, ListTexture));
			
			//closing window
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


