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
    rWin.textRender({255, 255, 255}, {0, H_RES - 70 * c_scale}, 20, std::to_string(p1.getIndx()));
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
    if (p1.indx != p1.c.size()-1) {p1.indx+=1;};
    return;
};



void GameTable::PlayerPlay(bool& TryPlayCard, bool& PlayerTurn, bool& BlackCardPlayed, bool& EnemShouldDraw4, bool& EnemShouldDraw2, bool& P1Won){

    int indx = p1.getIndx();
    Card Played = p1.c[indx];
    Card topPile = pile.getCardOnTop();
    bool isMoveValid = checkMove(Played, topPile);

    if(isMoveValid){
        pile.c.push_back(p1.c[indx]);
        p1.c.erase(p1.c.begin() + indx);
        if (indx == p1.c.size()) {p1.indx --;}
        
        if (Played.val == 13){BlackCardPlayed = true;} //Choose a color
        if (Played.val == 14){BlackCardPlayed = true; EnemShouldDraw4 = true;} //Choose a color and opponents draw 4
        PlayerTurn = false;

        if (p1.c.size() == 0){P1Won = true;}
    }

    TryPlayCard = false;

    
}

void GameTable::PileColorSetter(int col){ this->pile.c.back().col = col; }

void GameTable::EnemyPlay(bool& AIWon)
{
    /*Getting available move*/
    std::vector <bool> aMoves;

    bool CanPlay = false;
    bool check;


    for(Card c : ai.c)
    {
        check = checkMove(c, pile.getCardOnTop());
        aMoves.push_back(check);
        if (check) {CanPlay = true;}
    }

    if(!CanPlay){this->OpponentDraws(1);}
    
    else
    {
        int indx;
        srand(time(NULL));
        do
        {
            indx = rand()%aMoves.size();
        }while(!aMoves[indx]);

        /*Play the card*/

        Card ctmp = ai.c[indx];

        pile.c.push_back(ai.c[indx]);
        ai.c.erase(ai.c.begin() + indx);
        if (ai.c.size() == 0) {AIWon = true;}
        if (ctmp.val == 13){this->PileColorSetter(rand()%4);}
        if (ctmp.val == 14){this->PileColorSetter(rand()%4); this->PlayerDraws(4);}
    }
}