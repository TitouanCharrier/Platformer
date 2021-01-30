#include "../lib/geometrie_SDL2.h"
#include "settings.h"
//#include <SDL2/SDL_ttf.h>
#include <time.h>

CompareReturn CompareHitbox(Hitbox mobile, Hitbox statique[]);

SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]);

void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], SDL_Texture *ListTexture[]);

Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[], int, int);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], SDL_Event event, SDL_Texture *ListTexture[],int RESX, int RESY);

//Couple Play_menu();

//SDL_Texture *Print_Text(SDL_Renderer *renderer, char text[],int x, int y, int w, int h,TTF_Font *font);

Couple Get_Res();
