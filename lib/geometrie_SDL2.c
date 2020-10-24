#include "geometrie_SDL2.h"

#define pi 3.14159265358979323846264338379
#define False 0
#define True 1

int RegulHollowPoly(SDL_Renderer *renderer,int nbrCote,int tailleCote,int centrx,int centry, int facing, int r,int g,int b,int a) {
        SDL_SetRenderDrawColor(renderer, r,g,b,a);
        float rayon = tailleCote/(2*sin(pi/nbrCote));

        //je calcule ici l'angle qui va se répéter dans tout le polygone.
        float degAngle = (180-(360/nbrCote));
        float radAngle = pi-(degAngle/180)*pi;

        //on fait une liste qui va contenir tout les points.
        SDL_Point poly[abs(nbrCote*tailleCote)];
        int counter = 0;
        //un for qui répète autant de fois qu'il y a de cotés
        for (int j=0; j<nbrCote; j++) {
                float newAngle = radAngle * j;
                //celui là créé et stocke les points un par un
                for (int i=1; i<=tailleCote; i++) {
                        int newx;
                        int newy;
                        //les 3 lignes commentés ci dessous sont si on veut les voirs s'afficher progressivement
                        //SDL_RenderDrawPoints(renderer, poly, nbrCote*tailleCote);
                        //SDL_RenderPresent(renderer);
                        //SDL_Delay(4);

                        switch (facing) {
                                case (2) :
                                        newx = cos(newAngle)*i;
                                        newy = sin(newAngle)*i;

                                        poly[counter].x = (centrx-(tailleCote/2)+newx)/1;
                                        poly[counter].y = (centry-rayon+newy)/1;
                                        break;


                                case (3) :
                                        newx = sin(newAngle)*i;
                                        newy = cos(newAngle)*i;

                                        poly[counter].x = (centrx-(tailleCote/2)+newx)/1;
                                        poly[counter].y = (centry-rayon+newy)/1;
                                        break;

                                case (1) :
                                        newx = cos(-newAngle)*i;
                                        newy = sin(-newAngle)*i;

                                        poly[counter].x = (centrx-(tailleCote/2)+newx)/1;
                                        poly[counter].y = (centry+rayon+newy)/1;
                                        break;

                                case (4) :
                                        newx = sin(-newAngle)*i;
                                        newy = cos(-newAngle)*i;

                                        poly[counter].x = (centrx+(tailleCote/2)+newx)/1;
                                        poly[counter].y = (centry-rayon+newy)/1;
                                        break;


                        }
                        counter ++;
			
			if (i == tailleCote) {
                                centrx += newx;
                                centry += newy;
                        }
                }
        }
        //on dessine les points a patir de la liste (ca retourne 0 en cas de succés)
        SDL_RenderDrawPoints(renderer, poly, nbrCote*tailleCote);
        SDL_SetRenderDrawColor(renderer, 0,0,0,0);
}

int RegulPoly(SDL_Renderer *renderer,int nbrCote,int tailleCote,int centrx,int centry, int facing, int r,int g,int b,int a, bool hollow ) {
	if (hollow == 1) {
		for(int i=1; i<tailleCote; i++) {
			RegulHollowPoly(renderer, nbrCote, i, centrx, centry, facing, r, g, b, a );
		}
	}
	else {
		RegulHollowPoly(renderer, nbrCote, tailleCote, centrx, centry, facing, r, g, b, a );
	}
}

void CreateCircle(SDL_Renderer *renderer, int centrx, int centry, int ray, int r, int g, int b, int a) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        int res = 500;
        SDL_Point cercle[res];
        for (int i = 0; i != res; i++) {
                cercle[i].x = centrx + ray * cos(i);
                cercle[i].y = centry + ray * sin(i);
        }
               SDL_RenderDrawPoints(renderer,cercle , res);
}

int CreateRectangle(SDL_Renderer *renderer, int centrx, int centry, int sizex, int sizey, int r, int g, int b, int a, bool fill) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        if (fill) {
                SDL_Point fillrect[sizex*sizey];
                int counter = 0;
                for (int i=0; i!=sizey; i++ ) {
                        for (int j=0; j!=sizex; j++) {
                                fillrect[counter].x = centrx-sizex/2+j;
                                fillrect[counter].y = centry-sizey/2+i;
                                counter ++;
                        }
                }
                return (SDL_RenderDrawPoints(renderer, fillrect, sizex*sizey));
        }
        else {
                SDL_Point cote1[sizey];
                SDL_Point cote3[sizey];
                for (int i = 0; i != sizey; i++) {
                        cote1[i].x = centrx + sizex/2;
                        cote1[i].y = centry + sizey/2 - i;
                        cote3[i].x = centrx - sizex/2;
                        cote3[i].y = centry + sizey/2 - i;
                }
                SDL_Point cote2[sizex];
                SDL_Point cote4[sizex];
                for (int i = 0; i != sizex; i++) {
                        cote2[i].y = centry - sizey/2;
                        cote2[i].x = centrx + sizex/2 - i;
                        cote4[i].y = centry + sizey/2;
                        cote4[i].x = centrx + sizex/2 - i;
                }
                SDL_RenderDrawPoints(renderer, cote1, sizey);
                SDL_RenderDrawPoints(renderer, cote2, sizex);
                SDL_RenderDrawPoints(renderer, cote3, sizey);
                return (SDL_RenderDrawPoints(renderer, cote4, sizex));
        }
}

