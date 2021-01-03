#ifndef OBJECT_H
#define OBJECT_H
#include "SimObject.h"
#include "SDL.h"

class Object : public SimObject
{
    public:
        Object();
        Object(int x, int y, int w, int h, std::string id, float vx, float vy);
        void draw();
        void update();
        void clean();
        virtual ~Object();
    private:
        Vector2D m_velocity;
        Vector2D m_acceleration;
        bool finished=false;
};

#endif // OBJECT_H


