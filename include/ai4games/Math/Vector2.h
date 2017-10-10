#ifndef LOGIC_MATH_H
#define LOGIC_MATH_H

struct Vector2
{
	float x, y;

	Vector2();
	Vector2(float a, float b);
	~Vector2() = default;

	float Magnitude() const;
	float SqrMagnitude() const;
	void Normalize();
};

Vector2& operator+=(Vector2& a, const Vector2& b);
Vector2& operator-=(Vector2& a, const Vector2& b);
Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);
Vector2 operator*(float a, const Vector2& b);
Vector2 operator*(const Vector2& a, float b);
Vector2& operator*=(Vector2& a, float b);
Vector2 operator/(const Vector2& a, float b);
Vector2& operator/=(Vector2& a, float b);
bool operator==(const Vector2& a, const Vector2& b);
bool operator!=(const Vector2& a, const Vector2& b);

Vector2 Normalize(Vector2 v);
float Magnitude(const Vector2& v);
float SqrMagnitude(const Vector2& v);
float Dot(const Vector2& a, const Vector2& b);
float Angle(const Vector2& a, const Vector2& b);
float Distance(const Vector2& a, const Vector2& b);
float SquaredDistance(const Vector2& a, const Vector2& b);

Vector2 Lerp(const Vector2& a, const Vector2& b, float t);

#endif // LOGIC_MATH_H