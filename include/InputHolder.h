#ifndef INPUTHOLDER_H
#define INPUTHOLDER_H
#include <iostream>

typedef class InputHolder
{
    public:
        static InputHolder *Instance()
        {
            if(s_Instance == 0)
            {
                s_Instance = new InputHolder();
                return s_Instance;
            }
            return s_Instance;
        }
        void setYi(int y);
        void setVx(int hiz_x);
        void setYon(int b);
        void setVy(int hiz_y);
        int getYi();
        float getVx();
        float getVy();
        void printVal();
    private:
        InputHolder();
        static InputHolder *s_Instance;
        int yi;
        float xi=0;
        float vx;
        float vy;
        int yon;

} TheInputHolder;

#endif // INPUTHOLDER_H
