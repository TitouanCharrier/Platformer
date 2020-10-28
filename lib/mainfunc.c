#include "mainfunc.h"

CompareReturn CompareHitbox_X(Hitbox mobile, Hitbox statique[]) {
	CompareReturn final;
	for (int i=0; i<NBR_OBS; i++) {
		int mcx = mobile.centrx;
		int mcy = mobile.centry;
		int msx = mobile.sizex;
		int msy = mobile.sizey;
		int scx = statique[i].centrx;
		int scy = statique[i].centry;
		int ssx = statique[i].sizex;
		int ssy = statique[i].sizey;
	
		if ((mcx+msx/2+HERO_SPEED >= scx-ssx/2) & (mcx-msx/2-HERO_SPEED <= scx)) {
			if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2) | (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
				final.direction = 4;
				final.object = i;	
				return final;
			}
		}
	
		else if ((mcx+msx/2+HERO_SPEED >= scx) & (mcx-msx/2-HERO_SPEED <= scx+ssx/2)) {
	                if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2) | (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
				final.direction = 3;
				final.object = i;
	                	return final;
	       	        }
		}
	}
	final.direction = 0;
	final.object = NULL;
	return final;
}

CompareReturn CompareHitbox_Y(Hitbox mobile, Hitbox statique[]) {
        CompareReturn final;
	for (int i=0; i<NBR_OBS; i++) {
		int mcx = mobile.centrx;
	        int mcy = mobile.centry;
	        int msx = mobile.sizex;
	        int msy = mobile.sizey;
	        int scx = statique[i].centrx;
	        int scy = statique[i].centry;
	        int ssx = statique[i].sizex;
	        int ssy = statique[i].sizey;
	
	        if ((mcy+msy/2+HERO_SPEED >= scy-ssy/2) & (mcy-msy/2-HERO_SPEED <= scy)) {
	                if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2) | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) { 
	                        final.direction = 1;
				final.object = i;
				return final;
	                }
	        }
	
		else if ((mcy+msy/2+HERO_SPEED >= scy) & (mcy-msy/2-HERO_SPEED <= scy+ssy/2)) {
	                if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2) | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) {
	                        final.direction = 2;
				final.object = i;
				return final;
	                }
	        }
	
	}
	final.direction = 0;
	final.object = NULL;
	return final;
}

void PrintHero(SDL_Renderer *renderer,Hitbox HeroBox,Hitbox ListObstacle[], int r, int g, int b, int a) {
	//nettoyage
	SDL_RenderClear(renderer);
	//floor 
	/*for (int i=0; i<NBR_OBS; i++) {
		CreateRectangle(renderer,ListObstacle[i].centrx,ListObstacle[i].centry,ListObstacle[i].sizex+17,ListObstacle[i].sizey+17,ListObstacle[i].r,ListObstacle[i].g,ListObstacle[i].b,ListObstacle[i].a,ListObstacle[i].fill);  

	}*/

	SDL_Surface *mouton_i = SDL_LoadBMP("rsc/mouton.bmp");
        SDL_Texture *mouton_t = SDL_CreateTextureFromSurface(renderer, mouton_i);
	SDL_Rect ListRectMouton[NBR_OBS]; 

	//image
	SDL_Surface *image = SDL_LoadBMP("rsc/external-content.bmp");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_Rect RectangleImage= {HeroBox.centrx-HeroBox.sizex/2, HeroBox.centry-HeroBox.sizey/2,HeroBox.sizex,HeroBox.sizey};
	for (int i=0; i<NBR_OBS; i++) {
                SDL_Rect RectMouton = {ListObstacle[i].centrx-ListObstacle[i].sizex/2, ListObstacle[i].centry-ListObstacle[i].sizey/2,ListObstacle[i].sizex,ListObstacle[i].sizey};
                ListRectMouton[i] = RectMouton;
                SDL_RenderCopy(renderer, mouton_t, NULL, &ListRectMouton[i]);
        }
	
	SDL_RenderCopy(renderer, texture, NULL, &RectangleImage);
	//CreateRectangle(renderer,HeroBox.centrx, HeroBox.centry, HeroBox.sizex, HeroBox.sizey, r,g,b,a, 0);
	
	//affichage
	SDL_RenderPresent(renderer);
	//mise au noir
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);

	SDL_Delay(16/NBR_OBS);
        SDL_DestroyTexture(texture);
        SDL_DestroyTexture(mouton_t);
        SDL_FreeSurface(image);
        SDL_FreeSurface(mouton_i);

	
}

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction) {
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

Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[]) {
	int object = CompareHitbox_Y(HeroBox, ListObstacle).object;	
	if (CompareHitbox_Y(HeroBox, ListObstacle).direction == 1) {
		object = CompareHitbox_Y(HeroBox, ListObstacle).object;	
        	HeroBox.centry = ListObstacle[object].centry + ListObstacle[object].sizey/2 + HeroBox.sizey/2 +10;
               	return HeroBox;
	}
	if (CompareHitbox_Y(HeroBox, ListObstacle).direction == 2) {
		object = CompareHitbox_Y(HeroBox, ListObstacle).object;	
	        HeroBox.centry = ListObstacle[object].centry - ListObstacle[object].sizey/2 - HeroBox.sizey/2 -10;
	        return HeroBox;
	}
	if (CompareHitbox_X(HeroBox, ListObstacle).direction == 3) {
		object = CompareHitbox_Y(HeroBox, ListObstacle).object;	
	        HeroBox.centrx = ListObstacle[object].centrx - ListObstacle[object].sizex/2 - HeroBox.sizex/2 -10;
	        return HeroBox;
	}
	if (CompareHitbox_X(HeroBox, ListObstacle).direction == 4) {
		object = CompareHitbox_Y(HeroBox, ListObstacle).object;	
	        HeroBox.centrx = ListObstacle[object].centrx + ListObstacle[object].sizex/2 + HeroBox.sizex/2 +10;
	        return HeroBox;
	}
}

