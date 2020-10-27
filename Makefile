Mainmake : main.c
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o objects_files/geometrie.o
	gcc -c lib/mainfunc.c -lSDL2 -lm	-o objects_files/mainfunc.o
	gcc main.c -o main objects_files/geometrie.o objects_files/mainfunc.o -lSDL2 -lm
	./main
