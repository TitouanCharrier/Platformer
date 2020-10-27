#include "geometrie_SDL2.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique, int speed);

int CompareHitbox_Y(Hitbox mobile, Hitbox statique, int speed);

void PrintHero(SDL_Renderer *renderer, Hitbox, Hitbox, int, int, int, int);

Hitbox Collision(Hitbox, Hitbox,int speed);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, Hitbox, int speed, int direction);

MoveHeroReturn MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox,int Jump_H, int speed, SDL_Event event);

Hitbox Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, int speed, SDL_Event event);
