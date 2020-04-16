#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster {
private:
	int lastIndex;
	int capacity;
	Student** classRosterArray;

public:
	Roster();
	Roster(int capacity);

	Student* getStudentId(int index);
	void parseThenAdd(string datarow);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysN1, int daysN2, int daysN3, Degree);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeprogram);

	~Roster();
};