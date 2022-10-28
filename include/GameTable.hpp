#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "GameObj.hpp"
#include "Utils.hpp"

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

    void PlayerPlay(bool& TryPlayCard, bool& PlayerTurn, bool& BlackCardPlayed, bool& EnemShouldDraw4, bool& EnemShouldDraw2, bool& P1Won);
    void PlayerMovesLeft();
    void PlayerMovesRight();
    void PileColorSetter(int col);
    void EnemyPlay(bool& AIWon);
};