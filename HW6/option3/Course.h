// Participants: Long Duong, Gabriela Lopez and Duyen Tran
// Date: 03-30-21
// Description: course header

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
	// Precondition:
	// Postcondition: 
	int getStudentPosition(int ID);
	// Precondition:
	// Postcondition:
	int getStudentID(string name);
	string getCourseName() const;
	string getStudentName(int position);
	double getStudentScores(int position);
	char getStudentGrade(int position);
	void setCourseName(string newCourseName);
	void setStudentID(int newID);
	void setStudentName(string newName);
	void setStudentScores(double newScore);
	void setStudentGrade(double theScore);
	void clear();


	void loadFileToCourses(int numberOfCourses,int& counter);

	void addNewStudent(int ID, string name, double studentScore, char studentGrade);

	bool searchStudentWithID(int ID);
	bool searchStudentWithName(string name); // return student id if exists

	std::string getStudentNameByID(int ID);
	double getStudentScoreByID(int ID);
	char getStudentGradesByID(int ID);

	void deleteStudentByID(int ID,int& index);
	void deleteStudentByName(std::string name);
	void operator =(const Course& rhs);
	friend ostream& operator<< (ostream& os, const Course& course);

private:
	string courseName;
	MyBag<int> studentIDs;
	MyBag<string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> studentGrades;
};

