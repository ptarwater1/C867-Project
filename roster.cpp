#include "roster.h"
using std::cout;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->students = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->students = new Student*[capacity];
}

Student * Roster::getStudentId(int index)
{
	return students[index];
}

void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		Degree degree;
		if (row[2] == 'C') degree = SECURITY;
		else if (row[2] == 'T') degree = NETWORKING;
		else if {row[2] == 'F') degree = SOFTWARE;
		else
		{
			cerr << "INVALID DEGREE. EXITING.\n";
			exit(-1);
		}
}
	int rhs = row.find(",");
	string sId = row.substr(0, rhs);

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	string fName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	string lName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	string eAddr = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	int sAge = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	int daysN1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	int daysN2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find("," lhs);
	int daysN3 = stoi(row.substr(lhs, rhs - lhs));
	
	add(sId, fName, lName, eAddr, sAge, daysN1, daysN2, daysN3, degree);
	}
	else
	{
		cerr << "Error. List had exceed max capacity.\n Exiting.":;
		exit(-1);
	}
}

void Roster::add(string sId, string fName, string lName, string eAddr, int sAge, int daysN1, int daysN2, int daysN3, Degree degree)
{
	int daysInCourse[Student::dayInCourseArraySize];
	daysInCourse[0] = daysN1;
	daysInCourse[1] = daysN2;
	daysInCourse[2] = daysN3;
	if (degree == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(fName, lName, eAddr, sAge, daysInCourse, degree);
	if (degree == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(fName, lName, eAddr, sAge, daysInCourse, degree)
	if (degree == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(fName, lName, eAddr, sAge, daysInCourse, degree);
}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->students)[i]->print();
}



const int MAX = 5;
int main() {
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Patrick,Tarwater,ptarwat@my.wgu.edu,26,30,60,45,SOFTWARE"
	};
	for (int i = 0; i < MAX; i++)
};