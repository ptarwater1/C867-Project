#include <iostream>
#include <iomanip>
#include "student.h"
using std::left;
using std::setw;
using std::cout;

//Constructors
Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[])
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
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

void Student::print() 
{
	cout << left << setw(4) << studentId;
	cout << left << setw(10) << firstName;
	cout << left << setw(10) << lastName;
	cout << left << setw(25) << emailAddress;
	cout << left << setw(4) << age;
	cout << left << setw(4) << daysInCourse[0];
	cout << left << setw(4) << daysInCourse[1];
	cout << left << setw(4) << daysInCourse[2];
}

//Destructor
Student::~Student() 
{

}