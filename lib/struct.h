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
