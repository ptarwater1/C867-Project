#pragma once
#include "student.h"
#include <string>

class NetworkStudent : public Student
{
public:
	NetworkStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree);
	NetworkStudent(
		string StudentId,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse,
		Degree degree
	);
	Degree getDegree();
	void print();

};
