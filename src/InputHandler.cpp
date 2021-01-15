#include <iostream>
#include <SDL.h>
#include "InputHandler.h"
#include "Sim.h"

InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler() : m_mousePosition(0.0,0.0) //Default olarak mouse konumu setlenir.
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }

}
//Mouse'un hangi butonda oldugunu dondurur.
bool InputHandler::getMouseButtonState(int buttonNumber)
{
        return m_mouseButtonStates[buttonNumber];
}
//Mouse'un konumunu dondurur.
Vector2D* InputHandler::getMousePosition()
{
        return &m_mousePosition;
}
//Inputlarýn durumunu gunceller
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
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
            case SDL_KEYDOWN:
                KeyEvents();
                break;
            default:
                 break;
            }
        }
}

//Tusa basýlýp basýlmadýgýnýn kontrolu yapilir.
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
//Klavye yoluyla gerceklesecek islemleri yonetir
void InputHandler::KeyEvents()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
    if(isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        TheSim::Instance()->quit();
    }

}
//Mouse'un x ve y koordinatý setlenir.
void InputHandler::onMouseMove(SDL_Event& event)
{
    m_mousePosition.setX(event.motion.x);
    m_mousePosition.setY(event.motion.y);
}
//Mouse'ta input verilip verilmediginin kontrolu yapilir.
void InputHandler::onMouseButtonUp(SDL_Event& event) {
	switch (event.button.button)
	{
        case SDL_BUTTON_LEFT:
            m_mouseButtonStates[LEFT] = false;
            break;
        case SDL_BUTTON_MIDDLE:
            m_mouseButtonStates[MIDDLE] = false;
            break;
        case SDL_BUTTON_RIGHT:
            m_mouseButtonStates[RIGHT] = false;
            break;
        default:
            break;
	}
}
//Mouse'ta input verilip verilmediginin kontrolu yapilir.
void InputHandler::onMouseButtonDown(SDL_Event& event) {
	switch (event.button.button)
	{
        case SDL_BUTTON_LEFT:
            m_mouseButtonStates[LEFT] = true;
            break;
        case SDL_BUTTON_MIDDLE:
            m_mouseButtonStates[MIDDLE] = true;
            break;
        case SDL_BUTTON_RIGHT:
            m_mouseButtonStates[RIGHT] = true;
            break;
        default:
            break;
	}
}

void InputHandler::clean()
{

}
