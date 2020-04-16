#include <iostream>
#include "NetworkStudent.h"
using std::cout;


NetworkStudent::NetworkStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	: Student(StudentId, firstName, lastName, emailAddress, age, daysInCourse)
{
	degree = NETWORK;
}

NetworkStudent::NetworkStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse, Degree degree)
{
}

Degree NetworkStudent::getDegree()
{
	return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}
