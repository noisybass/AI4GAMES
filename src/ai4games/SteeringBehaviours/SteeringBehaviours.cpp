#include "SteeringBehaviours\SteeringBehaviours.h"

Vector2 SteeringBehaviours::Seek(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	Vector2 desiredVelocity = Normalize(targetPos - sourcePos) * maxSpeed;

	return desiredVelocity - sourceVelocity;
}

Vector2 SteeringBehaviours::Flee(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	Vector2 desiredVelocity = Normalize(sourcePos - targetPos) * maxSpeed;

	return desiredVelocity - sourceVelocity;
}

Vector2 SteeringBehaviours::Arrive(Vector2 targetPos) const
{

}

Vector2 SteeringBehaviours::Calculate() const
{

}