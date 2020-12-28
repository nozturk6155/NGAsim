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
    //x ve y ana ekrandaki koordinatlar

    SDL_Rect srcRect;
    SDL_Rect dstRect;


    srcRect.x = width*currentFrame;
    srcRect.y = 0;
    srcRect.w = width;
    srcRect.h = height;

    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = width;
    dstRect.h = height;

    /*source rect ile texture uzerinden istedigimiz kisim alindi sonra destination rect ile
    ekranda istenilen yere basilmasi icin hazirlandi*/
    SDL_RenderCopy(renderer, m_textureMap.at(typeId), &srcRect, &dstRect);
    SDL_RenderPresent(renderer);//show
    SDL_RenderClear(renderer);//clear


}

void TextureManager::clearFromTextureMap(std::string typeId)
{
    SDL_DestroyTexture( m_textureMap.at(typeId) );
    // texture'u maptan sildi.
}
