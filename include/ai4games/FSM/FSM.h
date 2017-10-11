#ifndef AI4GAMES_FSM_H
#define AI4GAMES_FSM_H

#include "FSM\State.h"

template <class Agent>
class FSM
{
public:
	FSM(Agent* agent) : _agent(agent), _currentState(nullptr) {}
	FSM(Agent* agent, State<Agent>* initialState) : _agent(agent), _currentState(initialState) {}

	void SetCurrentState(State<Agent>* state) { _currentState = state; }

	void Update()
	{
		if (_currentState)
			_currentState.Execute(_agent);
	}

	void ChangeState(State<Agent>* newState)
	{
		_currentState.Exit(_agent);
		_currentState = newState;
		_currentState.Enter(_agent);
	}
private:
	Agent* _agent;
	State<Agent>* _currentState;

}; // class FSM

#endif