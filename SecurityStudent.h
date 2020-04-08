#pragma once
#include "student.h"
#include <string>

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(string StudentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree);
	SecurityStudent(
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

	~SecurityStudent();
};