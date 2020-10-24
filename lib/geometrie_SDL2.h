#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

#include "struct.h"

#define pi 3.14159265358979323846264338379
#define False 0
#define True 1

int RegulHollowPoly(SDL_Renderer *renderer,int nbrCote,int tailleCote,int centrx,int centry, int facing, int r,int g,int b,int a);

int RegulPoly(SDL_Renderer *renderer,int nbrCote,int tailleCote,int centrx,int centry, int facing, int r,int g,int b,int a, bool hollow );

void CreateCircle(SDL_Renderer *renderer, int centrx, int centry, int ray, int r, int g, int b, int a);

void CreateRectangle(SDL_Renderer *renderer, int centrx, int centry, int sizex, int sizey, int r, int g, int b, int a, bool fill);

