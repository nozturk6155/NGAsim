#include "InputBar.h"

#include "InputHandler.h"

#include "SimState.h"


InputBar::InputBar(int x, int y, int w, int h, std::string id, void (*callback)()):

    SimObject(x, y, w, h, id), m_callback(callback)

{
    m_currentFrame = MOUSE_OUT;
}

void InputBar::draw()
{
    SimObject::draw();
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
            m_bReleased = false;
            m_callback();

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
    }

}

void InputBar::clean()
{
    SimObject::clean();
}
