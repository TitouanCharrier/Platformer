#ifndef _STRUCT_H
#define _STRUCT_H

typedef int bool;

typedef struct Hitbox {
	int T_ID;
	int R_ID;
	SDL_Renderer *renderer;
	float centrx;
	float centry;
	float sizex;
    float sizey;
	int r;
	int g;
	int b;
	int a;
	bool fill;
	int LengthList;
}Hitbox;

typedef struct Rect {
	char type;
	int centrx;
	int centry;
	Hitbox Hitbox;
	int sizex;
	int sizey;
} Rect;

typedef struct MoveHeroReturn {
	Hitbox HeroBox;
	float Jump;
} MoveHeroReturn;

typedef struct CompareReturn {
	int direction[5];
	int object;
}CompareReturn;

typedef struct Couple {
	int RESX;
	int RESY;
}Couple;

typedef struct BorderReturn {
	int right;
	int left;
	int up;
	int down;
}BorderReturn;

typedef struct Increment {
	int Herbe;
	int Hero;
	int StateHero;
}Increment;

#endif
