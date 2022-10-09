#include "GameTable.hpp"


void GameTable::AddRenderer(RenderWindow& p_win){
    rWin = p_win;
};

void GameTable::PlayerDraws(int n)
{
    for(int i = 0; i < n; i++)
    {
        p1.c.push_back(deck.c.back());
        deck.c.pop_back();
    }
};

void GameTable::OpponentDraws(int n)
{
    for(int i = 0; i < n; i++)
    {
        ai.c.push_back(deck.c.back());
        deck.c.pop_back();
    }
};


void GameTable::RenderGameTable(){
    p1.Render(rWin);
    ai.Render(rWin);
    deck.Render(rWin);
    pile.Render(rWin);
};


void GameTable::StartTheGame()
{
    deck.Init(rWin);
    deck.Shuffle();
    // p1 and ai draws 7

    PlayerDraws(7);
    OpponentDraws(7);

    // Add a card from the deck to the discard pile
    // Might be smart to add a func TakeFrom, since this
    // Code gets used multiple time
    pile.c.push_back(deck.c.back());
    deck.c.pop_back();

};