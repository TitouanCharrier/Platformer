#include "lib/mainfunc.h"
#include <pthread.h>

#define SCR_W 1920
#define SCR_H 1080
#define pi 3.14159265358979323846264338379
#define False 0
#define True 1
#define SPEED 10
#define JUMP_H

int main() {

	//initiatilsation SDL2
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Renderer *renderer = NULL;
	SDL_Renderer *renderbg = NULL;
	SDL_Window *window = NULL;

	//définition de la fenètre et du renderer
	window = SDL_CreateWindow("name",0,0,SCR_W,SCR_H,SDL_RENDERER_ACCELERATED);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	//création des listes de hitbox
	Hitbox ListBoxMv[5];
	Hitbox ListBoxSt[10];

	//création de la variable événement
	SDL_Event event;

	//Variable d'éxecution	
	bool run = 1;
	
	//mise au noir de l'écran
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderPresent(renderer);
	
	//définition du carré qui fait office de personnage
 	Hitbox HeroBox;
	HeroBox.centrx = SCR_W/4;
	HeroBox.centry = SCR_H/2;
	HeroBox.sizex = 25;
	HeroBox.sizey = 50;
	
	//définition de la Hitbox de l'obstacle (oui ca ne ressemble pas a un sol)
	Hitbox FloorBox;
	FloorBox.centrx = SCR_W/2;
	FloorBox.centry = SCR_H/2;
	FloorBox.sizex = 100;
	FloorBox.sizey = 100;
	
	//struct servant a faire passer les arguments de la fontion MoveHero Dans le Thread 1
	MoveHeroArgs MoveHero_args;
	MoveHero_args.renderer = renderer;
	MoveHero_args.HeroBox = HeroBox;
	MoveHero_args.speed = SPEED;
	MoveHero_args.FloorBox = FloorBox;
	
	//pointeur vers le struct précédant
	MoveHeroArgs *p_MoveHero_args = &MoveHero_args;
	
	//struct servant a faire passer les arguments de la fonction Jump dans le Thread 2
	JumpArgs Jump_args;
	Jump_args.jump_H = 10;
	Jump_args.HeroBox = HeroBox;
	Jump_args.renderer = renderer;
	Jump_args.speed = SPEED;
	Jump_args.FloorBox = FloorBox;
	
	//pointeur vers le dernier struct
	JumpArgs *p_Jump_args = &Jump_args;
	
	//boucle principale	
	while (run) {
		while (SDL_PollEvent(&event)) {
			
			//ajout des derniers éléments aux structs d'arguments
			MoveHero_args.event = event;
			Jump_args.event = event;
			
			//définition du nombre de threads
			pthread_t threads[2];
			//creation des threads et lancement des fonction 
			pthread_create(&threads[0], NULL, ThreadMoveHero , p_MoveHero_args);
			pthread_create(&threads[1], NULL, ThreadJump, p_Jump_args);
			
			//attender la fin des Threads
			pthread_join(threads[0], NULL);
			pthread_join(threads[1], NULL);

			//détection de la touche échape pour fermer
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				run = 0;
			}
			
			//créer le rectangle Obstacle dont on a modifier la position grâce aux fonctions dans les Threads
			CreateRectangle(renderer, SCR_W/2, SCR_H/2, 100, 100, 0, 255, 0, 255, 1);
			
			//mettre a jour le renderer
			SDL_RenderPresent(renderer);
			
			//redéfinir le fond en noir
			SDL_SetRenderDrawColor(renderer, 0,0,0,0);	

			//attendre (16 ms environ = à 60fps);
			SDL_Delay(16);
		}
	//idem pour pas consommer trop de processeur
	SDL_Delay(16);
	}	
	//on ferme SDL
	SDL_Quit();
	pthread_exit(NULL);
	
}


