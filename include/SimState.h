#ifndef SIMSTATE_H
#define SIMSTATE_H
#include <string>
/*
********************ABSTRACT CLASS************************
SimState Abstract classi stateleri fonksiyonlara parametre
olarak verebilmek için ve diger butun state classlari icin
bir blueprint olmasi icin yaratildi: Butun state classlari
asagidaki fonksiyonlari icermek zorundadir.
*/
class SimState
{
    public:
        virtual void update() = 0;
        virtual void render() = 0;
        virtual bool onEnter() = 0;
        virtual bool onExit() = 0;
        virtual std::string getStateID() const = 0;
};

#endif // SIMSTATE_H
