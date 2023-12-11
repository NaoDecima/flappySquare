#include <iostream>
#include "SDL.h"
#include "CollisionComponent.h"
#include "Entity.h"


int main(int argc, char* argv[])
{
    // frame cap

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime = 0;

   

    frameStart = SDL_GetTicks();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // Handle initialization error
        return -1;
    }

   static SDL_Window* window = SDL_CreateWindow("Drawing a Rectangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        // Handle window creation error
        SDL_Quit();
        return -1;
    }

   static  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        // Handle renderer creation error
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

  


   
    int windowWidth, windowHeight;
    SDL_GetWindowSizeInPixels(window, &windowWidth, &windowHeight);


    Player player;
    player.init();
 
    SDL_Rect tubesArray[3];

    SDL_Rect tube1 = { 0 ,0, (windowWidth / 16),(windowWidth / 16)*5 };
    SDL_Rect tube2 = { (windowWidth / 2),0, (windowWidth / 16),(windowWidth / 16)*3 };
    SDL_Rect tube3 = { (windowHeight / 2) ,(windowHeight/2), (windowWidth / 16),(windowHeight / 2) };
    tubesArray[0] = tube1;
    tubesArray[1] = tube2;
    tubesArray[2] = tube3;


    SDL_Event e;
    bool quit = false;

    while (quit == false)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    player.jump();
                    
                }
            }
        } 

        //clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
   

        //update the objects

        player.update();
        SDL_Delay(10);
        player.draw(renderer);

        if (collision(player.getCol(), tube1))
        {
            player.init();
        }

         if (tube1.x + tube1.w < 0)
            {
                tube1.x = 800;
            }
            else tube1.x--;

        if (collision(player.getCol(), tube2))
        {
            player.init();
        }
        if (tube2.x + tube2.w < 0)
        {
            tube2.x = 800;
        }
        else tube2.x--;

        if (collision(player.getCol(), tube3))
        {
            player.init();
        }
         if (tube3.x + tube3.w < 0)
        {
            tube3.x = 800;
        }
        else tube3.x--;


        
       //draw the objects

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &tube1);
        SDL_RenderFillRect(renderer, &tube2);
        SDL_RenderFillRect(renderer, &tube3);

       
       

        //render the screen
        SDL_RenderPresent(renderer);

        //frame cap
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    


    // clean up after terminating the program
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}