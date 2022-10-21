#include "Entity.hpp"

Entity::Entity(SDL_Point p_pos, SDL_Point p_size, SDL_Texture* p_tex)
    :pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_size.x * c_scale;
    currentFrame.h = p_size.y * c_scale;
}

