// Participants: Andrew Thompson, Gabriela Lopez, Long Duong, Duyen Tran
// Date: 03-30-21
// Description: course implementation

#include "option3/Course.h"
#include <cassert>
using namespace std;

//Precondition: need Course obj
//Postcondition: initializes data for Course obj
Course::Course()
{
	studentIDs.setCapacity(0);
	studentGrades.setCapacity(0);
	studentNames.setCapacity(0);
	studentScores.setCapacity(0);
}

//Precondition: need Course obj
//Postcondition: pass in new data for Course Obj
Course::Course(const Course& obj)
{
	studentIDs = obj.studentIDs;
	studentGrades = obj.studentGrades;
	studentNames = obj.studentNames;
	studentScores = obj.studentScores;
	courseName = obj.courseName;
}

//Precondition: a string
//Postcondition: change courseName
void Course::setCourseName(string newCourseName)
{
	courseName = newCourseName;
}

string Course::getCourseName() const
{
	return courseName;
}

//Precondition: an int
//Postcondition: change StudentID
void Course::setStudentID(int newID)
{
	studentIDs.insert(newID);
}

//Precondition: a string
//Postcondition: change StudentName
void Course::setStudentName(string newName)
{
	studentNames.insert(newName);
}

//Precondition: a double
//Postcondition: change StudentScores
void Course::setStudentScores(double newScore)
{
	studentScores.insert(newScore);
}

//Precondition: a double
//Postcondition: change StudentGrade according to the pass in value
void Course::setStudentGrade(double theScore)
{
	if (theScore >= 90)
	{
		studentGrades.insert('A');
		return;
	}
	else if (theScore >= 80)
	{
		studentGrades.insert('B');
		return;
	}
	else if (theScore >= 70)
	{
		studentGrades.insert('C');
		return;
	}
	else if (theScore >= 60)
	{
		studentGrades.insert('D');
		return;
	}
	else
	{
		studentGrades.insert('F');
		return;
	}

}

//Precondition: an int, a string, double, char
//Postcondition: change all the datas for studentID, studentNames, studentScores, studentGrades
void Course::addNewStudent(int ID, string name, double studentScore, char studentGrade)
{
	studentIDs.insert(ID);
	studentNames.insert(name);
	studentScores.insert(studentScore);
	studentGrades.insert(studentGrade);
}

//Precondition: 2 int
//Postcondition: Print the menu
void Course::loadFileToCourses(int numberOfCourses, int& counter)
{
	string fileName;
	ifstream file;
	string ID, score, name, grade;
	/*Course newCourse;*/


	do
	{
		cout << "\nEnter a data file name for course[" << counter << "] : ";
		cin >> fileName;
		file.open(fileName);
		if (!file)
		{
			cout << "Error: file not found!\n";
		}
	} while (!file.is_open());


	/*file.open(fileName);*/
	if (file.fail())
		cout << "ERROR: The file did not open.\n";
	else
	{
		getline(file, name, '\n');
		setCourseName(name);
		while (!file.eof())
		{

			getline(file, ID, ',');
			setStudentID(stoi(ID));
			getline(file, name, ',');
			setStudentName(name);
			getline(file, score, '\n');
			setStudentScores(stod(score));
			setStudentGrade(stod(score));
			if (file.eof())
				break;
			//else clean getline? has to have a \n
		}
		file.close();

		cout << "Data from file, " << fileName << ", has been read and stored into Courses[" << (counter) << "].\n";
		counter++;
	}
	return;

}

bool Course::searchStudentWithID(int ID)
{
	int position = 0;
	return studentIDs.search(ID, position);
}

bool Course::searchStudentWithName(std::string name) 
{
	int position = 0;
	if (studentNames.search(name, position)) 
	{
		return true;
	}
	else
		return false;
}

void Course::clear()
{
	studentIDs.clear();
	studentNames.clear();
	studentScores.clear();
	studentGrades.clear();
}

string Course::getStudentNameByID(int ID)
{
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentNames.at(pos);
}
double Course::getStudentScoreByID(int ID) 
{
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentScores.at(pos);
}
char Course::getStudentGradesByID(int ID) 
{
	int pos = -1;
	studentIDs.search(ID, pos);
	assert(pos != -1);
	return studentGrades.at(pos);
}

void Course::deleteStudentByID(int ID, int& index) 
{
	
	studentIDs.search(ID, index);
	if (index == -1)
	{
		return;
	}
	studentIDs.removeAtIndex(index);
	studentNames.removeAtIndex(index);
	studentScores.removeAtIndex(index);
	studentGrades.removeAtIndex(index);
}
void Course::deleteStudentByName(std::string name) 
{
	int index = -1;
	studentNames.search(name, index);
	assert(index != -1);
	studentIDs.removeAtIndex(index);
	studentNames.removeAtIndex(index);
	studentScores.removeAtIndex(index);
	studentGrades.removeAtIndex(index);
}


void Course::operator =(const Course& rhs)
{

	studentScores = rhs.studentScores;
	studentNames = rhs.studentNames;
	studentIDs = rhs.studentIDs;
	studentGrades = rhs.studentGrades;
	courseName = rhs.courseName;
}

ostream& operator<< (ostream& os, const Course& obj)
{
	os << obj.courseName << '\n';
	os << "Index:\tID:\t Name:\t      Score:\tGrade:";
	for (int i = 0; i < obj.studentIDs.getSize(); i++)
	{

		os << "\n[" << i << "]\t";
		os << obj.studentIDs[i] << '\t';
		os << obj.studentNames[i] << '\t';
		os << obj.studentScores[i] << '\t';
		os << obj.studentGrades[i] << '\t';
	}
	return os;
}