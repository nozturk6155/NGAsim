#include "Object.h"
#include "SimObject.h"
#include "Vector2D.h"

Object::Object(int x, int y, int w, int h, std::string id, float vx, float vy)
:SimObject(x,y,w,h,id),m_velocity(vx,vy),m_acceleration(10,10)
{

}

void Object::draw()
{
    SimObject::draw();
}
void Object::update()
{
    if(finished==true)
    {
        return;
    }

    m_velocity += m_acceleration;
    m_position += m_velocity;

    if(m_position.getY()==0)
    {
        finished == true;
    }
}
void Object::clean()
{



}

Object::~Object()
{
    //dtor
}


