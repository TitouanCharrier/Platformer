main : main.c lib/geometrie_SDL2.c src/mainfunc.c src/settings.h
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o geometrie.o
	gcc -c lib/SDL2_menu.c -lSDL2 -lSDL2_ttf -o menu.o
	gcc -c src/mainfunc.c -lSDL2 -lm -lSDL2_ttf -o mainfunc.o
	gcc main.c -o main geometrie.o mainfunc.o menu.o -lSDL2 -lSDL2_ttf -lm -Wall
	rm geometrie.o mainfunc.o menu.o
	./main
window : main.c
	x86_64-w64-mingw32-gcc -c lib/geometrie_SDL2.c -lm -I/usr/x86_64-w64-mingw32/include/SDL2 -L/usr/x86_64-w64-mingw32 */*.c *.c
	x86_64-w64-mingw32-gcc -c src/mainfunc.c -lm -I/usr/x86_64-w64-mingw32/include/SDL2 -L/usr/x86_64-w64-mingw32 */*.c *.c
	x86_64-w64-mingw32-gcc -o Coucou.exe main.c mainfunc.o geometrie_SDL2.o -municode -I/usr/x86_64-w64-mingw32/include/SDL2/ -lm -L/usr/x86_64-w64-mingw32 */*.c *.c
	
