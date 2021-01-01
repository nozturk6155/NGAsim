#include <iostream>
#include "Sim.h"
#include "InputHandler.h"

Sim* Sim::s_pInstance = 0;

Sim::~Sim(){}

bool Sim::init(const char* title, int xpos, int ypos, int width,
                int height, int flag)
{

    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";

        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
        width, height, flag);

        if(m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0)
            {
                std::cout << "renderer creation success\n";
                // Background color is set to black.
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false;
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }

    std::cout << "init success\n";

    // everything inited successfully,start the main loop
    m_bRunning = true;

    m_pSimStateMachine = new SimStateMachine();

    m_pSimStateMachine->changeState(new MainState());

    std::cout << "init done\n";
    return true;
}

void Sim::handleEvents()
{
    InputHandler::Instance()->update();
}

void Sim::update()
{
    for(int i = 0; i < m_pSimStateMachine->getStateVector().size(); i++)
    {

        m_pSimStateMachine->getStateVector()[i]->update();
    }
}

void Sim::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to

    for(int i = 0; i < m_pSimStateMachine->getStateVector().size(); i++)
    {

        m_pSimStateMachine->getStateVector()[i]->render();
    }

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Sim::clean()
{
    std::cout << "cleaning simulation\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}









