#include "vector.hpp"
#include <math.h>

VECT::Vector()
{
}

VECT::~Vector()
{
}

double VECT::getX(void)
{
	return this->x;
}
double VECT::getY(void)
{
	return this->y;
}
double VECT::getMagnitude(void)
{
	return sqrt((this->x * this->x) + (this->y * this->y));
}

void VECT::setX(double X)
{
	this->x = X;
}
void VECT::setY(double Y)
{
	this->y = Y;
}
void VECT::setXY(double X, double Y)
{
	this->x = X;
	this->y = Y;
}

void VECT::normalize(void)
{
	double length = this->getMagnitude();

	if (length > 0)
	{
		this->x /= length;
		this->y /= length;
	}
}
void VECT::scale(double N)
{
	this->x *= N;
	this->y *= N;
}

VECT VECT::operator+(const Vector &v) const
{
	Vector a;

	a.x = this->x + v.x;
	a.y = this->y + v.y;

	return a;
}
VECT VECT::operator*(const Vector &v) const
{
	Vector a;

	a.x = this->x * v.x;
	a.y = this->y * v.y;

	return a;
}
VECT VECT::operator/(const Vector &v) const
{
	Vector a;

	a.x = this->x / v.x;
	a.y = this->y / v.y;

	return a;
}
bool VECT::operator==(const Vector &v) const
{
	return (this->x == v.x && this->y == v.y);
}
bool VECT::operator!=(const Vector &v) const
{
	return (this->x != v.x && this->y != v.y);
}

void VECT::operator=(Vector const &v)
{
	this->x = v.x;
	this->y = v.y;
}