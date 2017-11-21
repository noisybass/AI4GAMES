#ifndef STEERING_BEHAVIOURS_H
#define STEERING_BEHAVIOURS_H

#include "Math\Vector2.h"

class SteeringBehaviours
{
public:
	SteeringBehaviours();

	void SetSeekOn();
	void SetFleeOn(float fleePanicDistance);
	void SetArriveOn(int arriveDeceleration);

	Vector2 Calculate(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;

private:
	Vector2 Seek(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;
	Vector2 Flee(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;
	Vector2 Arrive(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;

	enum SteeringType
	{
		SEEK,
		FLEE,
		ARRIVE,
		NONE
	};

	SteeringType _type;
	float _fleePanicDistance;
	int _arriveDeceleration;

}; // class SteeringBehaviours

#endif // STEERING_BEHAVIOURS_H