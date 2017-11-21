#ifndef VEHICLE_H
#define VEHICLE_H

#include "Math\Vector2.h"
#include "SteeringBehaviours\SteeringBehaviours.h"

class SteeringAgent
{
public:
	SteeringAgent();
	SteeringAgent(Vector2 position, float mass, float maxSpeed);

	Vector2 Position() const { return _position; }

	void Seek(Vector2 target);
	void Flee(Vector2 target, float fleePanicDistance);
	void Arrive(Vector2 target, int arriveDeceleration);

	void Update(float deltaTime);
private:
	Vector2 _position;
	Vector2 _velocity;
	//Vector2 _heading;
	//Vector2 _side; // perpendicular to the heading vector

	float _mass;
	float _maxSpeed;
	//float _maxForce;
	//float _maxTurnRate;

	Vector2 _target;
	SteeringBehaviours* _steering;

};

#endif // VEHICLE_H