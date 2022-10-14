#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h);
    SDL_Texture *loadTexture(std::string p_filePath);
    void render(Entity &p_entity);
    void textRender(SDL_Color p_color, SDL_Point p_pos, int p_size, std::string p_txt);

    void toggleFullScreen();
    int getRefreshRate();
    void cleanUp(){SDL_DestroyWindow(window);};
    void clear(){SDL_RenderClear(renderer);};
    void display(){SDL_RenderPresent(renderer);};
    void setFullScreen(){SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);};

private:
    SDL_Window* window;
    SDL_Renderer* renderer;

};