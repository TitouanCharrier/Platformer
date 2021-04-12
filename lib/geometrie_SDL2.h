#ifndef _GEOMETRIE_SDL2_H
#define _GEOMETRIE_SDL2_H

#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include "../src/struct.h"
#define pi 3.14159265358979323846264338379
#define ECHAP 1
#define ESPACE 2
#define T_Z 3
#define T_Q 4
#define T_S 5
#define T_D 6

int RegulHollowPoly(SDL_Renderer *renderer, int nbrCote, int tailleCote, int centrx, int centry, int facing, int r, int g, int b, int a);

int RegulPoly(SDL_Renderer *renderer, int nbrCote, int tailleCote, int centrx, int centry, int facing, int r, int g, int b, int a, bool hollow );

void CreateCircle(SDL_Renderer *renderer, int centrx, int centry, int ray, int r, int g, int b, int a);

int CreateRectangle(SDL_Renderer *renderer, int centrx, int centry, int sizex, int sizey, int r, int g, int b, int a, bool fill);

void Rectangle(SDL_Renderer *renderer,int centrx, int centry, int sizex, int sizey, float rot, int r, int g, int b, int a);

void Polygone(SDL_Renderer *renderer,int centrx, int centry, int rayon, int cote, float rot, int r, int g, int b, int a);

void Circle(SDL_Renderer *renderer, int centrx, int centry, int rayon, int r, int g, int b, int a);

int Detect_KeyDown(SDL_Event event, int touche);

#endif
