#include <iostream>
#include "SecurityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent() :Student()
{
	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse, Degree degree)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	degree = SECURITY;
}

Degree SecurityStudent::getDegree()
{
	return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print()
		cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}