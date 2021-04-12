#include "mainfunc.h"
#define pi 3.14159265358979323846264338379
//compare hitbox and a hitbox list
CompareReturn CompareHitbox(Hitbox **ListObjects) {
	CompareReturn final;
	final.object = NULL;

	//generating direction list
	for (int i=0; i<5; i++) {
	        final.direction[i] = false;
        }
    for (int j=2; j< NBR_OBJ;j++) {
        for (int i=0; i<ListObjects[j][0].LengthList; i++) {
            int mcx = ListObjects[0][0].centrx;
            int mcy = ListObjects[0][0].centry;
            int msx = ListObjects[0][0].sizex;
            int msy = ListObjects[0][0].sizey;
            int scx = ListObjects[j][i].centrx;
            int scy = ListObjects[j][i].centry;
            int ssx = ListObjects[j][i].sizex;
            int ssy = ListObjects[j][i].sizey;

            //West side collision
            if ((mcx+msx/2+1 >= scx-ssx/2 && mcx-msx/2-1 <= scx)
            || (mcx >= scx-ssx/2 && mcx <= scx))  {
                if ((mcy+msy/2 <= scy+ssy/2 && mcy+msy/2 >= scy-ssy/2)
                || (mcy-msy/2 >= scy-ssy/2 && mcy-msy/2 <= scy+ssy/2)
                || (mcy >= scy-ssy/2 && mcy <= scy+ssy/2)) {
                    final.direction[WEST] = true;
                    final.object = i;
                }
            }
            //East side collision
            if ((mcx+msx/2+1 >= scx) && (mcx-msx/2-1 <= scx+ssx/2)
            || (mcx >= scx && mcx <= scx+ssx/2)) {
                if ((mcy+msy/2 <= scy+ssy/2 && mcy+msy/2 >= scy-ssy/2)
                || (mcy-msy/2 >= scy-ssy/2 && mcy-msy/2 <= scy+ssy/2)
                || (mcy >= scy-ssy/2 && mcy <= scy+ssy/2)) {
                    final.direction[EAST] = true;
                    final.object = i;
                        }
            }
            //North side collision
            if ((mcy+msy/2+1 >= scy-ssy/2) && (mcy-msy/2-1 <= scy)) {
                            if ((mcx+msx/2 <= scx+ssx/2 && mcx+msx/2 >= scx-ssx/2)
                            || (mcx-msx/2 >= scx-ssx/2 && mcx-msx/2 <= scx+ssx/2)) {
                                    final.direction[NORTH] = true;
                                    final.object = i;
                            }
                    }
            //South side collision
                    if ((mcy+msy/2+1 >= scy) && (mcy-msy/2-1 <= scy+ssy/2)) {
                            if ((mcx+msx/2 <= scx+ssx/2 && mcx+msx/2 >= scx-ssx/2)
                            || (mcx-msx/2 >= scx-ssx/2 && mcx-msx/2 <= scx+ssx/2)) {
                                    final.direction[SOUTH] = true;
                                    final.object = i;
                            }
                    }
            }

        }
	// return direction list and one object
	return final;
}

