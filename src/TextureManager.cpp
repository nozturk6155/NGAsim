#include "TextureManager.h"
/*
drawFrame ve clearFromTextureMap yazilacak.
*/
TextureManager::TextureManager(){}

TextureManager::~TextureManager(){}

TextureManager *TextureManager::s_Instance = 0;

/*Texture'a gecirilecek fotolarin konumunu, sim'de olusturulan genel renderer'i ve
textureMap pozisyonunu int olarak parametre alir.*/
//sim'de olusturulan  m_pTexture'a atanacak image dolu texturelari tutar.
bool TextureManager::load(std::string path, SDL_Renderer *renderer, std::string typeId)
{
    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr)
    {
        return false;
    }
    else
    {
        //Create texture from surface pixels
        m_textureMap[typeId] = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(m_textureMap[typeId] == nullptr)
        {
            return false;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return true;
}

void TextureManager::drawFrame(std::string typeId, int x, int y,
                               int width, int height,
                               int currentFrame, SDL_Renderer* renderer)
{
    // Source ve Destination Rect olustur. RenderCopy ile ekrana yaz.
}

void TextureManager::clearFromTextureMap(std::string typeId)
{
    // texture'u maptan sil.
}
