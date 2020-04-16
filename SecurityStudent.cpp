#include <iostream>
#include "SecurityStudent.h"
using std::cout;



SecurityStudent::SecurityStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	: Student(StudentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	degree = SECURITY;
}

Degree SecurityStudent::getDegree()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

