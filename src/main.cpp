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
bool ShoudlDrawCard = false;
bool ShouldMoveLeft = false;
bool ShouldMoveRight = false;
bool TryPlayCard = false;
bool isChoosingColor = false;
bool BlackCardPlayed = false;
bool EnemShouldDraw4 = false;
bool EnemShouldDraw2 = false;
bool HasChoosen = false;

unsigned int colorChoosen = 99;

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

    printf("Display Refresh Rate: %d\nWindow Resolution: %dx%d\n", window.getRefreshRate(), W_RES, H_RES);

    Player p1;
    Enemy ai;
    Deck deck;
    DiscardPile pile;

    SDL_Texture* chooseTex;
    chooseTex = window.loadTexture("res/gfx/ChooseColor.png");

    
    GameTable Game {p1, ai, deck, pile, window};
    Game.AddRenderer(window);
    Game.StartTheGame();
    window.setFullScreen();
    SDL_Event event;

    /*
    SDL_Texture* tmp_tex;
    tmp_tex = window.loadTexture("res/gfx/ChooseColor.png");
    Entity tmp_ent({W_RES/2, H_RES/2}, {192, 192}, tmp_tex);
    */

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    gameRunning = false; break;
                    
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        gameRunning = false; break;

                        case SDLK_LCTRL:
                        ShoudlDrawCard = true; break;

                        case SDLK_LEFT: ShouldMoveLeft = true; break;

                        case SDLK_RIGHT: ShouldMoveRight = true; break;
                        
                        case SDLK_e: TryPlayCard = true; break;

                        case SDLK_f:
                        //toggle fullscreen, changes scale and res
                        //window.setFullScreen
                        break;

                        case SDLK_w: if (isChoosingColor) {colorChoosen = 2; HasChoosen = true;} break;

                        case SDLK_a: if (isChoosingColor) {colorChoosen = 1; HasChoosen = true;} break;

                        case SDLK_s: if (isChoosingColor) {colorChoosen = 3; HasChoosen = true;} break;

                        case SDLK_d: if (isChoosingColor) {colorChoosen = 0; HasChoosen = true;} break;
                    }
                break;
            }
        }

        window.clear();

        Game.RenderGameTable();
        
        

        if(!isChoosingColor)
        {
            if(ShouldMoveLeft) {Game.PlayerMovesLeft(); ShouldMoveLeft = false;}
            if(ShouldMoveRight) {Game.PlayerMovesRight(); ShouldMoveRight = false;}
            if(TryPlayCard) {Game.PlayerPlay(BlackCardPlayed, EnemShouldDraw4, EnemShouldDraw4); TryPlayCard = false;}
            if(ShoudlDrawCard) {Game.PlayerDraws(1); ShoudlDrawCard = false;}
            
            if(BlackCardPlayed) {isChoosingColor = true; BlackCardPlayed = false;};
            if(EnemShouldDraw2) {Game.OpponentDraws(2); EnemShouldDraw2 = false;}
            if(EnemShouldDraw4) {Game.OpponentDraws(4); EnemShouldDraw4 = false;}
        }

        else
        {
            renderChoosePopup(chooseTex, window);
            
            if (HasChoosen)
            {
                Game.PileColorSetter(colorChoosen); 
                isChoosingColor = false; 
                HasChoosen = false;
            };
        }



        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    return 0;
}
