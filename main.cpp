#include <iostream>
#include <SDL.h>
#include "Sim.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    if(TheSim::Instance()->init("NGAsim", 200, 100, 800, 600, 0))
    {
        while(TheSim::Instance()->running())
        {
            frameStart = SDL_GetTicks();

            TheSim::Instance()->handleEvents();
            TheSim::Instance()->update();
            TheSim::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;
            if(frameTime< DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    }
    else
    {
        std::cout << "sim init failure - " << SDL_GetError() << "\n";
        return -1;
    }

    TheSim::Instance()->clean();
    return 0;
}

