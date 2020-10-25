#include "geometrie_SDL2.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique, int speed);

int CompareHitbox_Y(Hitbox mobile, Hitbox statique, int speed);

void PrintHero(SDL_Renderer *renderer, Hitbox HeroBox, int, int, int, int);

Hitbox Collision(Hitbox, Hitbox HeroBox,int speed, int CauseStop);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, int speed, int direction);

void MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox,int speed, SDL_Event event);

void Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event);
