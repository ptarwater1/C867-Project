#include <iostream>
#include "SoftwareStudent.h"
using std::cout;

SoftwareStudent::SoftwareStudent() :Student()
{
	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse, Degree degree)
	: Student(studentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	degree = SOFTWARE;
}

Degree SoftwareStudent::getDegree()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print()
		cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
