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
bool PlayerTurn = true;
bool IsGameOver = false;

bool P1Won = false;
bool AIWon = false;

unsigned int colorChoosen = 99;

int main(int argc, char const *argv[])
{
    


    return 0;
}