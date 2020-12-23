#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <map>

using namespace std;

typedef class TextureHolder
{
public:

    static TextureHolder *Instance()//dýþarýdan objeye ulaþmamýzý saðlayacak fonks.
        {
            if(s_Instance == 0)
            {   s_Instance = new TextureHolder();
                return s_Instance;
            }

            return s_Instance;
        }
        ~TextureHolder();

    void load_to_Texture(string path, SDL_Renderer *renderer, int count);

    map<string, SDL_Texture*> m_textureMap;

private:
    TextureHolder();
    static TextureHolder *s_Instance;

}TheTextureHolder;
