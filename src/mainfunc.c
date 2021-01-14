#include "mainfunc.h"

//compare hitbox and a hitbox list
CompareReturn CompareHitbox(Hitbox mobile, Hitbox statique[]) {
	CompareReturn final;
	final.object = NULL;

	//generating direction list
	for (int i=0; i<5; i++) {
	        final.direction[i] = false;
        }

	for (int i=0; i<NBR_OBS; i++) {
		int mcx = mobile.centrx;
		int mcy = mobile.centry;
		int msx = mobile.sizex;
		int msy = mobile.sizey;
		int scx = statique[i].centrx;
		int scy = statique[i].centry;
		int ssx = statique[i].sizex;
		int ssy = statique[i].sizey;
			
		//West side collision
		if ((mcx+msx/2+1 >= scx-ssx/2) & (mcx-msx/2-1 <= scx)) {
			if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2)
			| (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
				final.direction[WEST] = true;
				final.object = i;	
			}
		}
		//East side collision
		if ((mcx+msx/2+1 >= scx) & (mcx-msx/2-1 <= scx+ssx/2)) {
	                if ((mcy+msy/2 <= scy+ssy/2 & mcy+msy/2 >= scy-ssy/2)
			| (mcy-msy/2 >= scy-ssy/2 & mcy-msy/2 <= scy+ssy/2)) {
				final.direction[EAST] = true;
				final.object = i;
	       	        }
		}
		//North side collision
		if ((mcy+msy/2+1 >= scy-ssy/2) & (mcy-msy/2-1 <= scy)) {
                        if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2)
                        | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) {
                                final.direction[NORTH] = true;
                                final.object = i;
                        }
                }
		//South side collision
                if ((mcy+msy/2+1 >= scy) & (mcy-msy/2-1 <= scy+ssy/2)) {
                        if ((mcx+msx/2 <= scx+ssx/2 & mcx+msx/2 >= scx-ssx/2)
                        | (mcx-msx/2 >= scx-ssx/2 & mcx-msx/2 <= scx+ssx/2)) {
                                final.direction[SOUTH] = true;
                                final.object = i;
                        }
                }

	}
	// return direction list and one object
	return final;
}

//Create a texture from image path (char list)
SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]) {
	SDL_Surface *buffer = SDL_LoadBMP(Image);
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(renderer, buffer);
	return Texture;
}

//print the scene
void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], SDL_Texture *ListTexture[]) {

	//clearing
	SDL_RenderClear(renderer);

	//print background
	SDL_RenderCopy(renderer, ListTexture[1], NULL, NULL);

	//print hitboxs
	CreateRectangle(renderer, HeroBox.centrx, HeroBox.centry, HeroBox.sizex, HeroBox.sizey, 255, 0, 0, 255, 0); 
	for (int i=0; i<NBR_OBS; i++) {
		CreateRectangle(renderer,
				ListObstacle[i].centrx,ListObstacle[i].centry,
				ListObstacle[i].sizex,ListObstacle[i].sizey,
				ListObstacle[i].r,ListObstacle[i].g,ListObstacle[i].b,
				ListObstacle[i].a,ListObstacle[i].fill);  
	}	
	//create Hero image
	SDL_Rect RectangleHero= {HeroBox.centrx-HeroBox.sizex/2, 
		HeroBox.centry-HeroBox.sizey/2,HeroBox.sizex,HeroBox.sizey};
	// create and add Obstacle to renderer
	SDL_Rect ListRectMouton[NBR_OBS]; 
	for (int i=0; i<NBR_OBS; i++) {
                SDL_Rect RectMouton = {ListObstacle[i].centrx-ListObstacle[i].sizex/2,
			ListObstacle[i].centry-ListObstacle[i].sizey/2,ListObstacle[i].sizex,ListObstacle[i].sizey};
                ListRectMouton[i] = RectMouton;
                SDL_RenderCopy(renderer, ListTexture[2], NULL, &ListRectMouton[i]);
        }
	
	//add Hero to renderer
	SDL_RenderCopy(renderer, ListTexture[0], NULL, &RectangleHero);
	//print hitbox when uncommented
	//CreateRectangle(renderer,HeroBox.centrx, HeroBox.centry, HeroBox.sizex, HeroBox.sizey, r,g,b,a, 0);
	
	//printing
	SDL_RenderPresent(renderer);
	
	//set to black
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	
	//wait
	SDL_Delay(16/NBR_OBS);

	
}

//move a subject 
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

//replace the Hero in terms of collisions
Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[]) {
	int objecty = CompareHitbox(HeroBox, ListObstacle).object;	
	int objectx = CompareHitbox(HeroBox, ListObstacle).object;	

	if (CompareHitbox(HeroBox, ListObstacle).direction[NORTH] == true) {
                HeroBox.centry = ListObstacle[objecty].centry - ListObstacle[objecty].sizey/2 - HeroBox.sizey/2 -1;
        }

	if (CompareHitbox(HeroBox, ListObstacle).direction[WEST] == true) {
                HeroBox.centrx = ListObstacle[objectx].centrx - ListObstacle[objectx].sizex/2 - HeroBox.sizex/2 +1;
        }
        if (CompareHitbox(HeroBox, ListObstacle).direction[EAST] == true) {
                HeroBox.centrx = ListObstacle[objectx].centrx + ListObstacle[objectx].sizex/2 + HeroBox.sizex/2 -1;
        }

	if (CompareHitbox(HeroBox, ListObstacle).direction[SOUTH] == true) {
        	HeroBox.centry = ListObstacle[objecty].centry + ListObstacle[objecty].sizey/2 + HeroBox.sizey/2 +1;
	}
	return HeroBox;
}

