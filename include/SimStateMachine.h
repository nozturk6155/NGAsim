#ifndef SIMSTATEMACHINE_H
#define SIMSTATEMACHINE_H
#include <vector>
#include "SimState.h"


class SimStateMachine
{
    public:
        void update();
        void render();
        void pushState(SimState* pState);
        void changeState(SimState* pState);
        void popState();
        std::vector<SimState*> getStateVector()
        {
            return m_simStates;
        }
    private:
        std::vector<SimState*> m_simStates;
};

#endif // SIMSTATEMACHINE_H
