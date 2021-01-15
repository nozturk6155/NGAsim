#include "MainState.h"
#include "Sim.h"
#include "TextureManager.h"
#include "Button.h"
#include "RunState.h"
#include "InputHolder.h"
#include "InputBar.h"

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
    if(!TextureManager::Instance()->load("assets/inbar.png",TheSim::Instance()->getRenderer(), "inbar"))
    {
        return false;
    }
    /* Create objects */
    SimObject* bilgi = new SimObject(0, 0, 150, 450, "bk");
    SimObject* inout = new SimObject(0, 450, 800, 150, "io");
    SimObject* hareket = new SimObject(150, 0, 650, 450, "he");
    SimObject* basla = new Button(185, 483, 50, 17, "basla", startToRun);
    SimObject* inbar1 = new InputBar(110, 483, 50, 17, "inbar", typeInbar1);
    SimObject* inbar2 = new InputBar(110, 516, 50, 17, "inbar", typeInbar2);
    SimObject* inbar3 = new InputBar(110, 550, 50, 17, "inbar", typeInbar3);

    /* Push objects into to vector */
    m_simObject.push_back(bilgi);
    m_simObject.push_back(inout);
    m_simObject.push_back(hareket);
    m_simObject.push_back(basla);
    m_simObject.push_back(inbar1);
    m_simObject.push_back(inbar2);
    m_simObject.push_back(inbar3);

    std::cout << "entering MainState\n";
    return true;

}

void MainState::typeInbar1()
{
    int yi;
    std::cout << "Yi(ilk konum-y) giriniz: \n";
    while(1)
    {
        std::cin >> yi;
        if(yi > 0 && yi <= 390)
        {
            TheInputHolder::Instance()->setYi(yi);
            break;
        }
        std::cout << "0 - 390 arasinda bir deger giriniz\n";
    }
}

void MainState::typeInbar2()
{
    int vx;
    std::cout << "Vx(x eksenindeki ilk hiz) giriniz: \n";
    while(1)
    {
        std::cin >> vx;
        if(vx >= 0 && vx <= 100)
        {
            TheInputHolder::Instance()->setVx(vx);
            break;
        }
        std::cout << "0-100 arasinda bir deger giriniz\n";
    }
}

void MainState::typeInbar3()
{
    int vy;
    int dir;
    std::cout << "Vy(y eksenindeki ilk hiz) giriniz: \n";
    while(1)
    {
        std::cin >> vy;
        if(vy >= 0 && vy <= 100)
        {
            TheInputHolder::Instance()->setVy(vy);
        }
        std::cout << "y eksenindeki hizin yonunu giriniz (1 yukari, 0 asagi): \n";
        std::cin >> dir;
        if(dir == 1 || dir == 0)
        {
            InputHolder::Instance()->setYon(dir);
            break;
        }
        else
        {
            std::cout << "1 veya 0 giriniz\n";
        }
    }
}

void MainState::startToRun()
{
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

