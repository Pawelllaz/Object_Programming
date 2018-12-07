#include "pch.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "employee.h"

using namespace std;

Employee::Employee(string new_name, string new_position, int new_age)
{
	this->name = new_name;
	this->Position = new_position;
	this->age = new_age;
}

Employee::Employee()
{
	this->age = 0;
	this->name = "";
	this->Position = "";
}
string Employee::output_elements()
{
	stringstream s;
	s << "Name: " << this->name << ", Position: " << this->Position << ", Age: " << this->age;
	return s.str();
}
/*Employee::~Employee()
{
	delete this;
}*/

