#ifndef AI4GAMES_STATE_H
#define AI4GAMES_STATE_H

template <class Agent>
class State
{
public:
	virtual ~State();

	virtual void Enter(Agent* agent) = 0;
	virtual void Execute(Agent* agent) = 0;
	virtual void Exit(Agent*  agent) = 0;

}; // class State

#endif // AI4GAMES_STATE_H