#include "SimStateMachine.h"

//vector.empty()-->It determines whether the vector is empty or not.
//vector.back()-->It gives a reference to the last element.
//vector.push_back()-->It adds a new element at the end.
//vector.pop_back()-->It removes a last element from the vector.

void SimStateMachine::update()
{
    if( !m_simStates.empty() )
    {
         m_simStates.back()->update();
    }
}

void SimStateMachine::render()
{
    if(!m_simStates.empty())
    {
        m_simStates.back()->render();
    }
}

void SimStateMachine::pushState(SimState *pState)
{
    m_simStates.push_back(pState);
    m_simStates.back()->onEnter();
}

void SimStateMachine::changeState(SimState *pState)
{
    if(!m_simStates.empty())
    {
        if(m_simStates.back()->getStateID() == pState->getStateID())
        {
            return; // do nothing
        }
        if(m_simStates.back()->onExit())
        {
            delete m_simStates.back();
            m_simStates.pop_back();

        }
    }
    // push back our new state
    m_simStates.push_back(pState);
    // initialize it
    m_simStates.back()->onEnter();
}


void SimStateMachine::popState()
{
    if(!m_simStates.empty())
    {
        if(m_simStates.back()->onExit())
        {
            delete m_simStates.back();
            m_simStates.pop_back();
        }
    }
}
