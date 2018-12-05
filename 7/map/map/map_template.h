#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__

#include <iostream>
#include <map>
#include "employee.h"

using namespace std;

template<typename id, class Employee>class map_template
{
private:
	std::map<typename id, class Employee> mapa;
public:
	map_template();
	map_template(const class map_template& m);
	void Add(unsigned int, class Employee);
};
// http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node129.html
// https://4programmers.net/C/Szablony_klas


#endif __MAP_TEMPLATE_H__