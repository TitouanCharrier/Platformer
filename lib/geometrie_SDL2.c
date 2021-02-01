#include "geometrie_SDL2.h"

#define False 0
#define True 1

//create a regular empty polygon
int RegulHollowPoly(SDL_Renderer *renderer,int nbrCote,int tailleCote,int centrx,int centry, int facing, int r,int g,int b,int a) {
        SDL_SetRenderDrawColor(renderer, r,g,b,a);
        float rayon = tailleCote/(2*sin(pi/nbrCote));

        //set main angle repeated in the polygon
        float degAngle = (180-(360/nbrCote));
        float radAngle = pi-(degAngle/180)*pi;

        //list who store all points
        SDL_Point poly[abs(nbrCote*tailleCote)];
        int counter = 0;

        //repeat for each side
        for (int j=0; j<nbrCote; j++) {
                float newAngle = radAngle * j;

                //create and store point
                for (int i=1; i<=tailleCote; i++) {
                        int newx;
                        int newy;
                        //uncomment the following to show the poly appear (slow)
                        //SDL_RenderDrawPoints(renderer, poly, nbrCote*tailleCote);
                        //SDL_RenderPresent(renderer);
                        //SDL_Delay(4);
			
			//add a basic rotation function with only for directions 
			//North 1, South 2, East 3, West 4
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
        //drawing each point contained in poly list
        SDL_RenderDrawPoints(renderer, poly, nbrCote*tailleCote);
        SDL_SetRenderDrawColor(renderer, 0,0,0,0);
}

//enable to create full polygons (work in progress)
int RegulPoly(SDL_Renderer *renderer, int nbrCote, int tailleCote,
int centrx, int centry, int facing, int r,int g,int b,int a, bool hollow ) {
	if (hollow == 1) {
		for(int i=1; i<tailleCote; i++) {
			RegulHollowPoly(renderer, nbrCote, i, centrx, centry, facing, r, g, b, a );
		}
	}
	else {
		RegulHollowPoly(renderer, nbrCote, tailleCote, centrx, centry, facing, r, g, b, a );
	}
}

//Create circle with a radius and a center (and rgba)
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

//create a rectangle with a center and both side size (rgba and fill state)
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

void Rectangle(SDL_Renderer *renderer,int centrx, int centry, int sizex, int sizey, float rot, int r, int g, int b, int a) {

    SDL_SetRenderDrawColor(renderer, r,g,b,a);

    float ddiag = sqrt(pow(sizex,2)+pow(sizey,2))/2;

    float angle1;
    float angle2;

    if (sizex == sizey) {
        angle1 = pi/2;
        angle2 = pi/2;
    }
    else {
        angle1 = acos(sizey/sizex);
        angle2 = (360-2*angle1)/2;
    }

    int x1 = centrx + ddiag * cos(rot+0*angle1+0*angle2); 
    int y1 = centry + ddiag * sin(rot+0*angle1+0*angle2);   

    int x2 = centrx + ddiag * cos(rot+1*angle1); 
    int y2 = centry + ddiag * sin(rot+1*angle1); 

    int x3 = centrx + ddiag * cos(rot+pi); 
    int y3 = centry + ddiag * sin(rot+pi); 

    int x4 = centrx + ddiag * cos(rot+1*angle1+pi); 
    int y4 = centry + ddiag * sin(rot+1*angle1+pi); 

    SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
    SDL_RenderDrawLine(renderer,x2,y2,x3,y3);
    SDL_RenderDrawLine(renderer,x3,y3,x4,y4);
    SDL_RenderDrawLine(renderer,x4,y4,x1,y1);

    SDL_SetRenderDrawColor(renderer, 0,0,0,0);

}

void Polygone(SDL_Renderer *renderer,int centrx, int centry, int rayon, int cote, float rot, int r, int g, int b, int a) {

    SDL_SetRenderDrawColor(renderer,r,g,b,a);

    double angle = 2*pi/cote;
    int x1;
    int y1;
    int x2;
    int y2;

    for (int i=0; i<cote; i++) {
        x1 = centrx - rayon * cos(rot+i*angle); 
        y1 = centry - rayon * sin(rot+i*angle); 
        x2 = centrx - rayon * cos(rot+(i+1)*angle); 
        y2 = centry - rayon * sin(rot+(i+1)*angle); 
        SDL_RenderDrawLine(renderer,x1,y1,x2,y2);
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,0);

}

void Circle(SDL_Renderer *renderer, int centrx, int centry, int rayon, int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer,r,g,b,a);   

    for (float i=0; i<2*pi; i+=0.005) {
        SDL_RenderDrawPoint(renderer,centrx + rayon*cos(i),centry + rayon*sin(i));
    }

    SDL_SetRenderDrawColor(renderer,0,0,0,0);
}

int Detect_KeyDown(SDL_Event event,int touche) {

    SDL_PollEvent(&event);
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == touche) {
            return 1;
        }
    }

    return 0;
}







