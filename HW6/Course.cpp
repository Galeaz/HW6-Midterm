// Participants: Long Duong, Gabriela Lopez and Duyen Tran
// Date: 03-30-21
// Description: course implementation

#include "option3/Course.h"
#include <cassert>
using namespace std;

// accesors - mutators
int Course::getStudentPosition(int ID) { return 1; }
int Course::getStudentID(string name) { return 1; }
string Course::getStudentName(int position){ return "1"; }
double Course::getStudentScores(int position){ return 1; }
char Course::getStudentGrade(int position){ return 1; }

void Course::setCourseName(string newCourseName)
{
	courseName = newCourseName;
}

void Course::setStudentID(int newID)
{
	studentIDs = newID;
}

void Course::setStudentName(string newName)
{
	//studentNames = newName;
}

void Course::setStudentScores(double newScore)
{
	studentScores = newScore;
}

void Course::setStudentGrade(double theScore)
{
	if (theScore >= 90)
		studentGrades = 'A';
	else if (theScore >=80)
		studentGrades = 'B';
	else if (theScore >= 70)
		studentGrades = 'C';
	else if (theScore >= 60)
		studentGrades = 'D';
	else
		studentGrades = 'F';
}

void Course::addNewStudent(int ID, string name, double studentScore, char studentGrade)
{
	studentIDs.insert(ID);
	studentNames.insert(name);
	studentScores.insert(studentScore);
	studentGrades.insert(studentGrade);
}

Course Course::loadFileToCourses(int numberOfCourses)
{
	string fileName;
	ifstream file;
	string data;
	Course newCourse;
	MyBag<Course> theBag;
	int counter = 1;
	do
	{
		cout << "\nEnter a data file name for course[0] (STOP - return): ";
		cin >> fileName;
		if (fileName == "STOP")
			break;
		else
		{
			file.open(fileName);
			if (file.fail())
				cout << "ERROR: The file does not found.\n";
			else
			{
				while (!file.eof())
				{
					getline(file, data, '\n');
					newCourse.setCourseName(data);
					getline(file, data, ',');
					newCourse.setStudentID(stoi(data));
					getline(file, data, ',');
					newCourse.setStudentName(data);
					getline(file, data, ',');
					newCourse.setStudentScores(stod(data));
					newCourse.setStudentGrade(stod(data));
					if (file.eof())
						break;
					//else clean getline? has to have a \n
				}
				file.close();
				theBag.insert(newCourse);
				cout << "Data from file, " << fileName << ", has been read and stored into Courses[" << (counter - 1) << "].\n";
				counter++;
			}
		}
	} while (counter != numberOfCourses);
	return newCourse;

}

bool Course::searchStudentWithID(int ID)
{
	int position = 0;
	return studentIDs.search(ID, position); // WHY DO WE NEED A POSITION IN SEARCHING? **********************************************************
}

int Course::searchStudentWithName(std::string name) {
	int position = 0;
	if (studentNames.search(name, position)) {
		return studentIDs.at(position);
	}
	else { return -1; }
}

/// WORK IN PROGRRRREEESSSSSS

string Course::getStudentNameByID(int ID)
{
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentNames.at(pos);
}
double Course::getStudentScoreByID(int ID){ 
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentScores.at(pos);
}
char Course::getStudentGradesByID(int ID){ 
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentGrades.at(pos);
}

void Course::deleteStudentByID(int ID){
	int index = -1;
	studentIDs.search(ID, index);
	assert(index != -1);
	studentIDs.removeAtIndex(index);
	studentNames.removeAtIndex(index);
	studentScores.removeAtIndex(index);
	studentGrades.removeAtIndex(index);
}
void Course::deleteStudentByName(std::string name) {
	int index = -1;
	studentNames.search(name, index);
	assert(index != -1);
	studentIDs.removeAtIndex(index);
	studentNames.removeAtIndex(index);
	studentScores.removeAtIndex(index);
	studentGrades.removeAtIndex(index);
}



ostream& operator<< (ostream& os, const Course& obj)
{
	os << "Index:\tID:\tName:\tScore:\tGrade:";
	for (int i = 0; i < obj.studentIDs.getSize(); i++)
	{
		os << '\n' << i << '\t';
		os << obj.studentIDs << '\t';
		os << obj.studentNames << '\t';
		os << obj.studentScores << '\t';
		os << obj.studentGrades << '\t';
	}
	return os;
}