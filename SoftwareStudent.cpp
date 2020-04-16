#include <iostream>
#include "SoftwareStudent.h"
using std::cout;


SoftwareStudent::SoftwareStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	: Student(StudentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	degree = SOFTWARE;
}

Degree SoftwareStudent::getDegree()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

