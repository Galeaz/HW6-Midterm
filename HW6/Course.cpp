// Participants: Long Duong, Gabriela Lopez and Duyen Tran
// Date: 03-30-21
// Description: course implementation

#include "option3/Course.h"
using namespace std;

void Course::addNewStudent(int ID, string name, double studentScore, char studentGrade)
{
	studentIDs.insert(ID);
	studentNames.insert(name);
	studentScores.insert(studentScore);
	studentGrades.insert(studentGrade);
}

Course Course::loadFileToCourses(std::string fileName)
{

}