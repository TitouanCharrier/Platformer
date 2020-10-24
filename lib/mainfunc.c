#include "mainfunc.h"

int CompareHitbox(Hitbox mobile, Hitbox statique) {
	return 1;
}

void PrintHero(SDL_Renderer *renderer,Hitbox HeroBox, int r, int g, int b, int a) {
	SDL_RenderClear(renderer);	
	RegulPoly(renderer, 6, 100, HeroBox.centrx, HeroBox.centry,1, r,g,b,a, 0);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
}

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, int speed, int direction) {
		switch (direction) {
	                case 1 :
        	                subject.centry -= speed;
                	        break;
                	case 2 :
                	        subject.centry += speed;
                	        break;
                	case 3 :
                	        subject.centrx += speed;
                	        break;
                	case 4 :
                	        subject.centrx -= speed;
                	        break;
                }

        PrintHero(renderer, subject, 255,0,0,255);
	return (subject);
}

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int direction = 0;
		do {
			if (event.type == SDL_KEYDOWN) {

				if (event.key.keysym.sym == SDLK_UP) {
					direction = 1;
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					direction = 2;
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
					direction = 3;
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					direction = 4;
				}
			}


			if (direction != 0) {
				HeroBox =  Move(renderer, HeroBox, 10, direction);
                        	SDL_Delay(16);
			}
			SDL_PollEvent(&event);

		} while (event.type != SDL_KEYUP);
	}
        SDL_PollEvent(&event);
	return HeroBox;

}
