#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <math.h>
class Vector2D {
public:
	Vector2D(float x, float y);
	float getX();
	float getY();
	void setX(float x);
	void setY(float x);

	float length();
	
	Vector2D operator+(const Vector2D& v2) const;
	Vector2D operator-(const Vector2D& v2) const;
	Vector2D operator*(float scalar);
	Vector2D operator/(float scalar);

	Vector2D operator*=(float scalar);
	Vector2D operator/=(float scalar);

	void normalize();

	friend Vector2D operator+=(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator-=(Vector2D& v1, const Vector2D& v2);

private:
	float m_x;
	float m_y;
};
#endif // !VECTOR2D_H