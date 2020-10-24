#include "geometrie_SDL2.h"

int CompareHitbox(Hitbox mobile, Hitbox statique);

void PrintHero(SDL_Renderer *renderer, Hitbox, int, int, int, int);

Hitbox Move(SDL_Renderer *renderer,Hitbox subject, int speed, int direction);

Hitbox MoveHero(SDL_Renderer *renderer, Hitbox HeroBox, SDL_Event event);
