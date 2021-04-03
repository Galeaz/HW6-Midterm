// Participants: Long Duong, Gabriela Lopez and Duyen Tran
// Date: 03-30-21
// Description: course header

#pragma once

#include "../templateMyBag.h"
#include "../input.h"
#include <string>
#include <fstream>

using namespace TEMPLATE_MYBAG;

class Course 
{
public:
	Course() = default;

	// accesors - mutators
	int getStudentPosition(int ID);
	int getStudentID(std::string name);
	std::string getStudentName(int position);
	double getStudentScores(int position);
	char getStudentGrade(int position);
	void setCourseName(string newCourseName);
	void setStudentID(int newID);
	void setStudentName(std::string newName);
	void setStudentScores(double newScore);
	void setStudentGrade(double theScore);



	Course loadFileToCourses(int numberOfCourses);

	void addNewStudent(int ID, std::string name, double studentScore, char studentGrade);

	bool searchStudentWithID(int ID);
	int searchStudentWithName(std::string name); // return student id if exists

	std::string getStudentNameByID(int ID);
	std::string getStudentScoreByID(int ID);
	std::string getStudentGradesByID(int ID);

	void deleteStudentByID(int ID);
	void deleteStudentByName(std::string name);

private:
	std::string courseName;
	MyBag<int> studentIDs;
	MyBag<std::string> studentNames;
	MyBag<double> studentScores;
	MyBag<char> studentGrades;
};

std::ostream& operator<< (std::ostream& os, const Course& course);