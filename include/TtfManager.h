#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <SDL_ttf.h>

typedef class TtfManager
{
public:
    static TtfManager *Instance()
    {
        if(s_Instance == 0)
            {   s_Instance = new TtfManager();
                return s_Instance;
            }
        return s_Instance;
    }
    ~TtfManager();

    //Creates image from font string
    bool loadFromRenderedText(std::string textureText,SDL_Renderer *renderer, std::string Id);
    void render(int x, int y, SDL_Renderer *renderer, std::string textureID);

    int getWidth();
    int getHeight();

    std::map<std::string, std::string> inputText;
    std::map<std::string, SDL_Texture*> mTexture;
    std::string currentID;

    bool renderText = false;

private:
    TtfManager();
    static TtfManager *s_Instance;

    TTF_Font *gFont;

    //Image dimensions
    int mWidth;
    int mHeight;


}TheTtfManager;
