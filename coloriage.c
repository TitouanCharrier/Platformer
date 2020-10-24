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

	bool hollow = 0;
	
	int poly = 3; 

	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderPresent(renderer);

	while (run) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				while (event.button.button == SDL_BUTTON_LEFT) {
					RegulPoly(renderer, poly, 50, event.button.x, event.button.y,1, 255, event.button.x/10, event.button.y/10,255, hollow);
					SDL_RenderPresent(renderer);
					SDL_PollEvent(&event);
				}
			}
			
			if ((event.type == SDL_KEYDOWN) & (event.key.keysym.sym == SDLK_q)) {
				run = 0;
			}
		 	if ((event.type == SDL_KEYDOWN) & (event.key.keysym.sym == SDLK_c)) {
                                SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
                        }
			if ((event.type == SDL_KEYDOWN) & (event.key.keysym.sym == SDLK_p)) {
                                if (poly < 10) {
					poly ++;
				}
                        }
			if ((event.type == SDL_KEYDOWN) & (event.key.keysym.sym == SDLK_m)) {
				if (poly > 2) {
					poly --;
				}
                        }
			if ((event.type == SDL_KEYDOWN) & (event.key.keysym.sym == SDLK_f)) {
                                if (hollow == 1) {
                                        hollow = 0;
                                }
				else {
					hollow = 1;
				}
                        }

			
		}

	}	
	//on quitte proprement (je crois)
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


