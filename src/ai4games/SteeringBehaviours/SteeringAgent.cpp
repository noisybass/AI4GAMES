#include "SteeringBehaviours\SteeringAgent.h"

SteeringAgent::SteeringAgent()
: _position{ 0.0f, 0.0f }, _velocity{ 0.0f, 0.0f }, _mass{ 1.0f }, _maxSpeed{ 20.0f }, _target{ 0.0f, 0.0f }
{
	_steering =  new SteeringBehaviours();
}
SteeringAgent::SteeringAgent(Vector2 position, float mass, float maxSpeed)
: _position{ position }, _velocity{ 0.0f, 0.0f }, _mass{ mass }, _maxSpeed{ maxSpeed }, _target{ 0.0f, 0.0f }
{
	_steering = new SteeringBehaviours();
}

void SteeringAgent::Seek(Vector2 target)
{
	_target = target;
	_steering->SetSeekOn();
}
void SteeringAgent::Flee(Vector2 target, float fleePanicDistance)
{
	_target = target;
	_steering->SetFleeOn(fleePanicDistance);
}
void SteeringAgent::Arrive(Vector2 target, int arriveDeceleration)
{
	_target = target;
	_steering->SetArriveOn(arriveDeceleration);
}

void SteeringAgent::Update(float deltaTime)
{
	Vector2 steeringForce = _steering->Calculate(_target, _position, _velocity, _maxSpeed);

	// Acceleration = Force/Mass
	Vector2 accel = steeringForce / _mass;

	// Velocity = Acceleration*deltaTime
	_velocity = accel * deltaTime;

	// Velocity can not exceed the maximum velocity
	// _velocity.Truncate(_maxSpeed);

	// Position = PreviousPosition * Velocity*deltaTime
	_position += _velocity * deltaTime;

	// Update heading
	//if (_velocity.SqrMagnitude() > 0.0001f)
	//{
	//	_heading = Normalize(_velocity);
	//	//_side = _heading.Perpendicular();
	//}
}