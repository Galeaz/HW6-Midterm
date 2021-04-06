// Participants: Andrew Thompson, Gabriela Lopez, Long Duong, Duyen Tran
// Date: 03-30-21
// Description: Course header

#pragma once

#include "../templateMyBag.h"
#include <string>
#include <fstream>

using namespace TEMPLATE_MYBAG;
using namespace std;
class Course 
{
public:
	Course();
	Course(const Course& obj);
	~Course();
	// Precondition: course instance
	// Postcondition: returns the current course name
	string getCourseName() const;
	// Precondition: course instance
	// Postcondition: set the internal course name to new course name
	void setCourseName(string newCourseName);
	// Precondition: course instance
	// Postcondition: insert new student ID
	void setStudentID(int newID);
	// Precondition: course instance
	// Postcondition: insert new student name
	void setStudentName(string newName);
	// Precondition: course instance
	// Postcondition: insert new score
	void setStudentScores(double newScore);
	// Precondition: course instance 
	// Postcondition: insert new grade given student's score
	void setStudentGrade(double theScore);
	// Precondition: course instance 
	// Postcondition: clear all students
	void clear();
	
	// Precondition: course instance
	// Postcondition: prompts user for file to load in
	void loadFileToCourses(int numberOfCourses,int& counter);

	// Precondition: course instance
	// Postcondition: add a new students with ID, name, score, and grade
	void addNewStudent(int ID, string name, double studentScore, char studentGrade);

	// Precondition: course instance
	// Postcondition: Returns if student with ID given exists
	bool searchStudentWithID(int ID);
	// Precondition: course instanace
	// Postcondition: returns if student with name exists
	bool searchStudentWithName(string name); // return student id if exists

	// Precondition: course instance
	// Postcondition: return student name given ID
	std::string getStudentNameByID(int ID);
	// Precondition: course instance
	// Postcondition: return student score given ID
	double getStudentScoreByID(int ID);
	// Precondition: course instance
	// Postcondition: return student grade given ID
	char getStudentGradesByID(int ID);

	// Precondition: course instance
	// Postcondition: remove student with ID
	void deleteStudentByID(int ID,int& index);
	// Precondition: course instance
	// Postcondition: remove student with name
	void deleteStudentByName(std::string name);
	// Precondition: course instance
	// Postcondition: copy another course into self
	void operator =(const Course& rhs);
	// Precondition: course instance
	// Postcondition: display course into outstream
	friend ostream& operator<< (ostream& os, const Course& course);

private:
	string courseName;
	MyBag<int> studentIDs;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> studentGrades;
};

