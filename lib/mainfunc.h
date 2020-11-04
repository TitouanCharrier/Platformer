#include "geometrie_SDL2.h"
#include "parametres.h"

CompareReturn CompareHitbox(Hitbox mobile, Hitbox statique[]);

SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]);

void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], SDL_Texture *ListTexture[]);

Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[]);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], SDL_Event event, SDL_Texture *ListTexture[]);

