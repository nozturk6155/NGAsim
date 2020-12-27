#include <iostream>
#include "InputHandler.h"
#include "Sim.h"
#include <SDL.h>
/*
Constructorda Mouse position ve Mouse Button State'leri setlenecek.
Diger mouse ve klavye durumlari donguye eklenecek.
header dosyasindaki onMouseMove, onMouseButtonUp, onMouseButtonDown,
getMousePosition, getMouseButtonState yazilacak.
void clean() fonksiyonunu bu dosyaya da ekle. ici bos kalsin.
*/
InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler()
{

}
//inputların durumunu günceller
void InputHandler::update()
{
    SDL_Event event;
        m_keystates = SDL_GetKeyboardState(0);
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                TheSim::Instance()->quit();
                break;
            case SDL_KEYDOWN:
                KeyEvents();

                break;
            default:
                 break;
            }
        }
}

//Tuşa basılıp basılmadığının kontrolü yapılır
bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystates != 0)
    {
        if(m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
//Klavye yoluyla gerçekleşecek işlemleri yönetir
void InputHandler::KeyEvents()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
    if(isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheSim::Instance()->quit();
    }

}
