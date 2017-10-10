#ifndef AI4GAMES_STATE_H
#define AI4GAMES_STATE_H

class State
{
public:
	~virtual State();

	virtual void Enter() = 0;
	virtual void Execute() = 0;
	virtual void Exit() = 0;

}; // class State

#endif // AI4GAMES_STATE_H