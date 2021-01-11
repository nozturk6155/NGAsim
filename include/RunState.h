#ifndef RUNSTATE_H
#define RUNSTATE_H
#include <vector>
#include "SimState.h"
#include "SimObject.h"

class RunState : public SimState
{
    public:
        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();
        virtual std::string getStateID() const { return s_runID; }
        static void restartToRun();
        static void resetToMain();
    private:
        static const std::string s_runID;
        std::vector<SimObject*> m_simObject;

};

#endif // RUNSTATE_H