MoveHeroReturn MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[],int Jump_H, SDL_Event event) {
	float Jump = 0;
	int grav= 0;
	bool MvRight = 0;
	bool MvLeft = 0;
	bool ObsCount;
	if (event.type == SDL_KEYDOWN) {
		int direction = 0;
		do {
			if (event.type == SDL_KEYDOWN) {

				if (event.key.keysym.sym == SDLK_ESCAPE) break;

					
				if (event.key.keysym.sym == SDLK_SPACE & Jump == 0 & ((CompareHitbox_Y(HeroBox, ListObstacle).direction == 1) | (HeroBox.centry >= 768-HeroBox.sizey/2-50))) {

					Jump = Jump_H;
				}
					
				if (event.key.keysym.sym == SDLK_RIGHT) {
					if (CompareHitbox_X(HeroBox, ListObstacle).direction != 4) {
	                                	MvRight = 1;
						MvLeft = 0;
	                                }
	
				}
				if (event.key.keysym.sym == SDLK_LEFT) {
					if (CompareHitbox_X(HeroBox, ListObstacle).direction != 3) {
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
			if (Jump>0 & (CompareHitbox_Y(HeroBox,ListObstacle).object == NULL | CompareHitbox_Y(HeroBox,ListObstacle).direction != 2)) {
                                if (Jump > 3*(Jump_H/4)) {
					HeroBox = Move(renderer, HeroBox, JUMP_SPEED, 1);
					Jump -= 1;
				}	
				else if (Jump > Jump_H/2) {
					HeroBox = Move(renderer, HeroBox, 3*(JUMP_SPEED/4), 1);
					Jump -= 1;
				}
				else if (Jump > Jump_H/4) {
					HeroBox = Move(renderer, HeroBox, 2*(JUMP_SPEED/4), 1);
					Jump -= 1;
				}
				else {
                                	HeroBox = Move(renderer, HeroBox, 1*(JUMP_SPEED/4), 1);
					Jump -=1;
				}
                        }
			else Jump = 0;
			//gravity
			if (CompareHitbox_Y(HeroBox, ListObstacle).direction != 1 & HeroBox.centry < 768-HeroBox.sizey/2-20 & Jump == 0) {
	               	        if (grav < Jump_H/4) {
	                                HeroBox = Move(renderer, HeroBox, JUMP_SPEED/4, 2);
	                                grav += 1;
	                        }
	                        else if (grav < Jump_H/2) {
	                                HeroBox = Move(renderer, HeroBox, 2*(JUMP_SPEED/4), 2);
	                                grav += 1;
	                        }
	                        else if (grav < (Jump_H/4)) {
	                                HeroBox = Move(renderer, HeroBox, 2*(JUMP_SPEED/4), 2);
	                                grav += 1;
	                        }
	                        else {
	                                HeroBox = Move(renderer, HeroBox, 4*(JUMP_SPEED/4), 2);
	                                grav +=1;
	                        }

			}
	
			if (MvRight == 1 & CompareHitbox_X(HeroBox, ListObstacle).direction != 4) {
				HeroBox =  Move(renderer, HeroBox, HERO_SPEED, 3);
			}
			if (MvLeft == 1 & CompareHitbox_X(HeroBox, ListObstacle).direction != 3) {
				HeroBox = Move(renderer, HeroBox, HERO_SPEED, 4);
			}
			PrintHero(renderer, HeroBox, ListObstacle, 0,255,255,255);
	                SDL_PollEvent(&event);


		} while (MvLeft == 1 | MvRight == 1 | Jump > 0 | (CompareHitbox_Y(HeroBox, ListObstacle).direction !=1 & HeroBox.centry<(768-HeroBox.sizey/2-20)));
	}
        SDL_PollEvent(&event);
	MoveHeroReturn MHR;
	MHR.HeroBox = HeroBox;
	MHR.Jump = Jump;
	return MHR;

}
