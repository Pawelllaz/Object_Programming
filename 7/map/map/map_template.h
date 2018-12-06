#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__

#include <iostream>
#include <map>
#include "employee.h"

using namespace std;

template<typename T1, class Employee emp>
class map_template
{
private:
	std::map<T1 id, class Employee emp> mapa;
public:
	map_template();
	map_template(const class map_template&);
	void Add(T1, class Employee);
};




// http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node129.html
// https://4programmers.net/C/Szablony_klas
// http://cpp0x.pl/kursy/Kurs-C++/Szablony-klas/317

#endif __MAP_TEMPLATE_H__
