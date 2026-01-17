#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 1920
#define HEIGHT 1080

void dibujarPixeles(char* estado, SDL_Surface* superf){
    SDL_Rect* pixel = &(SDL_Rect){100,100,1,1};
    for(int i = 0; i < WIDTH*HEIGHT/8; i++){
        char byte = estado[i];
        for(int j = 0; j < 8; j++){
            char res = (char)0x80 & (byte << j);
            if (res == (char)0x80){
                pixel->x= ((i*8+j) % WIDTH);
                pixel->y= ((i*8+j) / WIDTH);
                SDL_FillRect(superf, pixel, 0xFFFFFFFF);
                //printf("Dibujado pixel en %d, %d: que viene de num %d\n", pixel->x, pixel->y, i*8+j);
            }
        }
    }
}

void pasoDeTiempo(char* estado1, char* estado2){
    
}

int main(int argc, char* argv[]){
    SDL_Window* ventana = SDL_CreateWindow("Juego de la vida de Conway",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT, 0);  
    SDL_Surface *superf = SDL_GetWindowSurface(ventana);

    char* estado1 = (char *)malloc((WIDTH*HEIGHT)/8);
    memset(estado1, 0, WIDTH*HEIGHT/8);

    char* estado2 = (char *)malloc((WIDTH*HEIGHT)/8);
    memset(estado2, 0, WIDTH*HEIGHT/8);

    char letra = 0x00;

    bool app_running = true;

    while(app_running){
        SDL_Event event;

        SDL_FillRect(superf,&(SDL_Rect){0,0,WIDTH,HEIGHT}, 0x00000000);

        dibujarPixeles(estado1, superf);
        memset(estado1, letra++, WIDTH*HEIGHT/8);
        //estado1[1] = letra++;

        SDL_UpdateWindowSurface(ventana);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                app_running = 0;
            }
        }
        SDL_Delay(100);
    }

    free(estado1);
}