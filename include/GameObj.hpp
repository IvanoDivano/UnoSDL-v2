#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#include "Entity.hpp"
#include "RenderWindow.hpp"


struct Card
{
    int col;
    int val;
    SDL_Texture *tex;

    Card(int p_value, int p_color, RenderWindow& p_win);
};

struct CardArray
{
    std::vector<Card> c;
    int getSize() { return c.size(); };
};

// Added custom implementation for Opponent and Player for future use
// Try and make Private card array


class Player : public CardArray
{
public:
    int indx = 0;
    void Render(RenderWindow& p_win);
    int getVal(){return c[indx].val;};
    int getCol(){return c[indx].col;};
    int getIndx(){return indx;};
};

class Enemy : public CardArray
{
public:
    void Render(RenderWindow& p_win);
};

class Deck : public CardArray
{
public:
    void Render(RenderWindow& p_win);
    void Init(RenderWindow& p_win);
    void Shuffle();
};

class DiscardPile : public CardArray
{
public:
    int getCol(){return c.back().col;};
    int getVal(){return c.back().val;};
    Card getCardOnTop(){return c.back();};
    void Render(RenderWindow& p_win);
    void Reset();
};

