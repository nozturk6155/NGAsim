#ifndef SIMOBJECT_H
#define SIMOBJECT_H
#include <iostream>
#include "Vector2D.h"
#include "TextureManager.h"
#include "Sim.h"

class SimObject
{
    public:

        SimObject(int x, int y, int w, int h, std::string ID);
        virtual void draw();
        virtual void update();
        virtual void clean();
        Vector2D& getPosition() { return m_position; }
        int getWidth() { return m_width; }
        int getHeight() { return m_height; }
        ~SimObject();

    protected:

        Vector2D m_position;
        int m_width;
        int m_height;
        int m_currentFrame;
        std::string m_textureID;
};

#endif // SIMOBJECT_H*/
