main : main.c lib/geometrie_SDL2.c lib/mainfunc.c lib/parametres.h
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o geometrie.o
	gcc -c lib/mainfunc.c -lSDL2 -lm	-o mainfunc.o
	gcc main.c -o main geometrie.o mainfunc.o -lSDL2 -lm
	rm geometrie.o mainfunc.o
	./main
window : main.c
	x86_64-w64-mingw32-gcc main.c -o window.exe -I/usr/x86_64-w64-mingw32/include/SDL2 -lm -L/usr/x86_64-w64-mingw32 */*.c *.c
	echo "hello"
