#include "Math\Vector2.h"

#include <cmath>

Vector2::Vector2() : x{ 0.0f }, y{ 0.0f } {}

Vector2::Vector2(float a, float b) : x{ a }, y{ b } {}

float Vector2::Magnitude() const
{
	return std::sqrtf(x*x + y*y);
}

float Vector2::SqrMagnitude() const
{
	return x*x + y*y;
}

void Vector2::Normalize()
{
	float magnitude = Magnitude();
	x = x / magnitude;
	y = y / magnitude;
}


//////////////////////////////////////////////////////////////////////


Vector2& operator+=(Vector2& a, const Vector2& b)
{
	a.x += b.x;
	a.y += b.y;

	return a;
}

Vector2& operator-=(Vector2& a, const Vector2& b)
{
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

Vector2 operator+(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2& a, const Vector2& b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator*(float a, const Vector2& b)
{
	return Vector2(a*b.x, a*b.y);
}

Vector2 operator*(const Vector2& a, float b)
{
	return Vector2(a.x*b, a.y*b);
}

Vector2& operator*=(Vector2& a, float b)
{
	a.x *= b;
	a.y *= b;

	return a;
}
Vector2 operator/(const Vector2& a, float b)
{
	return Vector2(a.x/b, a.y/b);
}

Vector2& operator/=(Vector2& a, float b)
{
	a.x /= b;
	a.y /= b;

	return a;
}

bool operator==(const Vector2& a, const Vector2& b)
{
	return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vector2& a, const Vector2& b)
{
	return a.x != b.x || a.y != b.y;
}

Vector2 Normalize(Vector2 v)
{
	v.Normalize();
	return v;
}
float Magnitude(const Vector2& v)
{
	return v.Magnitude();
}

float SqrMagnitude(const Vector2& v)
{
	return v.SqrMagnitude();
}

float Dot(const Vector2& a, const Vector2& b)
{
	return a.x*b.x + a.y*b.y;
}

float Angle(const Vector2& a, const Vector2& b)
{
	return std::acosf(Dot(Normalize(a), Normalize(b)));
}

float Distance(const Vector2&a, const Vector2& b)
{
	return Magnitude(a - b);
}

float SquaredDistance(const Vector2& a, const Vector2& b)
{
	return SqrMagnitude(a - b);
}

Vector2 Lerp(const Vector2& a, const Vector2& b, float t)
{
	return (b - a)*(t > 1.0f ? 1.0f : t) + a;
}