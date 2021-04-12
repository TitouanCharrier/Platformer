#include "mainfunc.h"

//Create a texture from image path (char list)
SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]) {
    printf("debug8\n");
	SDL_Surface *buffer = SDL_LoadBMP(Image);
    if (buffer == NULL) {
        //printf("texture : %s\n", SDL_GetError());
    }
    printf("debug9\n");
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(renderer, buffer);
    printf("debug10\n");
	if (!Texture) {
		printf("--%s--\n",Image);
	}
    else {
        printf("++%s++\n",Image);
    }
	return Texture;
}

//Load one type of texture
SDL_Texture **LoadOneTexture(SDL_Renderer *renderer, char file[], int NumberFrames){
// Loading textures
    FILE *fichier_textures = fopen(file,"r");
    //loading Textures

    printf("debug3%s\n",file);
    SDL_Texture **ListTextures = malloc(NumberFrames * sizeof(SDL_Texture*));
        printf("debug4\n");
    char ListTexturesName[NumberFrames][40];
    for (int i=0; i<NumberFrames; i++) {
        printf("debug4.5\n");
        fgets(ListTexturesName[i],40,fichier_textures);
        printf("debug5\n");
        //delete '\n'
        int j=0;
        while (ListTexturesName[i][j] != '\0') {
            
            if (ListTexturesName[i][j] == '\n' || ListTexturesName[i][j] == '$') {
                ListTexturesName[i][j] = '\0';
                break;


            }
            j++;
        }
        printf("debug6\n");
        //ListTexturesName[i][strlen(ListTexturesName[i])-4] = '\0';
        ListTextures[i] = Loading(renderer, ListTexturesName[i]);
        printf("debug7\n");

    }
    return ListTextures;
}
//pack all texture in an array
SDL_Texture ***LoadTexture(SDL_Renderer *renderer) {

    printf("debug1\n");
    SDL_Texture ***ListTextures = malloc(223*sizeof(SDL_Texture**));
    printf("debug2\n");

    ListTextures[0] = LoadOneTexture(renderer,"rsc/Personnage/Lateral/Lateral.txt",20);
    ListTextures[1] = LoadOneTexture(renderer,"rsc/Fond/Fond.txt",2);
    ListTextures[2] = LoadOneTexture(renderer,"rsc/Decors_statiques/Decors_statiques.txt",1);
    ListTextures[3] = LoadOneTexture(renderer,"rsc/Herbe/Herbe.txt",41);
    ListTextures[4] = LoadOneTexture(renderer,"rsc/Personnage/Jump/Jump.txt",40);
    ListTextures[5] = LoadOneTexture(renderer,"rsc/Personnage/Stand/Stand.txt",20);
    ListTextures[6] = LoadOneTexture(renderer,"rsc/Personnage/Aura/Aura.txt",1);
    ListTextures[7] = LoadOneTexture(renderer,"rsc/Personnage/JumpLat/JumpLat.txt",20);


    return ListTextures;
}
