#include "GameObj.hpp"

Card::Card(int p_value, int p_color, RenderWindow& p_win)
{
    val = p_value;
    col = p_color;

    std::string path("res/gfx/");

    switch (val)
    {
    case 0:
        path.append("0");
        break;

    case 1:
        path.append("1");
        break;

    case 2:
        path.append("2");
        break;

    case 3:
        path.append("3");
        break;

    case 4:
        path.append("4");
        break;

    case 5:
        path.append("5");
        break;

    case 6:
        path.append("6");
        break;

    case 7:
        path.append("7");
        break;

    case 8:
        path.append("8");
        break;

    case 9:
        path.append("9");
        break;

    case 10:
        path.append("Stop");
        break;

    case 11:
        path.append("Cambio");
        break;

    case 12:
        path.append("2+");
        break;

    case 13:
        path.append("Cambio");
        break;

    case 14:
        path.append("4+");
    }

    switch (col)
    {
    case 0:
        path.append("Blu");
        break;

    case 1:
        path.append("Giallo");
        break;

    case 2:
        path.append("Rosso");
        break;

    case 3:
        path.append("Verde");
    }

    path.append(".png");
    tex = p_win.loadTexture(path);
};

void Deck::Init(RenderWindow& p_win)
{
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            c.push_back(Card(i, j, p_win));
            if (i != 0)
            {
                c.push_back(Card(i, j, p_win));
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        c.push_back(Card(13, 99, p_win));
        c.push_back(Card(14, 99, p_win));
    }
}

void Deck::Shuffle()
{
    srand(time(NULL));

    int n_shuffle = rand()%100 + 100;
    int p1, p2;

    for(int i = 0; i <= n_shuffle; i++)
    {
        p1 = rand()%c.size();
        p2 = rand()%c.size();

        Card swap = c[p1];
        c[p1] = c[p2];
        c[p2] = swap;
    }

}

void Player::Render(RenderWindow& p_win){
    float cWidth = 50 * c_scale;
    float cHeight = 70 * c_scale;
    int cSide = 20 * c_scale;

    int cSpaceTanken = ((c.size()-1) * cSide) + cWidth;


    std::vector <Entity> tmp;

    SDL_Point pos = {(W_RES - cSpaceTanken)/2, H_RES - cHeight};
    SDL_Point posIndx = pos; 
    
    posIndx.x += cSide * indx;
    posIndx.y -= 55 * c_scale;

    
    for(Card card : this->c)
    {
        tmp.push_back(Entity(pos, card.tex));
        pos.x += cSide;
    }

    //Figure out how many lines to draw

    
    tmp[indx] = Entity(posIndx, tmp[indx].getTex());

    for (Entity& e : tmp){p_win.render(e);}
    
}

void Enemy::Render(RenderWindow& p_win)
{
    SDL_Texture* backTex = p_win.loadTexture("res/gfx/Back.png");

    int cSide = 20;
    float cWidth = 50 * c_scale;
    float cHeight = 70 * c_scale;
    std::vector <Entity> tmp;

    SDL_Point point {W_RES - ((W_RES - ((c.size()-1) * cSide) + cWidth)/2), 0};

    for(int i = 0; i < c.size(); i++)
    {
        tmp.push_back(Entity(point, backTex));
        point.x -= cSide;
    }

    for(Entity& e : tmp){p_win.render(e);};
}

void Deck::Render(RenderWindow& p_win)
{
    SDL_Texture* backTex = p_win.loadTexture("res/gfx/Back.png");
    SDL_Point pos {((W_RES / 3) * 2) - 50*c_scale/2, H_RES/2 - 70*c_scale/2};
    Entity e(pos, backTex);
    p_win.render(e);
    pos.x += 50*c_scale + 30;
    pos.y += 5;
    std::string nCards;
    nCards += std::to_string(c.size());
    p_win.textRender({255, 255, 255}, pos, 32*c_scale, nCards);
}

void DiscardPile::Render(RenderWindow& p_win)
{
    SDL_Point pos {(W_RES / 3) - 50*c_scale/2, H_RES/2 - 70*c_scale/2}; 
    Entity e(pos, c.back().tex);
    p_win.render(e);
}