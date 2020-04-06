#include <iostream>
#include "student.h"
using std::left;
using std::cout;
using std::setw;

//Constructors
Student::Student() 
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[])
	:studentId(studentId), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), daysInCourse(new int[daysInCourseArraySize])
{
	for (int i = 0; i < daysInCourseArraySize; ++i) this->daysInCourse[i] = daysInCourse[i];
}

//Accessors
string Student::getStudentId() {
	return studentId;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}

//Mutators
void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAdress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseArraySize; ++i) 
	this->daysInCourse[i] = daysInCourse[i];
}

void Student::print() {
	cout << getStudentId();
	cout << "\tFirst Name: " << getFirstName();
	cout << "\tLast Name: " << getLastName();
	cout << "\tAge: " << getAge();

	int* days = getDaysInCourse();
	cout << "\t Days in course: " << days[0] << ", " << days[1] << ", " << days[2];

	string degreeString = "";
	switch (getDegree()) {
	case NETWORK:
		degreeString = "SECURITY";
		break;
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case NETWORK:
		degreeString = "SOFTWARE";
		break;
	}
	cout << "\tDegree: " << degreeString << endl;
}

//Destructor
Student::~Student() {

}