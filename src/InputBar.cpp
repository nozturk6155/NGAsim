#include "InputBar.h"
#include "InputHandler.h"
#include "SimState.h"
#include "TtfManager.h"

InputBar::InputBar(int x, int y, int w, int h, std::string id):
    SimObject(x, y, w, h, id)
{
    m_currentFrame = MOUSE_OUT;
    TheTtfManager::Instance()->inputText[id];
    TheTtfManager::Instance()->mTexture[id];
    //bu currentID inputbarýnki
    currentID = id;
}

void InputBar::draw()
{
    SimObject::draw();
    //muhtemelen diger inputbarlara tiklaninca yazili olan inputBarýn ekrandaki text'i kaybolacak,
    //nasil bi çozum bulabiliriz?
    TtfManager::Instance()->render(110,480,TheSim::Instance()->getRenderer(),
                                   TheTtfManager::Instance()->currentID);
}

void InputBar::update()
{
    Vector2D *pMousePos = TheInputHandler::Instance()
                            ->getMousePosition();

    if(pMousePos->getX() < (m_position.getX() + m_width)
    && pMousePos->getX() > m_position.getX()
    && pMousePos->getY() < (m_position.getY() + m_height)
    && pMousePos->getY() > m_position.getY())
    {
        if(TheInputHandler::Instance()->getMouseButtonState(LEFT)
        && m_bReleased)
        {
            m_currentFrame = CLICKED;
            TheTtfManager::Instance()->currentID = currentID;
            SDL_StartTextInput();

            m_bReleased = false;
        }
        else if(!TheInputHandler::Instance()
        ->getMouseButtonState(LEFT))
        {
            m_bReleased = true;
            m_currentFrame = MOUSE_OVER;
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
        SDL_StopTextInput();
    }
}

void InputBar::clean()
{
    SimObject::clean();
}
