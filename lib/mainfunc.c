#include "mainfunc.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique, int speed) {
	int mcx = mobile.centrx;
	int mcy = mobile.centry;
	int msx = mobile.sizex;
	int msy = mobile.sizey;
	int scx = statique.centrx;
	int scy = statique.centry;
	int ssx = statique.sizex;
	int ssy = statique.sizey;

	if ((mcx+msx/2+speed >= scx-ssx/2) & (mcx-msx/2-speed <= scx+ssx/2)) {
		if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2) | (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
			return 1;
		}
	}
	else {
		return 0;
	}
}

int CompareHitbox_Y(Hitbox mobile, Hitbox statique, int speed) {
        int mcx = mobile.centrx;
        int mcy = mobile.centry;
        int msx = mobile.sizex;
        int msy = mobile.sizey;
        int scx = statique.centrx;
        int scy = statique.centry;
        int ssx = statique.sizex;
        int ssy = statique.sizey;

        if ((mcy+msy/2+speed >= scy-ssy/2) & (mcy-msy/2-speed <= scy+ssy/2)) {
                if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2) | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) { 
                        return 1;
                }
        }

        
        else {  
                return 0;
        }
}

void PrintHero(SDL_Renderer *renderer,Hitbox HeroBox, int r, int g, int b, int a) {
	SDL_RenderClear(renderer);	
	CreateRectangle(renderer,HeroBox.centrx, HeroBox.centry, HeroBox.sizex, HeroBox.sizey, r,g,b,a, 0);
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

Hitbox Collision(Hitbox HeroBox, Hitbox FloorBox,int speed, int CauseStop) {
	if (CompareHitbox_Y(HeroBox, FloorBox, speed) == 1 & CauseStop == 1) {
        	HeroBox.centry = FloorBox.centry + FloorBox.sizey/2 + HeroBox.sizey/2 +10;
                return HeroBox;
        }
        if (CompareHitbox_Y(HeroBox, FloorBox, speed) == 1 & CauseStop == 2) {
                HeroBox.centry = FloorBox.centry - FloorBox.sizey/2 - HeroBox.sizey/2 -10;
                return HeroBox;
        }
        if (CompareHitbox_X(HeroBox, FloorBox, speed) == 1 & CauseStop == 3) {
                HeroBox.centrx = FloorBox.centrx - FloorBox.sizex/2 - HeroBox.sizex/2 -10;
                return HeroBox;
        }
        if (CompareHitbox_X(HeroBox, FloorBox, speed) == 1 & CauseStop == 4) {
                HeroBox.centrx = FloorBox.centrx + FloorBox.sizex/2 + HeroBox.sizex/2 +10;
                return HeroBox;
        }

		
}

void MoveHero(SDL_Renderer *renderer, Hitbox *HeroBox, Hitbox FloorBox, int speed, SDL_Event event) {
	int CauseStop = 0;
	if (event.type == SDL_KEYDOWN) {
		int direction = 0;
		do {
			if (event.type == SDL_KEYDOWN) {

				if (event.key.keysym.sym == SDLK_UP) {
					if ((CompareHitbox_Y(HeroBox, FloorBox, speed) == 1) & (HeroBox.centry > FloorBox.centry)) {
						CauseStop = 1;
						HeroBox.centry = FloorBox.centry + FloorBox.sizey/2 + HeroBox.sizey/2 +speed;
                                        	direction = 0;
                                	}
					else {
						direction = 1;
					}
				}
				if (event.key.keysym.sym == SDLK_DOWN) {
					if ((CompareHitbox_Y(HeroBox, FloorBox, speed) == 1) & (HeroBox.centry < FloorBox.centry)) {
						CauseStop = 2;
						HeroBox.centry = FloorBox.centry - FloorBox.sizey/2 - HeroBox.sizey/2 -speed;
                                                direction = 0;
                                        }
                                        else {  
                                                direction = 2;
                                        }

				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
					if ((CompareHitbox_X(HeroBox, FloorBox, speed) == 1) & (HeroBox.centrx < FloorBox.centrx)) {
						CauseStop = 3;
						HeroBox.centrx = FloorBox.centrx - FloorBox.sizex/2 - HeroBox.sizex/2 -speed;
                                                direction = 0;
                                        }
                                        else {  
                                                direction = 3;
                                        }

				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					if ((CompareHitbox_X(HeroBox, FloorBox, speed) == 1) & (HeroBox.centrx > FloorBox.centrx)) {
						CauseStop = 4;
						HeroBox.centrx = FloorBox.centrx + FloorBox.sizex/2 + HeroBox.sizex/2 +speed;
                                                direction = 0;
                                        }

                                        else {  
                                                direction = 4;
                                        }

				}
			}
			

			if (direction != 0) {
				HeroBox =  Move(renderer, HeroBox, speed, direction);
                                SDL_Delay(16);

			}

			else {
				PrintHero(renderer, HeroBox, 0,255,255,255);
			}
			//Collision(HeroBox, FloorBox, speed, CauseStop);

			SDL_PollEvent(&event);

		} while (event.type != SDL_KEYUP);
	}
        SDL_PollEvent(&event);
}

void Jump(SDL_Renderer *renderer, Hitbox *HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event) {
	if (event.type == SDL_KEYDOWN & event.key.keysym.sym == SDLK_SPACE) {
	
		if (jump_H != 0) {
			for (float i=0; i<jump_H; i+=0.1) {
                		HeroBox = Move(renderer, HeroBox, 10*cos(i), 1);
                		PrintHero(renderer, HeroBox, 0,255, 255, 255);
				SDL_Delay(16);
			}
			while (CompareHitbox_Y(HeroBox,FloorBox, speed) != 1 & HeroBox.centry < 768) {
				HeroBox = Move(renderer, HeroBox, 10, 2);
				Collision(HeroBox, FloorBox, speed, 1);
                                PrintHero(renderer, HeroBox, 0,255, 255, 255);
                                SDL_Delay(16);

			}
			SDL_PollEvent(&event);
         	}
	}
	return HeroBox;

}
