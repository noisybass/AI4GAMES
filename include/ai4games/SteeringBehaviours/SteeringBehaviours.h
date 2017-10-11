#ifndef STEERING_BEHAVIOURS_H
#define STEERING_BEHAVIOURS_H

#include "Math\Vector2.h"

class SteeringBehaviours
{
public:
	Vector2 Seek(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;
	Vector2 Flee(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const;
	Vector2 Arrive(Vector2 targetPos) const;

	Vector2 Calculate() const;

}; // class SteeringBehaviours

#endif // STEERING_BEHAVIOURS_H