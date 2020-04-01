#include <iostream>
#include "student.h"
using namespace std;

//Constructors
Student::Student()
	: studentId(""), firstName(""), lastName(""), emailAddress(""), age(-1), daysInCourse(new int[daysInCourseArraySize])
{
	for (int i = 0; i < daysInCourseArraySize; ++1) {
		this->daysInCourse[i] = 0;
	}
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	:studentId(studentId), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), daysInCourse(new int[daysInCourseArraySize])
{
	for (int i = 0; i < daysInCourseArraySize; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

//Accessors
string Student::getStudentId() const {
	return studentId;
}

string Student::getFirstName() const {
	return firstName;
}

string Student::getLastName() const {
	return lastName;
}

string Student::getEmailAddress() const {
	return emailAddress;
}

int Student::getAge() const {
	return age;
}

int* Student::getDaysInCourse() const {
	return daysInCourse;
}

Degree Student::getDegree() {
	return degree;
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
	this->daysInCourse = new int[daysInCourseArraySize];
	for (int i = 0; i < daysInCourseArraySize; ++i) this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegree(Degree degree) {
	this->degree = degree;
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