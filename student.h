#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[];
	Degree degree;

public:
	//Constructors
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse[], Degree degree);
	const static int dayInCourseArraySize = 3;

	//Accessors
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getDaysInCourse() const;
	virtual Degree getDegree() = 0;

	//Mutators
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAdress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(Degree degree);

	virtual void print();

	//Destructor
	~Student();
};

