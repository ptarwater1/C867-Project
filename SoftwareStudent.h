#pragma once
#include "student.h"
#include <string>

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree);
	SoftwareStudent(
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

	~SoftwareStudent();
};