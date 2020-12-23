#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>


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
    private:
        static InputHandler* s_pInstance;
        void KeyEvents();
        InputHandler();
        ~InputHandler() {}
        const Uint8* m_keystates;

}TheInputHandler;

#endif // INPUTHANDLER_H
