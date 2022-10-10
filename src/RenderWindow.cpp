#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL)

{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    if (window == NULL){printf("Window init failed. Error %s", SDL_GetError());}
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

SDL_Texture* RenderWindow::loadTexture(std::string p_fPath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_fPath.c_str());

    if(texture == NULL){printf("Failed to load texture. Errror %s", SDL_GetError());}

    return texture;
}

int RenderWindow::getRefreshRate(){
    int displayIndex = SDL_GetWindowDisplayIndex(window);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void RenderWindow::render(Entity& p_entity){
    
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    
    SDL_Rect dst;
    dst.x = p_entity.getPos().x;
    dst.y = p_entity.getPos().y;
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::textRender(SDL_Color p_color, SDL_Point p_pos, int p_size, std::string p_txt, SDL_Point p_rectSize){
    //Add Custom Fonts, via path in global var
    
    TTF_Init();
    TTF_Font* alagard = TTF_OpenFont("res/font/alagard.ttf", p_size);
    
    SDL_Surface* surfmsg = TTF_RenderText_Solid(alagard, p_txt.c_str(), p_color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfmsg);

    SDL_Rect msg_rect;
    msg_rect.x = p_pos.x;
    msg_rect.y = p_pos.y;
    msg_rect.w = p_rectSize.x;
    msg_rect.h = p_rectSize.y;

    SDL_RenderCopy(renderer, Message, NULL, &msg_rect);
    SDL_FreeSurface(surfmsg);
    SDL_DestroyTexture(Message);
}

