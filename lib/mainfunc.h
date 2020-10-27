#include "geometrie_SDL2.h"
#include "parametres.h"

CompareReturn CompareHitbox_X(Hitbox mobile, Hitbox statique[], int speed);

CompareReturn CompareHitbox_Y(Hitbox mobile, Hitbox statique[], int speed);

void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], int, int, int, int);

Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[],int speed);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction);

MoveHeroReturn MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[],int Jump_H, int speed, SDL_Event event);

Hitbox Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], int jump_H, int speed, SDL_Event event);
