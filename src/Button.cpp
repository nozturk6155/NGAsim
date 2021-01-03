#include "Button.h"
#include "InputHandler.h"
#include "SimState.h"

Button::Button(int x, int y, int w, int h, std::string id, void (*callback)()):
    SimObject(x, y, w, h, id), m_callback(callback)
{
    m_currentFrame = MOUSE_OUT;
}

void Button::draw()
{
    SimObject::draw();
}

void Button::update()
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
            m_callback();
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
    }
}

void Button::clean()
{
    SimObject::clean();
}

