#include "InputHolder.h"
InputHolder *InputHolder::s_Instance=0;
InputHolder::InputHolder(){}
void InputHolder::setYi(int y)
{

    yi = 395 - y; //189 395
}
void InputHolder::setVx(int hiz_x)
{
    vx = hiz_x;
}
void InputHolder::setYon(int b)
{
    yon = b;
}
void InputHolder::setVy(int hiz_y)
{
    if(yon)
    {
        vy = hiz_y;
    }
    else
    {
        vy = -hiz_y;
    }
}

int InputHolder::getYi(){ return yi; }
float InputHolder::getVx(){ return vx; }
float InputHolder::getVy(){ return vy; }
void InputHolder::printVal()
{
    std::cout << "konum: (" << xi << "," << yi << ")\n"
              << "hiz-x: " << vx << "\n"
              << "hiz-y: " << vy << "\n";
}
