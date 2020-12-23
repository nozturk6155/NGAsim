#include "textureHolder.h"

using namespace std;

TextureHolder::TextureHolder(){}

TextureHolder::~TextureHolder(){}

TextureHolder *TextureHolder::s_Instance = 0;

//Texture'a gecirilecek fotolarin konumunu ve sim'de olusturulan genel renderer'i parametre olarak alir.
//sim'de olusturulan  m_pTexture'a atanacak image dolu texturelari döndurur.
SDL_Texture *TextureHolder::load_to_Texture(string path, SDL_Renderer *renderer)
{
    //The final texture
    SDL_Texture *newTexture = nullptr;
    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr)
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if(newTexture == nullptr)
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }


    return newTexture;
}
