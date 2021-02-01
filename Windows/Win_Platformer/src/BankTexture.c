#include "mainfunc.h"

//Create a texture from image path (char list)
SDL_Texture *Loading(SDL_Renderer *renderer, char Image[]) {
	SDL_Surface *buffer = SDL_LoadBMP(Image);
    if (buffer == NULL) {
        printf("erreure de chargement de la texture : %s", SDL_GetError());
    } 
	SDL_Texture *Texture = SDL_CreateTextureFromSurface(renderer, buffer);
    
	return Texture;
}

//Load one type of texture
SDL_Texture **LoadOneTexture(SDL_Renderer *renderer, char file[], int NumberFrames){
// Loading textures
    FILE *fichier_textures = fopen(file,"r");
    //loading Textures
    SDL_Texture **ListTextures = malloc(NumberFrames * sizeof(SDL_Texture*));
    char ListTexturesName[NumberFrames][40];
    for (int i=0; i<NumberFrames; i++) {
        fgets(ListTexturesName[i],40,fichier_textures);
        
        //delete '\n'
        int j=0;
        while (ListTexturesName[i][j] != '\0') {
            if (ListTexturesName[i][j] == '\n') {
                ListTexturesName[i][j] = '\0';

                          
            }
            j++;
        }
        printf("%s\n",ListTexturesName[i]);
        //ListTexturesName[i][strlen(ListTexturesName[i])-4] = '\0';
        ListTextures[i] = Loading(renderer, ListTexturesName[i]);
    
    }
    return ListTextures;
}
//pack all texture in an array
SDL_Texture ***LoadTexture(SDL_Renderer *renderer) {

    SDL_Texture ***ListTextures = malloc(223*sizeof(SDL_Texture*));
    
    ListTextures[0] = LoadOneTexture(renderer,"rsc/Personnage/Personnage.txt",1);
    ListTextures[1] = LoadOneTexture(renderer,"rsc/Fond/Fond.txt",1);
    ListTextures[2] = LoadOneTexture(renderer,"rsc/Decors_statiques/Decors_statiques.txt",1);
    ListTextures[3] = LoadOneTexture(renderer,"rsc/Herbe/Herbe.txt",440);
    

    return ListTextures;
}
