#ifndef _VECTOR_H
#define _VECTOR_H
#include "utillity.hpp"
#include <vector>

#define VECT ykes::Vector

namespace ykes
{

	class Vector
	{
	    private:
		double x;
		double y;

	    public:
		Vector();
		Vector(double x, double y) : x(x), y(y) {};
		~Vector();

		double getX(void);
		double getY(void);
		double getMagnitude(void);

		void setX(double X);
		void setY(double Y);
		void setXY(double X, double Y);

		void normalize(void);
		void scale(double N);

		Vector operator+(const Vector &v) const;
		Vector operator*(const Vector &v) const;
		Vector operator/(const Vector &v) const;
		bool   operator==(const Vector &v) const;
		bool   operator!=(const Vector &v) const;
	};
} // namespace ykes

#endif
