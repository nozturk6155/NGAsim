#include "SimObject.h"
#include "Vector2D.h"
#include "TextureManager.h"

SimObject::SimObject(int x, int y, int w, int h, std::string textureID): m_position(x,y)
{
    m_width = w;
    m_height = h;
    m_textureID = textureID;
    m_currentFrame=0;
}
void SimObject::draw()
{

    TextureManager::Instance()->drawFrame(m_textureID,(int)m_position.getX(),
    (int)m_position.getY(),m_width, m_height,m_currentFrame,
    TheSim::Instance()->getRenderer());

}
void SimObject::update()
{



}
void SimObject::clean()
{



}
SimObject::~SimObject()
{
    //dtor
}

