typedef int bool;

typedef struct Hitbox {
	char type;
	int centrx;
	int centry;
	int sizex;
        int sizey;
}Hitbox;

typedef struct Mouvement {
	Hitbox subject;
	SDL_Event event;
} Mouvement;

