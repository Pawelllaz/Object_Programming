#include <string.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "employee.h"

using namespace std;

Employee::Employee(string new_name = "", string new_position = "", int new_age = 0)
{
	this->Name = new_name;
	this->Position = new_position;
	this->Age = new_age;
}

Employee::Employee()
{
	this->Name = "";
	this->Position = "";
	this->Age = 0;
}

string Employee::output_elements()
{
	stringstream s;
	s << "Name: " << this->Name << ", Position: " << this->Position << ", Age: " << this->Age;
	return s.str();
}


