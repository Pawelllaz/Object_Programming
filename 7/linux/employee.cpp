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
Employee::~Employee()
{
	delete[] this;
}

