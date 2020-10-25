#include "geometrie_SDL2.h"

int CompareHitbox_X(Hitbox mobile, Hitbox statique);

int CompareHitbox_Y(Hitbox mobile, Hitbox statique);

void PrintHero(SDL_Renderer *renderer, Hitbox, int, int, int, int);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox,int speed, SDL_Event event);

Hitbox Jump(SDL_Renderer *renderer, Hitbox HeroBox, Hitbox FloorBox, int jump_H, SDL_Event event);
