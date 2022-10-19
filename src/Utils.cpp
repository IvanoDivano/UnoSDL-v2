#include "Utils.hpp"


bool checkMove(Card t, Card b){
    bool sameVal = b.val==t.val;
    bool sameCol = t.col==b.col;
    bool isBlack = t.val==14 || t.val == 13;

    return sameVal || sameCol || isBlack;
}

int chooseColor();