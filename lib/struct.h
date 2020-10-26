typedef int bool;

typedef struct Hitbox {
	char type;
	int centrx;
	int centry;
	int sizex;
        int sizey;
}Hitbox;

typedef struct Rect {
	char type;
	int centrx;
	int centry;
	Hitbox Hitbox;
	int sizex;
	int sizey;
} Rect;

typedef struct MoveHeroArgs {
	SDL_Renderer *renderer;
	Hitbox HeroBox;
	Hitbox FloorBox;
	int speed;
	SDL_Event event;
}MoveHeroArgs;

typedef struct JumpArgs {
	SDL_Renderer *renderer;
	Hitbox HeroBox;
	Hitbox FloorBox;
	int jump_H;
	int speed;
	SDL_Event event;
}JumpArgs;
