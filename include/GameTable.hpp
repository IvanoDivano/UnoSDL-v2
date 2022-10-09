#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "GameObj.hpp"

class GameTable
{

    
public:
    Player p1;
    Enemy ai;
    Deck deck;
    DiscardPile pile;

    RenderWindow rWin;
    void AddRenderer(RenderWindow& p_win);
    void StartTheGame();
    void PlayerDraws(int n);
    void OpponentDraws(int n);
    void RenderGameTable();
};