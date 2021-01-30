#include "../src/mainfunc.h"

Couple Play_menu() {

TTF_Font * Sans = TTF_OpenFont("/usr/share/fonts/liberation/LiberationMono-Regular.ttf",1024);
    //init menu window and renderer
    SDL_Renderer *R_menu = NULL;
    SDL_Window *W_menu = NULL;
    
	//set menu windw and renderer
    W_menu = SDL_CreateWindow("Titre",1920/2-125,1080/2-250,250,500,0);
    R_menu = SDL_CreateRenderer(W_menu,-1,SDL_RENDERER_ACCELERATED);
    
    Couple retour;
    SDL_Color white = {255,255,255};
    SDL_Event menu_event;
    int choix;
    
    SDL_Rect List_Rect[4];
    char Text[4][50] = {"void","1920 x 1080","2560 x 1080","1366 x 768"};

    CreateRectangle(R_menu,125,125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,125+125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,2*125+125/2,250,125,255,88,0,255,0);
    CreateRectangle(R_menu,125,3*125+125/2,250,125,255,88,0,255,0);

    Print_Text(R_menu,"       Hello       ",10,25,230,32,Sans);
    SDL_Delay(25); 
    Print_Text(R_menu,"Select a resolution",10,25+40,230,32,Sans);
    SDL_Delay(25); 
    
    for (int i=1; i<4; i++) {
    
        Print_Text(R_menu,Text[i],10,25+125*i,230,75,Sans);
        List_Rect[i].x = 10;
        List_Rect[i].y = 25+125*i;
        List_Rect[i].w = 230;
        List_Rect[i].h = 75;
        SDL_Delay(25); 
    }
    
    

    //menu loop
    
    while(1) {
        
        SDL_WaitEvent(&menu_event);
        
        if (menu_event.type == SDL_MOUSEBUTTONDOWN) {
            if (menu_event.button.button == SDL_BUTTON_LEFT) {
                int x = menu_event.button.x;
                int y = menu_event.button.y;
                
                for (int i=1; i<4; i++) {

                    if (x>List_Rect[i].x && x<(List_Rect[i].w+List_Rect[i].x) 
                        && y>List_Rect[i].y && y<(List_Rect[i].h+List_Rect[i].y)) {
                            choix = i;
                            goto EXIT;
                    }  
                }
            }
        }

        SDL_RenderPresent(R_menu);
        SDL_Delay(10);
    }

    EXIT :
    
    SDL_DestroyWindow(W_menu);

    switch (choix)  {
        case 1 :
            retour.RESX = 1920;
            retour.RESY = 1080;
            return retour;
            break;
    
        case 2 :    
            retour.RESX = 2560;
            retour.RESY = 1080;
            return retour;
            break;
        
        case 3 :
            retour.RESX = 1366;
            retour.RESY = 768;
            return retour;
            break;

    }
}



















