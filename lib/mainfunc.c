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

	if ((mcx+msx/2+speed >= scx-ssx/2) & (mcx-msx/2-speed <= scx)) {
		if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2) | (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
			return 4;
		}
	}

	else if ((mcx+msx/2+speed >= scx) & (mcx-msx/2-speed <= scx+ssx/2)) {
                if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2) | (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
                        return 3;
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

        if ((mcy+msy/2+speed >= scy-ssy/2) & (mcy-msy/2-speed <= scy)) {
                if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2) | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) { 
                        return 1;
                }
        }

	if ((mcy+msy/2+speed >= scy) & (mcy-msy/2-speed <= scy+ssy/2)) {
                if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2) | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) {
                        return 2;
                }
        }


        
        else {  
                return 0;
        }
}

void PrintHero(SDL_Renderer *renderer,Hitbox HeroBox,Hitbox FloorBox, int r, int g, int b, int a) {
	SDL_RenderClear(renderer);
	CreateRectangle(renderer,FloorBox.centrx,FloorBox.centry,FloorBox.sizex+17,FloorBox.sizey+17,FloorBox.r,FloorBox.g,FloorBox.b,FloorBox.a,FloorBox.fill);  
	CreateRectangle(renderer,HeroBox.centrx, HeroBox.centry, HeroBox.sizex, HeroBox.sizey, r,g,b,a, 0);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
}

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, Hitbox FloorBox, int speed, int direction) {
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
	return (subject);
}

Hitbox Collision(Hitbox HeroBox, Hitbox FloorBox,int speed) {
	if (CompareHitbox_Y(HeroBox, FloorBox, speed) == 1) {
        	HeroBox.centry = FloorBox.centry + FloorBox.sizey/2 + HeroBox.sizey/2 +10;
                return HeroBox;
        }
        if (CompareHitbox_Y(HeroBox, FloorBox, speed) == 2) {
                HeroBox.centry = FloorBox.centry - FloorBox.sizey/2 - HeroBox.sizey/2 -10;
                return HeroBox;
        }
        if (CompareHitbox_X(HeroBox, FloorBox, speed) == 3) {
                HeroBox.centrx = FloorBox.centrx - FloorBox.sizex/2 - HeroBox.sizex/2 -10;
                return HeroBox;
        }
        if (CompareHitbox_X(HeroBox, FloorBox, speed) == 4) {
                HeroBox.centrx = FloorBox.centrx + FloorBox.sizex/2 + HeroBox.sizex/2 +10;
                return HeroBox;
        }

}

