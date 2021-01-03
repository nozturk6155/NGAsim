#include "MainState.h"
#include "Sim.h"
#include "TextureManager.h"

const std::string MainState::s_mainID = "MAIN";


void MainState::update()
{
    for(int i = 0; i < m_simObject.size(); i++)
    {
        m_simObject[i]->update();
    }
}


void MainState::render()
{

    for(int i = 0; i < m_simObject.size(); i++)
    {

        m_simObject[i]->draw();
    }

}

bool MainState::onEnter()
{

    if(!TextureManager::Instance()->load("assets/bk2.png", TheSim::Instance()->getRenderer(), "bk"))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("assets/io.png", TheSim::Instance()->getRenderer(), "io"))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("assets/harer.png",TheSim::Instance()->getRenderer(), "he"))
    {
        return false;
    }

    /* Create objects */
    SimObject* bilgi = new SimObject(0, 0, 150, 450, "bk");
    SimObject* inout = new SimObject(0, 450, 800, 150, "io");
    SimObject* hareket = new SimObject(150, 0, 650, 450, "he");

    /* Push objects into to vector */
    m_simObject.push_back(bilgi);
    m_simObject.push_back(inout);
    m_simObject.push_back(hareket);

    std::cout << "entering MainState\n";
    return true;

}

bool MainState::onExit()
{
    for(int i = 0; i < m_simObject.size(); i++)
    {
        m_simObject[i]->clean();
    }

    m_simObject.clear();

    std::cout << "exiting MainState\n";
    return true;
}