//print the scene
void PrintHero(SDL_Renderer *renderer, Hitbox **ListObjects, SDL_Texture ***ListTexture, Increment *Incr) {

	//clearing
	SDL_RenderClear(renderer);

	//print background
	SDL_RenderCopy(renderer, ListTexture[1][1], NULL, NULL);

	//create Hero image
	SDL_Rect RectangleHero= {ListObjects[0][0].centrx-50,
		ListObjects[0][0].centry-90,100,150};
    /*printf("%d\n", ListObjects[0][0].centry);
    printf("%d\n", ListObjects[0][0].centrx);
    printf("%d\n", ListObjects[0][0].sizey);
    printf("%d\n", ListObjects[0][0].sizex);
    */
    //create Aura image
	SDL_Rect RectangleAura= {ListObjects[0][0].centrx-250,
		ListObjects[0][0].centry-250,500,500};

    //add aura to renderer
    SDL_RenderCopy(renderer, ListTexture[6][0], NULL, &RectangleAura);

	// create and add Obstacle to renderer
	SDL_Rect ListRectObstacle[NBR_OBS];

	//add Wood
    
	for (int i=0; i<NBR_WOOD; i++) {
        SDL_Rect RectObstacle = {ListObjects[2][i].centrx-ListObjects[2][i].sizex/2,
        ListObjects[2][i].centry-ListObjects[2][i].sizey/2,ListObjects[2][i].sizex,ListObjects[2][i].sizey};
        ListRectObstacle[i] = RectObstacle;
        SDL_RenderCopy(renderer, ListTexture[2][0], NULL, &ListRectObstacle[i]);
    }
    //add hero
    SDL_RendererFlip FlipNone = SDL_FLIP_NONE;
    SDL_RendererFlip FlipHor = SDL_FLIP_HORIZONTAL;
    switch (Incr->StateHero) {
        case 0 :
            SDL_RenderCopy(renderer, ListTexture[5][(Incr->Hero/2)%19], NULL, &RectangleHero);
            break;
        case 3 :
            SDL_RenderCopyEx(renderer, ListTexture[0][(Incr->Hero/2)%19], NULL, &RectangleHero,0,NULL,FlipNone);
            break;
        case 4 :
            SDL_RenderCopyEx(renderer, ListTexture[0][(Incr->Hero/2)%19], NULL, &RectangleHero,0,NULL,FlipHor);
            break;
        case 1 :
            if (Incr->Hero/2 < 40) {
                SDL_RenderCopy(renderer, ListTexture[4][Incr->Hero/2], NULL, &RectangleHero);
                break;
            }
            else {
                SDL_RenderCopy(renderer, ListTexture[4][39], NULL, &RectangleHero);
                Incr->StateHero = 0;
                break;
            }
        case 5 :
            if (Incr->Hero/3 < 20) {
                SDL_RenderCopyEx(renderer, ListTexture[7][Incr->Hero/3], NULL, &RectangleHero,0,NULL,FlipNone);
                break;
            }
            else {
                SDL_RenderCopyEx(renderer, ListTexture[7][19], NULL, &RectangleHero,0,NULL,FlipNone);
                Incr->StateHero = 0;
                break;
            }
        case 6 :
            if (Incr->Hero/3 < 20) {
                SDL_RenderCopyEx(renderer, ListTexture[7][Incr->Hero/3], NULL, &RectangleHero,0,NULL,FlipHor);
                break;
            }
            else {
                SDL_RenderCopyEx(renderer, ListTexture[7][19], NULL, &RectangleHero,0,NULL,FlipHor);
                Incr->StateHero = 0;
                break;
            }

    }
    //add Herbe only
    for (int i=0; i<NBR_GRASS; i++) {
        SDL_Rect RectObstacle = {ListObjects[3][i].centrx-ListObjects[3][i].sizex/2,
        (ListObjects[3][i].centry-ListObjects[3][i].sizey/2)-40,ListObjects[3][i].sizex,ListObjects[3][i].sizey};
        ListRectObstacle[i] = RectObstacle;
        SDL_RenderCopy(renderer, ListTexture[3][(Incr->Herbe/3)%41], NULL, &ListRectObstacle[i]);
    }

    /*print hitboxs
	for (int i=0; i<1; i++) {
        for (int j=0; j<1; j++) {
	Rectangle(renderer,
		ListObjects[i][j].centrx,ListObjects[i][j].centry,
		ListObjects[i][j].sizex,ListObjects[i][j].sizey,(-pi/4),
		ListObjects[i][j].r,ListObjects[i][j].g,ListObjects[i][j].b,
		ListObjects[i][j].a);

        }
	}*/
    
	//printing
	SDL_RenderPresent(renderer);

	//set to black
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);

	//wait
	SDL_Delay(10);


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