MoveHeroReturn MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox,int Jump_H, int speed, SDL_Event event) {
	float Jump = 0;
	int grav= 0;
	bool MvRight = 0;
	bool MvLeft = 0;
	if (event.type == SDL_KEYDOWN) {
		int direction = 0;
		do {
			if (event.type == SDL_KEYDOWN) {

				if (event.key.keysym.sym == SDLK_ESCAPE) break;

				if (event.key.keysym.sym == SDLK_SPACE & Jump == 0 & ((CompareHitbox_Y(HeroBox, FloorBox, speed) == 1) | (HeroBox.centry >= 790))) {
					if ((CompareHitbox_X(HeroBox, FloorBox, speed) == 1) & (HeroBox.centrx < FloorBox.centrx)) {
                                                HeroBox.centrx = FloorBox.centrx - FloorBox.sizex/2 - HeroBox.sizex/2 -speed;
					}
					else Jump = Jump_H;
				}
				
				if (event.key.keysym.sym == SDLK_RIGHT) {
					if ((CompareHitbox_X(HeroBox, FloorBox, speed) == 4) & (HeroBox.centrx < FloorBox.centrx)) {
						HeroBox.centrx = FloorBox.centrx - FloorBox.sizex/2 - HeroBox.sizex/2 -speed;
                                                //MvRight = 0;
                                        }
                                        else {  
                                                MvRight = 1;
						MvLeft = 0;
                                        }

				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					if ((CompareHitbox_X(HeroBox, FloorBox, speed) == 3) & (HeroBox.centrx > FloorBox.centrx)) {
						HeroBox.centrx = FloorBox.centrx + FloorBox.sizex/2 + HeroBox.sizex/2 +speed;
                                                //MvLeft = 0;
                                        }

                                        else {  
                                                MvLeft = 1;
						MvRight = 0;
                                        }

				}
			}
			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_LEFT) {
					MvLeft = 0;
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
                                        MvRight = 0;
                                }
			}
			//Jump
			if (Jump>0) {
                                if (Jump > 3*(Jump_H/4)) {
					HeroBox = Move(renderer, HeroBox, FloorBox, speed, 1);
					Jump -= 1;
				}	
				else if (Jump > Jump_H/2) {
					HeroBox = Move(renderer, HeroBox, FloorBox, 3*(speed/4), 1);
					Jump -= 1;
				}
				else if (Jump > Jump_H/4) {
					HeroBox = Move(renderer, HeroBox, FloorBox, 2*(speed/4), 1);
					Jump -= 1;
				}
				else {
                                	HeroBox = Move(renderer, HeroBox, FloorBox, 1*(speed/4), 1);
					Jump -=1;
				}
                        }

			if (CompareHitbox_Y(HeroBox, FloorBox, speed) != 1 & HeroBox.centry < 800 & Jump == 0) {
                       	        if (grav < Jump_H/4) {
                                        HeroBox = Move(renderer, HeroBox, FloorBox, speed/4, 2);
                                        grav += 1;
                                }
                                else if (grav < Jump_H/2) {
                                        HeroBox = Move(renderer, HeroBox, FloorBox, 2*(speed/4), 2);
                                        grav += 1;
                                }
                                else if (grav < (Jump_H/4)) {
                                        HeroBox = Move(renderer, HeroBox, FloorBox, 2*(speed/4), 2);
                                        grav += 1;
                                }
                                else {
                                        HeroBox = Move(renderer, HeroBox, FloorBox, 4*(speed/4), 2);
                                        grav +=1;
                                }

			}

			if (MvRight == 1 & CompareHitbox_X(HeroBox, FloorBox, speed) != 4) {
				HeroBox =  Move(renderer, HeroBox, FloorBox, speed, 3);
			}
			printf("Hitbox : %d, MvLeft : %d\n",CompareHitbox_X(HeroBox,FloorBox,speed), MvLeft);
			if (MvLeft == 1 & CompareHitbox_X(HeroBox, FloorBox, speed) != 3) {
				printf("debug");
				HeroBox = Move(renderer, HeroBox, FloorBox, speed, 4);
				printf("debug");
			}
			
			SDL_Delay(16);
			PrintHero(renderer, HeroBox, FloorBox, 0,255,255,255);
			//Collision(HeroBox, FloorBox, speed, CauseStop);
			SDL_PollEvent(&event);

		} while (MvLeft == 1 | MvRight == 1 | Jump > 0 | (CompareHitbox_Y(HeroBox, FloorBox, 10) != 1 & HeroBox.centry<(800)));
	}
        SDL_PollEvent(&event);
	MoveHeroReturn MHR;
	MHR.HeroBox = HeroBox;
	MHR.Jump = Jump;
	return MHR;

}
/*
Hitbox Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event) {
	if (event.type == SDL_KEYDOWN & event.key.keysym.sym == SDLK_SPACE) {
	
		if (jump_H != 0) {
			for (float i=0; i<jump_H; i+=0.1) {
                		HeroBox = Move(renderer, HeroBox, FloorBox, 10*cos(i), 1);
                		PrintHero(renderer, HeroBox, FloorBox, 0,255, 255, 255);
				SDL_Delay(16);
			}
			while (CompareHitbox_Y(HeroBox,FloorBox, speed) != 1 & HeroBox.centry < 768) {
				HeroBox = Move(renderer, HeroBox, FloorBox, 10, 2);
				Collision(HeroBox, FloorBox, speed, 1);
                                PrintHero(renderer, HeroBox, FloorBox, 0,255, 255, 255);
                                SDL_Delay(16);

			}
			SDL_PollEvent(&event);
         	}
	}
	return HeroBox;

}*/
