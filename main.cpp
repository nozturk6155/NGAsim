#include <iostream>
#include <SDL.h>
#include "Sim.h"

int main(int argc, char* argv[])
{
    if(TheSim::Instance()->init("NGAsim", 100, 100, 640, 480, 0))
    {
        while(TheSim::Instance()->running())
        {
            TheSim::Instance()->handleEvents();
            TheSim::Instance()->update();
            TheSim::Instance()->render();
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
