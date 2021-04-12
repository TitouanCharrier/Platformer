#ifndef _MAINFUNC_H
#define _MAINFUNC_H

#include "../lib/geometrie_SDL2.h"
#include "settings.h"
#include "Bank.h"
//#include <SDL2/SDL_ttf.h>
#include <time.h>

CompareReturn CompareHitbox(Hitbox **ListObjects);

SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]);

void PrintHero(SDL_Renderer *renderer, Hitbox **ListObjects, SDL_Texture ***ListTexture, Increment *Incr);

Hitbox Collision(Hitbox **ListObjects, int, int);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox **ListObjects, SDL_Event event, SDL_Texture ***ListTexture,int RESX, int RESY, Increment *Incr);

Hitbox **LoadObjects(int WIDTH, int HEIGHT);

//Couple Play_menu();

//SDL_Texture *Print_Text(SDL_Renderer *renderer, char text[],int x, int y, int w, int h,TTF_Font *font);

Couple Get_Res();

SDL_Texture **LoadOneTexture(SDL_Renderer *renderer, char file[], int NumberFrames);

SDL_Texture ***LoadTexture(SDL_Renderer *renderer);

//Bank.h

Hitbox **LoadObjects(int WIDTH, int HEIGHT);

Hitbox **LoadMap(int WIDTH, int HEIGHT, char *file_map, int NBR_Types);

#endif
