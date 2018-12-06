#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

using namespace std;

class Employee
{
private:
	string name;
	string Position;
	int age;
public:
	Employee(string, string, int);
	~Employee();
};



#endif // !__EMPLOYEE_H__
