typedef int bool;

typedef struct Hitbox {
	SDL_Renderer *renderer;
	int centrx;
	int centry;
	int sizex;
        int sizey;
	int r;
	int g;
	int b;
	int a;
	bool fill;
}Hitbox;

typedef struct Rect {
	char type;
	int centrx;
	int centry;
	Hitbox Hitbox;
	int sizex;
	int sizey;
} Rect;
