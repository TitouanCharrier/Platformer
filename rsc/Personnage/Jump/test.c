#include <SDL2/SDL.h>
#include <time.h>
int main(int argc, char **argv) {
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
	//set window and renderer
	window = SDL_CreateWindow("name",0,0,WIDTH,HEIGHT,0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderClear(renderer);

	SDL_Surface *buffer = SDL_LoadBMP("/home/titouan/Sync/Code/Projets/Platformer/rsc/Personnage/Jump/0017.bmp");
    if (buffer == NULL) {
        printf("texture : %s\n:", SDL_GetError());
    }
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(renderer, buffer);

	SDL_RenderCopy(renderer, Texture, NULL, NULL);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

}