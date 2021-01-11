#include "TtfManager.h"
#include <iostream>

TtfManager::TtfManager(){
//Initialize
    TTF_Init();
	gFont = TTF_OpenFont("assets/OpenSans-Regular.ttf", 14);
	mWidth = 0;
	mHeight = 0;

}

TtfManager::~TtfManager(){
    SDL_StopTextInput();
    TTF_CloseFont(gFont);
    TTF_Quit();
}

TtfManager *TtfManager::s_Instance = 0;


bool TtfManager::loadFromRenderedText(std::string textureText, SDL_Renderer *renderer, std::string Id)
{//inputHandler'da texture map'in ve inputText map'inin keylerini ayni verdim parametre olarak,
    //mantikli bence böylesi, olur derseniz bu fonksiyonun string parametresini teke indiririm ve inputHandler'da
    //kullanilislarini degistiririm.
    SDL_Color textColor = { 0, 0, 0, 0xFF };
    //Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, inputText[textureText].c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture[Id] = SDL_CreateTextureFromSurface( renderer, textSurface );
		if( mTexture[Id] == NULL )
		{
			std::cerr<<"Unable to create texture from rendered text! SDL Error: "<<SDL_GetError()<<std::endl;
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		std::cerr<<"Unable to render text surface! SDL Error: "<< TTF_GetError()<<std::endl;
	}


	//Return success
	return mTexture[Id] != NULL;


}

void TtfManager::render(int x, int y, SDL_Renderer *renderer, std::string textureID)
{
    //Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Render to screen
	SDL_RenderCopy(renderer, mTexture[textureID], nullptr, &renderQuad);


}














