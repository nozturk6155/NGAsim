#ifndef MAINSTATE_H
#define MAINSTATE_H
#include <vector>
#include "SimState.h"
#include "SimObject.h"

class MainState : public SimState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        virtual std::string getStateID() const { return s_mainID; }
        static void startToRun();
    private:
        static const std::string s_mainID;
        std::vector<SimObject*> m_simObject;

};

#endif // MAINSTATE_H
