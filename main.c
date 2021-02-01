#include "src/mainfunc.h"

int main(int argc, char *argv[]) {
    printf("debug1");
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
	int IncrHerbe = 3;
	int *p_IncrHerbe = &IncrHerbe;
	//set window and renderer
	window = SDL_CreateWindow("name",0,0,WIDTH,HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//set event var to store events
	SDL_Event event;

	//set var to run the main while
	bool run = 1;
    
    //loading objects
    
    Hitbox **ListObjects = LoadObjects(WIDTH,HEIGHT);
    printf("%d",ListObjects[1][125].sizey);
  
    // Loading textures
    FILE *fichier_textures = NULL;
    fichier_textures = fopen("rsc/textures.txt","r");

    //loading Textures
    SDL_Texture *ListTextures[443];
    char ListTexturesName[443][40];
    for (int i=0; i<443; i++) {
        fgets(ListTexturesName[i],40,fichier_textures);
        ListTexturesName[i][strlen(ListTexturesName[i])-1] = '\0';
        printf("%s\n",ListTexturesName[i]);
        ListTextures[i] = Loading(renderer, ListTexturesName[i]);

    }

	//printing scene
	PrintHero(renderer, ListObjects, ListTextures, *p_IncrHerbe);
	
	//main while
	while (run) {

		//event while
		while (SDL_PollEvent(&event)) {

            //call to the function who manage hero's movements
            ListObjects[0][0] = MoveHero(renderer, ListObjects, event, ListTextures,WIDTH,HEIGHT, p_IncrHerbe);

            //closing window
            if (event.key.keysym.sym == SDLK_ESCAPE) run = 0;

		}

		//print scene
		PrintHero(renderer, ListObjects, ListTextures, *p_IncrHerbe);
		*p_IncrHerbe += 1;

		//wait
        SDL_Delay(16);
	}
    
	//quit SDL
	printf("end reached");
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

    return 0;
}


