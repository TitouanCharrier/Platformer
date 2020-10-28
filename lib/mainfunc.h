#include "geometrie_SDL2.h"
#include "parametres.h"

CompareReturn CompareHitbox_X(Hitbox mobile, Hitbox statique[]);

CompareReturn CompareHitbox_Y(Hitbox mobile, Hitbox statique[]);

void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[], int, int, int, int);

Hitbox Collision(Hitbox HeroBox, Hitbox ListObstacle[]);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject,int speed, int direction);

MoveHeroReturn MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox ListObstacle[],int Jump_H, SDL_Event event);

