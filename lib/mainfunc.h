#include "geometrie_SDL2.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique, int speed);

int CompareHitbox_Y(Hitbox mobile, Hitbox statique, int speed);

void PrintHero(SDL_Renderer *renderer, Hitbox, Hitbox, int, int, int, int);

Hitbox Collision(Hitbox, Hitbox,int speed, int CauseStop);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, Hitbox, int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event);

Hitbox Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event, float);

Hitbox Gravity(SDL_Renderer *renderer, Hitbox, Hitbox, int);
