#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Settings.hpp"
#include "GameObj.hpp"
#include "GameTable.hpp"

bool gameRunning = true;

int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_Init FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_init FAILED. ERROR: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("UNO with an RPG twist", W_RES, H_RES);

    printf("Display Refresh Rate: %d\nWindow Resolution: %dx%d", window.getRefreshRate(), W_RES, H_RES);

    Player p1;
    Enemy ai;
    Deck deck;
    DiscardPile pile;
    
    GameTable Game {p1, ai, deck, pile, window};
    Game.AddRenderer(window);
    Game.StartTheGame();
    window.setFullScreen();
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        window.clear();

        Game.RenderGameTable();
        Game.OpponentDraws(1);
        Game.PlayerDraws(1);
        SDL_Delay(200);

        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
