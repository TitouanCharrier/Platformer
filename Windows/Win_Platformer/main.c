#include "src/mainfunc.h"

int main(int argc, char *argv[]) {
    printf("debug1");
	//starting SL2
	SDL_Init(SDL_INIT_VIDEO);

	//set antialiasing
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//starting TTF (to display text))
    //	TTF_Init();

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
	Hitbox ListObstacle[NBR_OBS+240];
	/*for (int i=0; i<NBR_OBS; i++) {
	        ListObstacle[i].centrx = (rand() % WIDTH *20)-WIDTH*10;
        	ListObstacle[i].centry = rand() % HEIGHT;
        	ListObstacle[i].sizex = 75;
       		ListObstacle[i].sizey = 75;
	}*/
	for (int i=0; i<240; i++) {
	        ListObstacle[i].centrx = 250*i - 10*WIDTH;
        	ListObstacle[i].centry = HEIGHT-20;
        	ListObstacle[i].sizex = 250;
       		ListObstacle[i].sizey = 37;
	}
    // Loading
    FILE *fichier_textures = NULL;
    fichier_textures = fopen("rsc/textures.txt","r");

    //loading Textures
    SDL_Texture *ListTextures[243];
    char ListTexturesName[243][40];
    for (int i=3; i<243; i++) {
        fgets(ListTexturesName[i],40,fichier_textures);
        ListTextures[i] = Loading(renderer, ListTexturesName[i]);

    }
    /*
	//printing scene
	PrintHero(renderer, HeroBox, ListObstacle, ListTextures);

	//main while
	while (run) {

		//event while
		while (SDL_PollEvent(&event)) {

		//call to the function who manage hero's movements
		HeroBox = MoveHero(renderer, HeroBox, ListObstacle, event, ListTextures,WIDTH,HEIGHT);

		//closing window
		if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;

		}



		//wait
                SDL_Delay(16);
	}

	//quit SDL
	SDL_DestroyRenderer(renderer);
	SDL_Quit();*/
    return 0;
}