//main movement function for the charactere
Hitbox MoveHero(SDL_Renderer *renderer,
Hitbox HeroBox, Hitbox ListObstacle[],
SDL_Event event, SDL_Texture *ListTexture[]) {
	
	float Jump = 0;
	bool MvRight = 0;
	bool MvLeft = 0;

	//detect event type
	if (event.type == SDL_KEYDOWN) {
		int direction = 0;
		
		//continue to end of movement
		do {
			if (event.type == SDL_KEYDOWN) {
				
				//detecte close call
				if (event.key.keysym.sym == SDLK_ESCAPE) break;

				//detect jump call
				if (event.key.keysym.sym == SDLK_SPACE 
				& Jump == 0 
				& ((CompareHitbox(HeroBox, ListObstacle).direction[NORTH] == true) 
				| (HeroBox.centry >= SCREEN_HEIGHT-HeroBox.sizey/2-50))) {

					Jump = JUMP_HEIGHT;
				}

				//detect start arrow call
				if (event.key.keysym.sym == SDLK_RIGHT) {
	                                MvRight = 1;
					MvLeft = 0;
	                                	
				}
				else if (event.key.keysym.sym == SDLK_LEFT) {
	                                MvLeft = 1;
					MvRight = 0;
	
				}
			}
			
			//detect end arrow call
			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_LEFT) {
					MvLeft = 0;
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
                                        MvRight = 0;
                                }
			}

			//Jump run
			if (Jump>0 & (CompareHitbox(HeroBox,ListObstacle).object == NULL 
			| CompareHitbox(HeroBox,ListObstacle).direction[SOUTH] != true)) {
                                
				if (Jump > 3*(JUMP_HEIGHT/4)) {
					HeroBox = Move(renderer, HeroBox, 2*JUMP_SPEED, 1);
					Jump -= 1;
				}	
				else if (Jump > JUMP_HEIGHT/2) {
					HeroBox = Move(renderer, HeroBox, 6*(JUMP_SPEED/4), 1);
					Jump -= 1;
				}
				else if (Jump > JUMP_HEIGHT/4) {
					HeroBox = Move(renderer, HeroBox, 4*(JUMP_SPEED/4), 1);
					Jump -= 1;
				}
				else {
                                	HeroBox = Move(renderer, HeroBox, 2*(JUMP_SPEED/4), 1);
					Jump -=1;
				}
                        }
			else Jump = 0;

			//gravity
			if (CompareHitbox(HeroBox, ListObstacle).direction[NORTH] != true 
			& HeroBox.centry < SCREEN_HEIGHT-HeroBox.sizey/2-20 
			& Jump == 0) {
	               	        
				if (1==1) {
					for(int i=0; i<JUMP_SPEED; i++) {
                                        	if(CompareHitbox(HeroBox, ListObstacle).direction[NORTH] != true) {
                                                	HeroBox =  Move(renderer, HeroBox, 1, 2);
                                        	}
                                	}
	                        }

			}
			
			//Displacement
			if (MvRight == 1) {
				for(int i=0; i<HERO_SPEED; i++) {
					if(CompareHitbox(HeroBox, ListObstacle).direction[WEST] != true) { 
						HeroBox =  Move(renderer, HeroBox, 1, 3);
					}
				}
			}
			if (MvLeft == 1 ) {
				for(int i=0; i<HERO_SPEED; i++) {
                                        if(CompareHitbox(HeroBox, ListObstacle).direction[EAST] != true) { 
                                                HeroBox =  Move(renderer, HeroBox, 1, 4);         
                                        }
                                }            

			}
			//other methode to fix collision
			//HeroBox = Collision(HeroBox, ListObstacle);
			
			//print the scene
			PrintHero(renderer, HeroBox, ListObstacle, ListTexture);

			//detect event
	                SDL_PollEvent(&event);


		} while (MvLeft == 1 | MvRight == 1 | Jump > 0 
		| (CompareHitbox(HeroBox, ListObstacle).direction[NORTH] != true 
		& HeroBox.centry<(SCREEN_HEIGHT-HeroBox.sizey/2-20)));
	}
        SDL_PollEvent(&event);
	return HeroBox;

}
void Play_menu() {
TTF_Font * Sans = TTF_OpenFont("/usr/share/fonts/liberation/LiberationMono-Regular.ttf",256);
    //init menu window and renderer
    SDL_Renderer *R_menu = NULL;
    SDL_Window *W_menu = NULL;

	//set menu windw and renderer
    W_menu = SDL_CreateWindow("Titre",SCREEN_WIDTH/2-125,SCREEN_HEIGHT/2-250,250,500,0);
    R_menu = SDL_CreateRenderer(W_menu,-1,SDL_RENDERER_ACCELERATED);


    //menu loop
    //int menu_run = 1;
    SDL_Color white = {255,255,255};
    //while (menu_run !=0) {
    CreateRectangle(R_menu,125,125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,125+125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,2*125+125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,3*125+125/2,250,125,255,88,0,255,0);
    SDL_Surface *Choix_1 = TTF_RenderText_Solid(Sans,"1920 x 1080", white);
    SDL_Texture * T_Choix_1 = SDL_CreateTextureFromSurface(R_menu,Choix_1);
    SDL_Rect Rect_Choix_1;
    Rect_Choix_1.x = 10;
    Rect_Choix_1.y = 25;
    Rect_Choix_1.w = 230;
    Rect_Choix_1.h = 75;
    SDL_RenderCopy(R_menu,T_Choix_1,NULL,&Rect_Choix_1);
    SDL_RenderPresent(R_menu);
    SDL_Delay(10000);
}