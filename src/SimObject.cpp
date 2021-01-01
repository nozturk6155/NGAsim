#include "SimObject.h"
#include "Vector2D.h"
#include "TextureManager.h"

SimObject::SimObject(int x, int y, int w, int h, std::string textureID): m_position(0.0,0.0)
{
    m_x = x;
    m_y = y;
    m_width = w;
    m_height = h;
    m_textureID = textureID;
    m_currentFrame=0;

}
void SimObject::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
    m_width, m_height,m_currentFrame, pRenderer);

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

