#pragma once

#include <string>
#include "Course.h"
#include"input.h"

using namespace std;

void driver3() 
{
	MyBag<Course> courses;

	int numberOfCourses;

	int menuOption;
	
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
				cout << " Enter the number of courses: ";
				cin >> numberOfCourses;
				cout << '\n';

				cout << numberOfCourses << " Course(s) has been created. \n";
				break;
			}

			case 2: 
			{

			}

			case 3: 
				break;
			case 4:
				break;
			case 5:
				break;
			default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
			}

		cout << '\n';
		system("pause");

	} while (true);

}
