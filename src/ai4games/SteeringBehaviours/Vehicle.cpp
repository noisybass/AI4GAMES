#include "SteeringBehaviours\Vehicle.h"

void Vehicle::Update(float deltaTime)
{
	Vector2 steeringForce = _steering->Calculate();

	// Acceleration = Force/Mass
	Vector2 accel = steeringForce / _mass;

	// Velocity = Acceleration*deltaTime
	_velocity = accel * deltaTime;

	// Velocity can not exceed the maximum velocity
	// _velocity.Truncate(_maxSpeed);

	// Position = PreviousPosition * Velocity*deltaTime
	_position += _velocity * deltaTime;

	// Update heading
	if (_velocity.SqrMagnitude() > 0.0001f)
	{
		_heading = Normalize(_velocity);
		//_side = _heading.Perpendicular();
	}
}