#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

using namespace std;

class Employee
{
public:
	string Name;
	string Position;
	int Age;
	Employee();
	Employee(string, string, int);
	string output_elements();
};



#endif // !__EMPLOYEE_H__
