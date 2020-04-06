#pragma once
#include <string>
#include "degree.h"
using std::string;


class Student {
public:
	const static int daysInCourseArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArraySize];
	Degree degree;

public:
	//Constructors
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse[]);
	
	//Accessors
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	virtual Degree getDegree() = 0;

	//Mutators
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAdress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	
	virtual void print() = 0;

	//Destructor
	~Student();
};

