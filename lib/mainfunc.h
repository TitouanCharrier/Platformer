#include "geometrie_SDL2.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique, int speed);

int CompareHitbox_Y(Hitbox mobile, Hitbox statique, int speed);

void PrintHero(SDL_Renderer *renderer, Hitbox, int, int, int, int);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox Floorbox,int speed, SDL_Event event);
