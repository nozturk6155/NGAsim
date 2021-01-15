#ifndef INPUTBAR_H
#define INPUTBAR_H

#include "SimObject.h"
#include <SDL_ttf.h>

class InputBar: public SimObject
{
    public:
        InputBar(int x, int y, int w, int h, std::string id, void (*callback)());
        void draw();
        void update();
        void clean();
    private:
        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
        void (*m_callback)();
        bool m_bReleased = true;
};

#endif // INPUTBAR_H
