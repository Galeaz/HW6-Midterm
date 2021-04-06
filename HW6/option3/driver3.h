// Participants: Andrew Thompson, Gabriela, Long, Duyen
// Date: 03-30-21
// Description: Driver for course

#pragma once

#include <string>
#include "Course.h"
#include "../input.h"
#include <vector>

using namespace std;
void part3Menu3(vector<Course>& obj, int size);
void part3Menu4(vector<Course>& obj, int size);
void driver3() 
{
	Course c1, c2;
	vector<Course> courses;
	int numberOfCourses = 0;
	int counter = 0;
	int menuOption;
	bool fileRead = false;

	
	do
	{
			system("cls");
			cout << "\t\t  3) Courses using MyBags of integers, strings, doubles, and chars\n";
			cout << '\t' << string(40, char(196)) << '\n';
			cout << "\t\t 1> Specify the number of courses\n";
			cout << "\t\t 2> Read in data file and insert into courses\n";
			cout << "\t\t 3> Search for a student record from a course\n";
			cout << "\t\t 4> Remove a student record from a course\n";
			cout << "\t\t 5> Display course(s)\n";
			cout << "\t\t 0> return\n";
			cout << '\t' << string(40, char(196)) << '\n';

			menuOption = inputInteger("Option: ", 0, 5);

			switch (menuOption)
			{
			case 0: 
				break;
			case 1: 
			{

				numberOfCourses = inputInteger("Enter the number of courses: ", 1, 100);
				cout << '\n';

				cout << numberOfCourses << " Course(s) has been created. \n";
				courses.reserve(numberOfCourses);
				break;
			}
			case 2: 
			{
				if (numberOfCourses != 0) {
					/*if (counter > 0)
					{
						for (int i = 0; i < counter; i++)
							courses.at(i).clear();
						
						counter = 0;
					}*/
					for (int i = 0; i < numberOfCourses; i++)
					{
						 c1.loadFileToCourses(numberOfCourses, counter);
						 c2=c1;
						courses.push_back(c2);
						fileRead = true;
						c1.clear();
					}
					break;
				}
				else
				{
					cout << "\nNumber of courses is currently 0\n";
					break;
				}
				break;
			}
			case 3: 
				if (fileRead) 
				{
					part3Menu3(courses, numberOfCourses);
					break;
				}
				else
				{
					cout << "\nERROR: no file has been read and stored into courses\n";
					break;
				}

				
			case 4:
				if (fileRead)
				{
					part3Menu4(courses, numberOfCourses);
						break;
				}
				
				else
				{
					cout << "\nERROR: no file has been read and stored into courses\n";
					break;
				}
				
			case 5:
				for (int i = 0; i < numberOfCourses; i++)
				{
					cout << courses[i]<<'\n';
				}
				break;

			default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
			}

		cout << '\n';
		system("pause");

	} while (true);

}
void part3Menu3(vector<Course>& obj, int size)
{
	int toFind = 0;
	bool found = false;
	string nameToFind = " ";
	int option;
	cout << "\n\t\tSearch by\n";
	cout << '\t' << string(40, char(196)) << '\n';
	cout << "\t\t1. ID Number\n";
	cout << "\t\t2. Name\n";
	cout << "\t\t0. return\n";
	cout << '\t' << string(40, char(196)) << '\n';
	option = inputInteger("Option: ",0,2);

	switch (option)
	{
	case 0: break;
	case 1:
		{
			toFind = inputInteger("Enter a student ID to search for: ");
			for (int i = 0; i < size; i++)
			{
				found = obj.at(i).searchStudentWithID(toFind);
				if (found) 
				{
					cout << "\nThe student id "<< toFind<< " was found in the course: " << obj.at(i).getCourseName();
					break;
				}
			}
			if (!found)
			{
				cout << "\nThe ID was not found in any courses!\n";
			}

				break;
		}
	case 2:
		{
			cout << "Enter a name to search for: ";
			getline(cin,nameToFind);
			
			for (int i = 0; i < size; i++)
			{
				found = obj.at(i).searchStudentWithName(nameToFind);
				if (found)
				{
					cout << "\nThe student " << nameToFind << " was found in the course: " << obj.at(i).getCourseName();
					break;
				}
			}
			if (!found)
			{
				cout << "\nThe entered name was not found in any courses!\n";
				break;
			}
		break;
		}


	}

} 
void part3Menu4(vector<Course>& obj, int size)
{
	int choice = 0;
	int id = 0;
	int index = -1;
	cout << "\nChose a class to remove student from:\n";
	cout << '\t' << string(40, char(196)) << '\n';
	for (int i = 0; i < size; i++)
	{
		cout << "\n\t" << '[' << i + 1 << "]: " << obj.at(i).getCourseName() << '\n';
	}
	cout << '\t' << string(40, char(196)) << '\n';
	choice = inputInteger("Option: ", 1, size);
	choice = choice - 1;
	id = inputInteger("\nEnter an id to search for and remove if it is found");
	obj.at(choice).deleteStudentByID(id, index);
	if (index == -1)
	{
		cout << "\nThe id "<<id<<" was not found in " << obj.at(choice).getCourseName() << "!\n";
		return;
	}
	else
	{
		cout << "The student associated with the ID number " << id << " was removed from "<< obj.at(choice).getCourseName();
		return;
	}
}