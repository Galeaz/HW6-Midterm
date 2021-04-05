// Participants: Gabriela Lopez, Andrew Thompson, Long Duong, Christopher Gomez, Gia Minh Hoang, Duyen Tran and Lincoln Nguyen
// Date: 03-27-21
// Description: Chapter 6 Solution

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

#include "option2.h"
#include "input.h"
#include "MyBag1.h"

//Precondition: N/A
//Postcondition: Prints menu and returns user int option selected
int menuOption();

void option1();

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0:  exit(0);
		case 1:  system("cls"); option1(); break;
		case 2:  system("cls"); option2(); break;
		case 3:  system("cls"); /*function();*/ break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		cout << '\n';
		system("pause");
	} while (true);
	return 0;
}

int menuOption()
{
	system("cls");
	cout << '\n';
	cout << '\t' << char(201) << string(42, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "    \t    CMPR131: Chapter 6             " << char(186) << '\n';
	cout << '\t' << char(186) << "      \t\t  Made by:                 " << char(186) << '\n';
	cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Lincoln Nguyen\t- Long Duong       " << char(186) << '\n';
	cout << '\t' << char(186) << " - Christopher Gomez\t- Gia Minh Hoang   " << char(186) << '\n';
	cout << '\t' << char(186) << " - Duyen Tran                             " << char(186) << '\n';
	cout << "\t" << char(204) << string(42, char(205)) << char(185) << "\n";
	cout << "\t" << char(186) << "   1: template bag of ints                " << char(186) << "\n";
	cout << "\t" << char(186) << "   2: template bag of doubles             " << char(186) << "\n";
	cout << "\t" << char(186) << "   3: ??????????? ????? ? ???? ?????????  " << char(186) << "\n";
	cout << "\t" << char(199) << string(42, char(196)) << char(182) << "\n";
	cout << "\t" << char(186) << "   0: Exit                                " << char(186) << "\n";
	cout << "\t" << char(200) << string(42, char(205)) << char(188) << "\n";

	int option = inputInteger("\t    Option: ", 0, 3);
	cin.clear();
	return option;
}

void option1()
{
	system("cls");

	int size = inputInteger("\nEnter the size (1..100) of the dynamic array: ", 1, 100);

	NON_TEMPLATE_MYBAG::MyBag testBag(size);

	do
	{
		cout << "\n\t1> Non-template MyBag of integers";
		cout << "\n\t" << string(100, char(205));
		cout << "\n\t\tA> clear";
		cout << "\n\t\tB> insert";
		cout << "\n\t\tC> search";
		cout << "\n\t\tD> sort";
		cout << "\n\t\tE> display";
		cout << "\n\t" << string(100, char(196));
		cout << "\n\t\tF> return";
		cout << "\n\t\t" << string(100, char(205)) << '\n';

		switch (toupper(inputChar("\t\tOption: ", "ABCDEF")))
		{
		case 'A': testBag.clear(); break;
		case 'B':
		{
			int element = inputInteger("\t\tEnter an element (integer) to insert: ", true);
			testBag.insert(element);
		}
		break;
		case 'C':
		{
			int element = inputInteger("\t\tEnter an element (integer) to search: ", true);
			int index = -1;
			cout << (testBag.search(1, index) ? "found at " + to_string(index) : "not found") << '\n';
		}
		break;
		case 'D':
		{
			testBag.sort();
		}
		break;
		case 'E':
		{
			cout << '\n' << testBag << '\n';
		}
		break;
		case 'F': return;

		}

	} while (true);
}