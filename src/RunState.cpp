#include "RunState.h"
#include "Sim.h"
#include "TextureManager.h"
#include "Button.h"
#include "Object.h"
#include "InputHolder.h"

const std::string RunState::s_runID = "RUN";


void RunState::update()
{
    for(int i = 0; i < m_simObject.size(); i++)
    {
        m_simObject[i]->update();
    }
}


void RunState::render()
{

    for(int i = 0; i < m_simObject.size(); i++)
    {

        m_simObject[i]->draw();
    }

}

bool RunState::onEnter()
{
    /* Load textures */
    if(!TextureManager::Instance()->load("assets/sifirla.png", TheSim::Instance()->getRenderer(), "reset"))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("assets/tekrar.png", TheSim::Instance()->getRenderer(), "restart"))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("assets/cisim.png", TheSim::Instance()->getRenderer(), "cisim"))
    {
        return false;
    }
    /* Create objects */
    SimObject* restart = new Button(185, 516, 50, 17, "restart",restartToRun);
    SimObject* reset = new Button(185, 550, 50, 17, "reset", resetToMain);
    std::cout << TheInputHolder::Instance()->getYi()
              << " " << TheInputHolder::Instance()->getVx()
              << " " << TheInputHolder::Instance()->getVy();
    SimObject* cisim = new Object(189, TheInputHolder::Instance()->getYi(),
                                  17, 17,"cisim",TheInputHolder::Instance()->getVx(),
                                  TheInputHolder::Instance()->getVy());

    /* Push objects into to vector */
    m_simObject.push_back(reset);
    m_simObject.push_back(restart);
    m_simObject.push_back(cisim);

    std::cout << "entering RunState\n";
    return true;

}

void RunState::restartToRun()
{

}

void RunState::resetToMain()
{
    if(TheSim::Instance()->getStateMachine()->getStateVector().back()->getStateID() == "RUN")
    {
        TheSim::Instance()->getStateMachine()->popState();
    }
}

bool RunState::onExit()
{
    for(int i = 0; i < m_simObject.size(); i++)
    {
        m_simObject[i]->clean();
    }

    m_simObject.clear();

    std::cout << "exiting RunState\n";
    return true;
}


