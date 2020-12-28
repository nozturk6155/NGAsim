#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <vector>
#include "Vector2D.h"


enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

typedef class InputHandler
{
    public:
        static InputHandler* Instance()
        {
            if(s_pInstance == 0)
            {
                s_pInstance = new InputHandler();
                return s_pInstance;
            }
            return s_pInstance;
        }
        void update();
        void clean();
        bool isKeyDown(SDL_Scancode);

        Vector2D* getMousePosition();

        bool getMouseButtonState(int buttonNumber);
    private:
        InputHandler();
        static InputHandler* s_pInstance;

        void KeyEvents();

        void onMouseMove(SDL_Event& event);
        void onMouseButtonDown(SDL_Event& event);
        void onMouseButtonUp(SDL_Event& event);

        const Uint8* m_keystates;

        Vector2D m_mousePosition;
        std::vector<bool> m_mouseButtonStates;
        ~InputHandler() {}

}TheInputHandler;

#endif // INPUTHANDLER_H
