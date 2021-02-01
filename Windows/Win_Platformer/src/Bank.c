#include "mainfunc.h"

Hitbox **LoadObjects(int WIDTH, int HEIGHT) {

    int NumberHero = 1;
    int NumberGrass = 100;
    int NumberWood = 400;
    int NumberFond = 1;
    int Total = NumberWood+NumberHero+NumberGrass+NumberFond;


    Hitbox **ListObjects = malloc(Total * sizeof(Hitbox));

    //Hero is a Hitbox, type defined in src/struct.h
    //ad a case to the main list :
    // HeroBox_Id_0;
    Hitbox *ListHero = malloc(sizeof(Hitbox));
    ListHero[0].centrx = WIDTH/4;
    ListHero[0].centry = HEIGHT/2;
    ListHero[0].sizex = 447/9;
    ListHero[0].sizey = 827/9;
    ListHero[0].LengthList = 1;
    ListObjects[0] = ListHero;

    //FondBox_Id_1

    Hitbox *ListFond = malloc(2*sizeof(Hitbox));
    ListFond[0].centrx = WIDTH/2;
    ListFond[0].centry = HEIGHT/6;
    ListFond[0].sizex = 1920*5;
    ListFond[0].sizey = 2080;
    ListFond[0].LengthList = 1;
    ListObjects[1] = ListFond;

    //WoodBlock_Id_2
	Hitbox *ListWood = malloc(NumberWood * sizeof(Hitbox));
	for (int i=0; i<NumberWood; i++) {
        ListWood[i].centrx = (rand() % WIDTH *20)-WIDTH*10;
        ListWood[i].centry = rand() % HEIGHT;
        ListWood[i].sizex = 100;
        ListWood[i].sizey = 100;
        ListWood[i].g = 255;
        ListWood[i].LengthList = NumberWood;
	}
    ListObjects[2] = ListWood;

    //GrassBlock_Id_3
    Hitbox *ListGrass = malloc(NumberGrass * sizeof(Hitbox));
    for (int i=0; i<NumberGrass; i++) {
        ListGrass[i].centrx = 300*i-5*WIDTH;
        ListGrass[i].centry = HEIGHT+15;
        ListGrass[i].sizex = 300;
        ListGrass[i].sizey = 100;
        ListGrass[i].b = 255;
        ListGrass[i].LengthList = NumberGrass;
    }
    ListObjects[3] = ListGrass;
    return ListObjects;
}
