#include "textureHolder.h"

using namespace std;

TextureHolder::TextureHolder(){}

TextureHolder::~TextureHolder(){}

TextureHolder *TextureHolder::s_Instance = 0;

/*Texture'a gecirilecek fotolarin konumunu, sim'de olusturulan genel renderer'i ve
textureMap pozisyonunu int olarak parametre alir.*/
//sim'de olusturulan  m_pTexture'a atanacak image dolu texturelari tutar.
void TextureHolder::load_to_Texture(string path, SDL_Renderer *renderer, int count)
{
    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr)
    {
        cerr<<"Unable to load image!\n";
    }
    else
    {
        //Create texture from surface pixels
        m_textureMap[count] = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(m_textureMap[count] == nullptr)
        {
            cerr<<"Unable to create texture!\n";
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

}
