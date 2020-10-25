Mainmake : main.c
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o lib/objets/geometrie.o
	gcc -c lib/mainfunc.c -lSDL2 -lm	-o lib/objets/mainfunc.o
	gcc main.c -o main lib/objets/geometrie.o lib/objets/mainfunc.o -lSDL2 -lm -lpthread
	./main
