#ifndef __POLY_H__
#define __POLY_H__
#include <iostream>
#include <math.h>
#include <map>

using namespace std;

class poly
{
private:
	map<int, double> p;
public:
	double &operator[] (const int i);
	friend std::ostream &operator<<(std::ostream &out, poly & po)
	{
		po.p.begin(); // a tu widzi 
	}

	poly(double new_number=0);
};

#endif /* __POLY_H__ */
