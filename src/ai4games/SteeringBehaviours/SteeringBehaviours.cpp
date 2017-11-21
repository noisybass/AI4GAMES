#include "SteeringBehaviours\SteeringBehaviours.h"

SteeringBehaviours::SteeringBehaviours() : _type{ NONE }, _fleePanicDistance{ 0.0f }, _arriveDeceleration{ 1 } {}

void SteeringBehaviours::SetSeekOn()
{
	_type = SEEK;
}
void SteeringBehaviours::SetFleeOn(float fleePanicDistance)
{
	_type = FLEE;
	_fleePanicDistance = fleePanicDistance;
}
void SteeringBehaviours::SetArriveOn(int arriveDeceleration)
{
	_type = ARRIVE;
	_arriveDeceleration = arriveDeceleration;
}

Vector2 SteeringBehaviours::Seek(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	Vector2 desiredVelocity = Normalize(targetPos - sourcePos) * maxSpeed;

	return desiredVelocity - sourceVelocity;
}

Vector2 SteeringBehaviours::Flee(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	if (_fleePanicDistance && SquaredDistance(sourcePos, targetPos) > _fleePanicDistance*_fleePanicDistance)
	{
		return Vector2();
	}

	Vector2 desiredVelocity = Normalize(sourcePos - targetPos) * maxSpeed;

	return desiredVelocity - sourceVelocity;
}

Vector2 SteeringBehaviours::Arrive(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	float distance = Distance(sourcePos, targetPos);

	if (distance > 0)
	{
		const float deceletarionTweaker = 0.3f;

		float speed = distance / _arriveDeceleration * deceletarionTweaker;

		if (speed > maxSpeed)
		{
			speed = maxSpeed;
		}

		Vector2 desiredVelocity = (sourcePos - targetPos) * speed / distance;

		return desiredVelocity - sourceVelocity;
	}
}

Vector2 SteeringBehaviours::Calculate(Vector2 targetPos, Vector2 sourcePos, Vector2 sourceVelocity, float maxSpeed) const
{
	switch (_type)
	{
	case SEEK:
		return Seek(targetPos, sourcePos, sourceVelocity, maxSpeed);
		break;
	case FLEE:
		return Flee(targetPos, sourcePos, sourceVelocity, maxSpeed);
		break;
	case ARRIVE:
		return Arrive(targetPos, sourcePos, sourceVelocity, maxSpeed);
		break;
	default:
		break;
	}
}