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
					// set all elements in course
					if (file.eof())
						break;
				}
				file.close();
				theBag.insert(newCourse);
				cout << "Data from file, " << fileName << ", has been read and stored into Courses[" << (counter - 1) << "].\n";
				counter++;
			}
		}
	} while (true);
}