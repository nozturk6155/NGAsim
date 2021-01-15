#include "Object.h"
#include "SimObject.h"
#include "Vector2D.h"


Object::Object(int x, int y, int w, int h, std::string id, float vx, float vy)
:SimObject(x,y,w,h,id),m_velocity(vx,vy),m_acceleration(0.00,10.00)
{
    m_velocity *= 0.0166666666666667;
    m_acceleration *= 0.00005391;
    start = clock();
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
    std::cout << m_position.getX() << " " << m_position.getY() << "\n";
    if(started && m_position.getY() > 394.668)
    {
        finished = true;
        std::cout << "son konum: (" << m_position.getX()-189 << ", " << m_position.getY()-395 << ")\n";
        std::cout << "son hiz: (" << m_velocity.getX() << ", " << m_velocity.getY() << ")\n";
        diff = (clock()-start)/(double)(CLOCKS_PER_SEC);
        std::cout << "Gecen sure: " << diff;
    }
    started = true;
}
void Object::clean()
{

}
Object::~Object(){}


