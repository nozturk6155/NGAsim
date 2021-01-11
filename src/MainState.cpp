#include "MainState.h"
#include "Sim.h"
#include "TextureManager.h"
#include "Button.h"
#include "RunState.h"

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
    if(!TextureManager::Instance()->load("assets/basla.png",TheSim::Instance()->getRenderer(), "basla"))
    {
        return false;
    }
    /* Create objects */
    SimObject* bilgi = new SimObject(0, 0, 150, 450, "bk");
    SimObject* inout = new SimObject(0, 450, 800, 150, "io");
    SimObject* hareket = new SimObject(150, 0, 650, 450, "he");
    SimObject* basla = new Button(185, 483, 50, 17, "basla", startToRun);

    /* Push objects into to vector */
    m_simObject.push_back(bilgi);
    m_simObject.push_back(inout);
    m_simObject.push_back(hareket);
    m_simObject.push_back(basla);

    std::cout << "entering MainState\n";
    return true;

}

void MainState::startToRun()
{
/*
    InputHolder calistirilacak. TtfManager'dan stringleri alip
    kontrol edecek düzenleyecek true or false dondurecek ve
    tutacak.
    Sonuca gore RunState'e gecilecek.
*/
    if(TheSim::Instance()->getStateMachine()->getStateVector().back()->getStateID() != "RUN")
    {
        TheSim::Instance()->getStateMachine()->pushState(new RunState);
    }
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

