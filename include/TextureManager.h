#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <map>


typedef class TextureManager
{
public:

    static TextureManager *Instance()//disaridan objeye ulasmamizi saglayacak fonks.
        {
            if(s_Instance == 0)
            {   s_Instance = new TextureHolder();
                return s_Instance;
            }

            return s_Instance;
        }
        ~TextureManager();

    bool load(std::string path, SDL_Renderer *renderer, std::string typeId);

    std::map<std::string, SDL_Texture*> m_textureMap;

    void drawFrame(std::string typeId, int x, int y, int width, int
        height, int currentFrame, SDL_Renderer* renderer);

    void clearFromTextureMap(std::string typeId);

private:
    TextureManager();
    static TextureManager *s_Instance;

}TheTextureManager;

#endif // TEXTUREMANAGER_H
