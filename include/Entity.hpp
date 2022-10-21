#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Settings.hpp"

class Entity
{

public:
    void init();

    Entity(SDL_Point p_pos, SDL_Point p_size, SDL_Texture *p_tex);
    SDL_Point getPos() {return pos;};
    SDL_Rect getCurrentFrame(){return currentFrame;};
    SDL_Texture *getTex(){return tex;};

private:
    SDL_Point pos;
    SDL_Rect currentFrame;
    SDL_Texture *tex;
};