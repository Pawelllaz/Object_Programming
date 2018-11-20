#include <iostream>
#include <math.h>
#include <map>
#include "poly.h"
#include <sstream>
using namespace std;

poly::poly(double new_number)
{
	this->p[0] = new_number;
}
//================================================================
double &poly::operator[](const int i)
{
	return this->p[i];
}
//================================================================
poly poly::operator+ (const poly &po) const
{	
	poly new_poly;
	
	for (std::map<int, double>::const_iterator i = p.begin(); i != p.end(); ++i)
		new_poly.p[(*i).first] = (*i).second;

	for (std::map<int, double>::const_iterator i = po.p.begin(); i != po.p.end(); ++i)
	{
		new_poly.p[(*i).first] += (*i).second;
		if (new_poly.p[(*i).first] == 0) new_poly.p.erase((*i).first);
	}
	return new_poly;
}
//================================================================
poly operator* (const poly &p1,const poly &p2) 
{
	poly new_poly;

	for (std::map<int, double>::const_iterator i = p1.p.begin(); i != p1.p.end(); ++i)
	{
		for (std::map<int, double>::const_iterator j = p2.p.begin(); j != p2.p.end(); ++j)
		{
			int id = (*i).first + (*j).first;
			new_poly.p[id] = (*i).second * (*j).second;
			if (new_poly.p[id] == 0) new_poly.p.erase(id);
		}
	}
	return new_poly;
}
//================================================================
double poly::operator() (double x)
{
	double result = 0;
	for (std::map<int, double>::const_iterator i = p.begin(); i != p.end(); ++i)
		result += (*i).second * pow(x, (*i).first);
	return result;
}
//================================================================
ostream &operator<<(std::ostream &out, poly po)
{
	stringstream s;
	if (po.p.begin() == po.p.end()) return out << "0";
	for (std::map<int,double>::const_iterator i = --po.p.end(); i != po.p.begin() ; i--)
	{
		if ((*i).second != 0)
		{
			if ((*i).second != 1) s << (*i).second;
			if ((*i).first > 1)
			{
				s << "x^";
				s << (*i).first;
			}
			else s << "x";

			if ((*i).first - 1 != 0) s << " + ";
		}
	}

	if ((*po.p.begin()).second != 0)
	{
		s << " + ";
		s << (*po.p.begin()).second;
	}
	return out << s.str();
}
