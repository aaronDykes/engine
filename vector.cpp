#include "vector.hpp"
#include <math.h>

ykes::Vector::Vector()
{
}

ykes::Vector::~Vector()
{
}

double ykes::Vector::getX(void)
{
	return this->x;
}
double ykes::Vector::getY(void)
{
	return this->y;
}
double ykes::Vector::getMagnitude(void)
{
	return sqrt((this->x * this->x) + (this->y * this->y));
}

void ykes::Vector::setX(double X)
{
	this->x = X;
}
void ykes::Vector::setY(double Y)
{
	this->y = Y;
}
void ykes::Vector::setXY(double X, double Y)
{
	this->x = X;
	this->y = Y;
}

void ykes::Vector::normalize(void)
{
	double length = this->getMagnitude();

	if (length > 0)
	{
		this->x /= length;
		this->y /= length;
	}
}
void ykes::Vector::scale(double N)
{
	this->x *= N;
	this->y *= N;
}

ykes::Vector ykes::Vector::operator+(const Vector &v) const
{
	Vector a;

	a.x = this->x + v.x;
	a.y = this->y + v.y;

	return a;
}
ykes::Vector ykes::Vector::operator*(const Vector &v) const
{
	Vector a;

	a.x = this->x * v.x;
	a.y = this->y * v.y;

	return a;
}
ykes::Vector ykes::Vector::operator/(const Vector &v) const
{
	Vector a;

	a.x = this->x / v.x;
	a.y = this->y / v.y;

	return a;
}
bool ykes::Vector::operator==(const Vector &v) const
{
	return (this->x == v.x && this->y == v.y);
}
bool ykes::Vector::operator!=(const Vector &v) const
{
	return (this->x != v.x && this->y != v.y);
}

void ykes::Vector::operator=(Vector const &v)
{
	x = v.x;
	y = v.y;
}