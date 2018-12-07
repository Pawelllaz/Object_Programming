#ifndef __MAPTEMPLATE_H__
#define __MAPTEMPLATE_H__

#include <iostream>
#include <map>
#include <sstream>
#include "employee.h"

using namespace std;

template<typename T1, typename T2>
class map_template
{
private:
	map<T1, T2> mp;
public:
	void Add(T1, T2);
	friend ostream& operator<<(ostream& o, const map_template<T1, T2>& m)
	{
		stringstream s;
		//s << "test";
		Employee temp_emp;
		for(typename map<T1, T2>::const_iterator i = m.mp.begin(); i!=m.mp.end(); i++)
		{
			temp_emp = m.mp.at((*i).first);
			s << "ID: " <<(*i).first << " --> " << temp_emp.output_elements()<<endl;
		}
		return o << s.str();
	}

};

template<typename T1, typename T2>
inline void map_template<T1, T2>::Add(T1 id, T2 employee)
{
	this->mp.insert(pair<T1, T2>(T1(id),T2(employee)));
}

//template<typename T1, typename T2>
//ostream & operator<<(ostream &o, const map_template<T1, T2>& m)

#endif // !__MAPTEMPLATE_H__
