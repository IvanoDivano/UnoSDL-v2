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

void GameTable::PlayerMovesLeft(){
    if(p1.indx != 0) {p1.indx-=1;};
    return;
}

void GameTable::PlayerMovesRight(){
    if (p1.indx != p1.c.size()) {p1.indx+=1;};
    return;
}

std::vector <bool> GameTable::CheckMoves(bool player){
    //player true if the enemy is not playing;

    int nCards;
    int pColor = pile.getCol();
    int pValue = pile.getVal();
    int indx = p1.getIndx();
    std::vector <Card> c;
    
    if (player) {nCards == p1.c.size();}
    else {nCards == ai.c.size();}

    std::vector <bool> tmp;
    
    bool NoMoves = true;
    bool SameVal;
    bool SameCol;
    bool IsBlack;
    for(int i = 0; i < nCards; i++)
    {
        SameVal = c[indx].val == pValue;
        SameCol = c[indx].col == pColor;
        IsBlack = c[indx].val == 13 || c[indx].val == 14;
        tmp[i] = SameVal || SameCol || IsBlack;
        if (tmp[i]) NoMoves = false;
    }

    if (NoMoves){tmp.push_back(false);}

    return tmp;
}

bool GameTable::PlayerPlay(){
    std::vector<bool> set = CheckMoves(true);
    if (set[p1.getIndx()])
    {
        pile.c.push_back(p1.c[p1.getIndx()]);
        p1.c.erase(p1.c.begin() + p1.indx);
        
        return true;
    }
    return false;
}