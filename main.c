#include "src/mainfunc.h"

int main(int argc, char *argv[]) {
	//starting SL2
	SDL_Init(SDL_INIT_VIDEO);

	//set antialiasing
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//starting TTF (to display text))
    	//TTF_Init();

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
	Increment increment;
	Increment *Incr = &increment;
        Incr->Herbe = 0;
        Incr->Hero = 0;
	
	//set window and renderer
	window = SDL_CreateWindow("name",0,0,WIDTH,HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//set event var to store events
	SDL_Event event;

	//set var to run the main while
	bool run = 1;
    
    //load texture
    SDL_Texture ***ListTextures = LoadTexture(renderer);

	//loading objects
    Hitbox **ListObjects = LoadMap(WIDTH, HEIGHT, "map/Test_1.txt", 4);
    //Hitbox **ListObjects = LoadObjects(WIDTH,HEIGHT);
	printf("debug1\n");
	//printing scene
	PrintHero(renderer, ListObjects, ListTextures, Incr);
	printf("dubug2\n");
	//main while
	while (run) {

		//event while
		while (SDL_PollEvent(&event)) {

            //call to the function who manage hero's movements
            ListObjects[0][0] = MoveHero(renderer, ListObjects, event, ListTextures,WIDTH,HEIGHT, Incr);

            //closing window
            if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;

		}
		//change jump status to standing
        Incr->StateHero = 0;
		//print scene
		PrintHero(renderer, ListObjects, ListTextures, Incr);
		Incr->Herbe += 1;
	
		//wait
        //SDL_Delay(16);
	}
	
	//quit SDL
	printf("end reached\n");
	//free(ListObjects);
	free(ListTextures);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
    return 0;
}


