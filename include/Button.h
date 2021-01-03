#ifndef BUTTON_H
#define BUTTON_H

#include "SimObject.h"
/*
Constructorda son parametre haric digerleri SimObject'in constructoruna verilir
bunun yaninda currentframe degiskeni MOUSE_OUT'a setlenir.
draw() fonksiyonunda SimObject'in draw'u cagrilir
update() fonksiyonunda mouse pozisyonuna gore butonun icerisinde olup olmadigi
kontrol edilir buna gore currentframe setlenir ve callback fonksiyonu cagrilir.
m_bReleased tusun basilip basilmadigi ifade eder. daha iyi bir goruntu icin
gereklidir.
*/
class Button : public SimObject
{
    public:
        Button(int x, int y, int w, int h, std::string id, void (*callback)());
        void draw();
        void update();
        void clean();
    private:
        enum button_state
        {
            MOUSE_OUT = 0,
            MOUSE_OVER = 1,
            CLICKED = 2
        };
        void (*m_callback)();
        bool m_bReleased = true;
};

#endif // BUTTON_H
