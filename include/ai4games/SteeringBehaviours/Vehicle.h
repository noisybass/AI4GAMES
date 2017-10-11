#ifndef VEHICLE_H
#define VEHICLE_H

#include "Math\Vector2.h"
#include "SteeringBehaviours\SteeringBehaviours.h"

class Vehicle
{
public:
	void Update(float deltaTime);
private:
	Vector2 _position;
	Vector2 _velocity;
	Vector2 _heading;
	Vector2 _side; // perpendicular to the heading vector

	float _mass;
	float _maxSpeed;
	float _maxForce;
	float _maxTurnRate;

	SteeringBehaviours* _steering;

};

#endif // VEHICLE_H