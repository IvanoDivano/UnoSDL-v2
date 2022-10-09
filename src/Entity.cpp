#include "Entity.hpp"

Entity::Entity(SDL_Point p_pos, SDL_Texture* p_tex)
    :pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 50 * c_scale;
    currentFrame.h = 70 * c_scale;
}

