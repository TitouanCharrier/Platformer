#include "mainfunc.h"

Hitbox **LoadObjects(int WIDTH, int HEIGHT) {

    int NumberHero = 1;
    int NumberGrass = NBR_GRASS;
    int NumberWood = NBR_WOOD;
    int NumberFond = 1;
    int Total = NumberWood+NumberHero+NumberGrass+NumberFond;


    Hitbox **ListObjects = malloc(Total * sizeof(Hitbox));

    //Hero is a Hitbox, type defined in src/struct.h
    //add a case to the main list :
    // HeroBox_Id_0;
    Hitbox *ListHero = malloc(NumberHero * sizeof(Hitbox));
    ListHero[0].centrx = WIDTH/2;
    ListHero[0].centry = HEIGHT/2;
    ListHero[0].sizex = 50;
    ListHero[0].sizey = 120;
    ListHero[0].LengthList = NumberHero;
    ListHero[0].r = 255;
    ListHero[0].g = 100;
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
        ListWood[i].centry = (rand() % HEIGHT);
        ListWood[i].sizex = 100;
        ListWood[i].sizey = 100;
        ListWood[i].g = 255;
        ListWood[i].LengthList = NumberWood;
	}
    ListObjects[2] = ListWood;

    //GrassBlock_Id_3
    Hitbox *ListGrass = malloc(NumberGrass * sizeof(Hitbox));
    for (int i=0; i<NumberGrass; i++) {
        ListGrass[i].centrx = 800/2*i-5*WIDTH;
        ListGrass[i].centry = HEIGHT+15;
        ListGrass[i].sizex = 800/2;
        ListGrass[i].sizey = 120/2;
        ListGrass[i].b = 255;
        ListGrass[i].LengthList = NumberGrass;
    }
    ListObjects[3] = ListGrass;
    return ListObjects;
}

Hitbox **LoadMap(int WIDTH, int HEIGHT, char *file_map, int NBR_Types) {
    
    Hitbox ObjTmp;
    
    FILE *fichier_map = fopen(file_map,"r");

    if (fichier_map == NULL){
        printf("ERROR failed to open map\n");
    }
    printf("success to open map_file\n");
    
    //read character by character and check for new line
    int linesCount = 0;
    char ch;
    while((ch=fgetc(fichier_map))!=EOF) {
        if(ch=='\n')
            printf("%d\n", linesCount );
            linesCount++;
    }
    
    //primary array
    Hitbox **ListObjects;
    ListObjects = malloc(NBR_Types*sizeof(Hitbox*));
    for (int i=0; i<NBR_Types; i++) {
        ListObjects[i] = malloc(linesCount*sizeof(Hitbox));
    }
    //replace cursor
    fseek(fichier_map,0,SEEK_SET);
    
    //var to store line's content
    char file_content[150]; 

    //load datas
    int i = 0;
    while (fscanf(fichier_map, "%[^\n] ",file_content) != EOF) {
        printf("%s\n", file_content);

        //extend list => error malloc invalid size unsorted
        //Type = malloc(sizeof(Hitbox));
        
        //convert tu usable datas
        sscanf(file_content, "%d, %d, %f, %f, %f, %f, %d", 
            &ObjTmp.T_ID, &ObjTmp.R_ID, &ObjTmp.centrx, &ObjTmp.centry, &ObjTmp.sizex, &ObjTmp.sizey, &ObjTmp.LengthList);
        
        ObjTmp.centrx *= WIDTH;
        ObjTmp.centry *= HEIGHT;
        ObjTmp.sizex *= WIDTH;
        ObjTmp.sizey *= HEIGHT;
        
        printf("centrx : %f\n", ObjTmp.centrx );
        printf("centry : %f\n", ObjTmp.centry );

        printf("T_ID : %d\n", ObjTmp.T_ID );
        printf("R_ID : %d\n", ObjTmp.R_ID );
        printf("coucou\n");


        ListObjects[ObjTmp.T_ID][ObjTmp.R_ID] = ObjTmp;

        i++;
    }

    printf("test 1 : %f\n", ListObjects[0][0].centrx );
    printf("test 2 : %f\n", ListObjects[0][0].centry );
    printf("test 3 : %f\n", ListObjects[0][0].sizex );
    printf("test 4 : %f\n", ListObjects[0][0].sizey );
    printf("test 5 : %f\n", ListObjects[3][10].centrx );
    printf("test 6 : %f\n", ListObjects[3][11].centrx );
    printf("test 7 : %f\n", ListObjects[3][12].centrx );


    fclose(fichier_map);
    printf("success to load map\n");
    
    return ListObjects;
}