//main movement function for the charactere
Hitbox MoveHero(SDL_Renderer *renderer,
	Hitbox **ListObjects,
	SDL_Event event, SDL_Texture ***ListTexture,
	int RESX, int RESY, Increment *Incr) {

	int Jump_call = 0;
	int MvRight = 0;
	int MvLeft = 0;
	float grav = 1;
	float jump = JUMP_HEIGHT;

	//detect event type
	if (event.type == SDL_KEYDOWN) {

		//continue to end of movement
		do {
			if (event.type == SDL_KEYDOWN) {

				//detect exit call
				if (event.key.keysym.sym == SDLK_ESCAPE) break;

				//detect jump call
				if (event.key.keysym.sym == SDLK_SPACE
				&& Jump_call == 0
				&& ((CompareHitbox(ListObjects).direction[NORTH] == true)
				|| (ListObjects[0][0].centry >= RESY-ListObjects[0][0].sizey/2-20))) {

					Jump_call = 1;
					Incr->Hero = 0;

				}

				//detect start arrow call
				if (event.key.keysym.sym == SDLK_RIGHT) {
	                MvRight = 1;
					MvLeft = 0;
					Incr->StateHero = 3;

				}
				else if (event.key.keysym.sym == SDLK_LEFT) {
	                MvLeft = 1;
					MvRight = 0;
					Incr->StateHero = 4;

				}
			}

			//detect end arrow call
			if (event.type == SDL_KEYUP) {
				if (event.key.keysym.sym == SDLK_LEFT) {
					MvLeft = 0;
					if (Incr->StateHero != 1) {
                        Incr->StateHero = 0;
					}
				}
				if (event.key.keysym.sym == SDLK_RIGHT) {
                    MvRight = 0;
                    if (Incr->StateHero != 1) {
                        Incr->StateHero = 0;
                    }
                }
			}

			//Jump run
			if (Jump_call == 1) {
				jump -= 1;
				for(int i=0; i<pow(jump/7,2); i++) {
					if (CompareHitbox(ListObjects).direction[SOUTH] != true
					&& jump>0 ) {
            	        ListObjects[0][0] =  Move(renderer, ListObjects[0][0], 1, NORTH);
            	    }
            	    else {
                        Jump_call = 0;
            	    }

				}
			} else jump = JUMP_HEIGHT;

            //gravity
			if (CompareHitbox(ListObjects).direction[NORTH] != true) {
				if (grav <= JUMP_HEIGHT) grav ++;

				for(int i=0; i<pow(grav/7,2); i++) {
					if (CompareHitbox(ListObjects).direction[NORTH] != true
					&& ListObjects[0][0].centry < RESY-ListObjects[0][0].sizey/2-20
					&& Jump_call == 0) {
            	        ListObjects[0][0] =  Move(renderer, ListObjects[0][0], 1, SOUTH);
            	    } else grav = 1;
				}
			} else grav = 1;



			//Displacement
			for(int j=0; j<HERO_SPEED; j++) {

				if (MvRight == 1 && CompareHitbox(ListObjects).direction[WEST] != true) {

				// borders motion right
					if (ListObjects[0][0].centrx > RESX-RESX/3) {
						for (int j=2; j<NBR_OBJ; j++) {
                            for (int i=0; i<ListObjects[j][0].LengthList; i++) {
                                ListObjects[j][i].centrx -= 1;
                            }
                        }
                    }


                else {
						//hero motion right
						ListObjects[0][0] =  Move(renderer, ListObjects[0][0], 1, EAST);
					}
				}

				if (MvLeft == 1 && CompareHitbox(ListObjects).direction[EAST] != true) {

					//borders motion left
					if (ListObjects[0][0].centrx < RESX/3) {
						for (int j=2; j<NBR_OBJ; j++) {
                            for (int i=0; i<ListObjects[j][0].LengthList; i++) {
                                ListObjects[j][i].centrx += 1;
                            }
                        }
                    }

					else {
						//hero motion left
                	    ListObjects[0][0] =  Move(renderer, ListObjects[0][0], 1, WEST);
                	}
                }

			}
            if (Jump_call == 1 && Incr->StateHero == 3) Incr->StateHero = 5;
            else if (Jump_call == 1 && Incr->StateHero == 4) Incr->StateHero = 6;
            else if (Jump_call == 1 && Incr->StateHero == 0) Incr->StateHero = 1;
            else if (MvRight == 1 && Incr->StateHero == 0) Incr->StateHero = 3;
            else if (MvLeft == 1 && Incr->StateHero == 0) Incr->StateHero = 4;
			//other methode to fix collision
			//ListObjects[0][0] = Collision(ListObjects[0][0], ListObjects, MvLeft, MvRight);

			//print the scene
			PrintHero(renderer,ListObjects, ListTexture, Incr);
			Incr->Herbe += 1;
			Incr->Hero+=1;
			//detect event
	        SDL_PollEvent(&event);


		} while (MvLeft == 1 || MvRight == 1 || jump == 1
		|| (CompareHitbox(ListObjects).direction[NORTH] != true
		&& ListObjects[0][0].centry<(RESY-ListObjects[0][0].sizey/2-20)));
	}
        SDL_PollEvent(&event);
	return ListObjects[0][0];

}

/*SDL_Texture *Print_Text(SDL_Renderer *renderer, char text[],int x, int y, int w, int h,TTF_Font *font) {
	SDL_Rect Rect;
	SDL_Color Orange = {255,255,255};
    SDL_Surface *Choix_1 = TTF_RenderText_Blended(font,text, Orange);
    SDL_Texture * T_Choix_1 = SDL_CreateTextureFromSurface(renderer,Choix_1);
    Rect.x = x;
    Rect.y = y;
    Rect.w = w;
   	Rect.h = h;
    SDL_RenderCopy(renderer,T_Choix_1,NULL,&&Rect);
    SDL_RenderPresent(renderer);
    return T_Choix_1;
}*/

//Detect screen resolution
Couple Get_Res() {
	SDL_DisplayMode screen;
	SDL_GetCurrentDisplayMode(0,&screen);
	Couple retour;
	retour.RESX = screen.w;
	retour.RESY = screen.h;
	return retour;
}
