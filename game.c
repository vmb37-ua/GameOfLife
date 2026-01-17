#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600

int main(int argc, char* argv[]){
    SDL_Window* ventana = SDL_CreateWindow("Juego de la vida de Conway",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT, 0);  
    SDL_Surface *superf = SDL_GetWindowSurface(ventana);


    bool app_running = true;
    
    while(app_running){
        SDL_Event event;

        SDL_FillRect(superf,&(SDL_Rect){0,0,WIDTH,HEIGHT}, 0x00000000);

        // Logica de actualizacion de pixeles

        SDL_UpdateWindowSurface(ventana);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                app_running = 0;
            }
        }
        SDL_Delay(50);
    }
}