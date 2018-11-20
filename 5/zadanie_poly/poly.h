#ifndef __POLY_H__
#define __POLY_H__
#include <iostream>
#include <map>

using namespace std;

class poly
{
private:
	std::map<int, double> p;
public:
	poly(double new_number = 0);
	double &operator[] (const int i);
	poly operator+ (const poly &po) const;
	double operator() (double x);
	friend poly operator* (const poly &p1, const poly &p2);
	friend std::ostream &operator<<(std::ostream &out, poly po);
};

#endif /* __POLY_H__ */
