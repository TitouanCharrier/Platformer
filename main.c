#include "src/mainfunc.h"

int main(int argc, char *argv[]) {

	//starting SL2
	SDL_Init(SDL_INIT_VIDEO);
	
	//set antialiasing
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//starting TTF (to display text))
	TTF_Init();

	time_t t;
	srand((unsigned) time(&t));
	
	//Display menu
	//Play_menu();
	SDL_Renderer *renderer = NULL;
	SDL_Window *window = NULL;

	SDL_DisplayMode Screen;
	SDL_GetCurrentDisplayMode(0, &Screen);
	int WIDTH = Screen.w;
	int HEIGHT = Screen.h;

	//set window and renderer
	window = SDL_CreateWindow("name",0,0,WIDTH,HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	//set event var to store events
	SDL_Event event;
	
	//set var to run the main while
	bool run = 1;
	
	//Hero is a Hitbox, type defined in src/struct.h 
	Hitbox HeroBox;
        HeroBox.centrx = WIDTH/4;
        HeroBox.centry = HEIGHT/2;
        HeroBox.sizex = 447/11;
        HeroBox.sizey = 827/11;

	//Obstacles same
	Hitbox ListObstacle[NBR_OBS];
	for (int i=0; i<NBR_OBS; i++) {
	        ListObstacle[i].centrx = (rand() % WIDTH *20)-WIDTH*10;
        	ListObstacle[i].centry = rand() % HEIGHT;
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
		"rsc/linux-1598424452826-2734.bmp", "rsc/obstacle.bmp"};
	
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
		HeroBox = MoveHero(renderer, HeroBox, ListObstacle, event, ListTexture,WIDTH,HEIGHT);
		
		//closing window
		if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;
		
		}
		
		

		//wait
                SDL_Delay(16);      
	}	

	//quit SDL
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


