#include "roster.h"
using std::cout;
using std::cerr;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

Student* Roster::getStudentId(int index)
{
	return classRosterArray[index];
}

void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degree;
		if (row[1] == '1') degree = SECURITY;
		else if (row[1] == '2') degree = NETWORK;
		else if (row[1] == '3') degree = SOFTWARE;
		else if (row[1] == '4') degree = SECURITY;
		else if (row[1] == '5') degree = SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE. EXITING.\n";
			exit(-1);
		}
	}
	int rhs = row.find(",");
	string sId = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string fName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string eAddr = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int sAge = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysN1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysN2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysN3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string degree = row.substr(lhs, rhs - lhs);
	Degree degreesp;
	if (degree == "SECURITY") {
		degreesp = SECURITY;
	}
	else if (degree == "NETWORK") {
		degreesp = NETWORK;
	}
	else {
		degreesp = SOFTWARE;
	}

	add(sId, fName, lName, eAddr, sAge, daysN1, daysN2, daysN3, degreesp);

}

void Roster::add(string sId, string fName, string lName, string eAddr, int sAge, int daysN1, int daysN2, int daysN3, Degree degreesp)
{
	int daysInCourse[3];
	daysInCourse[0] = daysN1;
	daysInCourse[1] = daysN2;
	daysInCourse[2] = daysN3;
	if (degreesp == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sId, fName, lName, eAddr, sAge, daysInCourse, degreesp);
	else if (degreesp == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(sId, fName, lName, eAddr, sAge, daysInCourse, degreesp);
	else if (degreesp == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sId, fName, lName, eAddr, sAge, daysInCourse, degreesp);
}


void Roster::remove(string studentId) {
	cout << "Remove student from roster by Id: " << studentId << "..." << endl;
	for (int i = 0; i < lastIndex; i++) {
		if (classRosterArray[i] == nullptr) {
			cout << "Error. Student Id not found." << endl;
		}
		else if (studentId == classRosterArray[i]->getStudentId()) {
			classRosterArray[i] = nullptr;
			cout << "Student has been removed." << endl;
		}
	}
}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::printAverageDaysInCourse(string StudentId) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentId() == StudentId) {
			found = true;
			const int* days = classRosterArray[i]->getDaysInCourse();
			cout << days[0] << ", " << days[1] << ", " << days[2] << ", " << endl;
			cout << "Average days in course: " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}

	if (found == false) {
		cout << "Student with this Id not found." << endl;
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++) {
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(".") == string::npos || emailAddress.find(" ") != string::npos)) {
			cout << "Email Address for: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid. " << emailAddress << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeprogram)
{
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegree() == degreeprogram) {
			classRosterArray[i]->print();
		}
	}  cout << endl;
}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}


int main() {

	cout << "C867: Scripting and Programming Applications." << endl;
	cout << "Built with C++." << endl;
	cout << "Patrick Tarwater - ID: #000919107." << endl;
	cout << endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Patrick,Tarwater,ptarwat@my.wgu.edu,26,30,60,45,SOFTWARE"
	};

	int classSize = 5;

	Roster* classRoster = new Roster(classSize);

	for (int i = 0; i < classSize; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	cout << "All Students:" << endl;

	classRoster->printAll();
	cout << endl;


	classRoster->printInvalidEmails();
	cout << endl;

	cout << "Printing average days for student A1." << endl;
	classRoster->printAverageDaysInCourse("A1");
	cout << endl;

	cout << "Printing all software students." << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	classRoster->remove("A3");

	classRoster->remove("A3");

	classRoster->~Roster();

}


