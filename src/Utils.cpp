#include "Utils.hpp"


bool checkMove(Card t, Card b){
    bool sameVal = b.val==t.val;
    bool sameCol = t.col==b.col;
    bool isBlack = t.val==14 || t.val == 13;

    return sameVal || sameCol || isBlack;
}


void renderChoosePopup(SDL_Texture* tex, RenderWindow& win){
    
    SDL_Point pos = {(W_RES - 192*c_scale) / 2, (H_RES - 192*c_scale) / 2};


    Entity tmp(pos, {192, 192}, tex);

    win.render(tmp);
}