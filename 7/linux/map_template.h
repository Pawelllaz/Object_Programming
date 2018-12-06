#ifndef __MAP_TEMPLATE_H__
#define __MAP_TEMPLATE_H__

#include <iostream>
#include <map>
#include "employee.h"
#include <sstream>
//#include <typeinfo>
using namespace std;

template<typename T1, typename T2>
class map_template
{
private:
	std::map<T1, T2> mapa;
public:
	//map_template(const class map_template&);
	void Add(unsigned int, class Employee);
	friend std::ostream& operator<<(std::ostream&, const map_template<T1, T2>&);
};
	
template<typename T1, typename  T2>
inline void map_template<T1, T2>::Add(unsigned int i, class Employee emp)
{
	this->mapa.insert(i, emp);
}

/*template<typename T1, typename T2>
map_template<T1, T2>::map_template(const class map_template& m)
{
	this->mapa = m;
}*/

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream &o, const map_template<T1, T2>&m)
{
	stringstream s;
	s << "asd";
	/*for (std::map<T1, T2>::const_iterator i = mapa.begin(); i != mapa.end(); i++)
	{
		
	}*/
	return s.str();
}

// http://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node129.html
// https://4programmers.net/C/Szablony_klas
// http://cpp0x.pl/kursy/Kurs-C++/Szablony-klas/317

#endif __MAP_TEMPLATE_H__
