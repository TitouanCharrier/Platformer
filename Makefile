main : main.c lib/geometrie_SDL2.c src/mainfunc.c src/settings.h src/Bank.c src/BankTexture.c
	gcc -c lib/geometrie_SDL2.c -lSDL2 -lm	-o geometrie.o
	gcc -c src/Bank.c -lSDL2 -lm -o Bank.o
	gcc -c src/BankTexture.c -o BankTexture.o 
	#gcc -c lib/SDL2_menu.c -lSDL2 -lSDL2_ttf -o menu.o
	gcc -c src/mainfunc.c -lSDL2 -lm -lSDL2_ttf -o mainfunc.o
	gcc main.c -o main geometrie.o mainfunc.o Bank.o BankTexture.o -lSDL2 -lSDL2_ttf -lm -Wall
	rm geometrie.o mainfunc.o BankTexture.o Bank.o
	./main
	
