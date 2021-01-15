#ifndef OBJECT_H
#define OBJECT_H
#include "SimObject.h"
#include "SDL.h"
#include "time.h"
class Object : public SimObject
{
    public:
        Object();
        Object(int x, int y, int w, int h, std::string id, float vx, float vy);
        void draw();
        void update(); // par eklendi
        void clean();
        virtual ~Object();
        int start;
        double diff;
    private:
        double m_x; // eklendi
        double m_y; // eklendi
        Vector2D m_velocity;
        Vector2D m_acceleration;
        bool finished=false;
        bool started=false;
};

#endif // OBJECT_H


