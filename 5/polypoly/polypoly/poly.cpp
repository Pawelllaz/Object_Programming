#include "pch.h"
#include <iostream>
#include <math.h>
#include <map>
#include "poly.h"

using namespace std;

double &poly::operator[](const int i)
{
	return this->p[i];
}


poly::poly(double new_number)
{
	this->p[0] = new_number;
}

ostream &operator<<(ostream &out, poly po)
{
    string s = "";
    for(map<int,double>::const_iterator i = po.p.begin(); i!=po.p.end(); i++)
    {
        if((*i).second!=0) s += (*i).second.str();

    }
}
