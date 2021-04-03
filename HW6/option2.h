#pragma once
#include <iostream>
#include <algorithm>
#include "templateMyBag.h"
using namespace std;
using namespace TEMPLATE_MYBAG;
void option2();

void option2()
{
	MyBag<double> bag(100);
	{
	
		int menuOption;

		do
		{
			system("cls");
			cout << "\t\t2) Template MyBag of doubles\n";
			cout <<'\t' << string(40, char(196))<<'\n';
			cout << "\t\t1> clear\n";
			cout << "\t\t2> insert\n";
			cout << "\t\t3> search\n";
			cout << "\t\t4> remove\n";
			cout << "\t\t5> sort and display\n";
			cout << "\t\t0> return\n";
			cout << '\t' << string(40, char(196)) << '\n';
			menuOption = inputInteger("Option: ", 0, 5);
			
			switch (menuOption)
			{
			case 0: break;
			case 1: bag.clear(); cout << "\n1> MyBag cleared of all elements\n"; break;
			case 2: {
						double toInsert = inputDouble("Enter a double to insert: ");
						bag.insert(toInsert);
						break;
					}
			case 3: {
						int index = -1;
						bool found = false;
						double toFind = inputDouble("Enter a double to search for: ");
						found = bag.search(toFind, index);
						if (found)
						{
							cout << "The value " << toFind << " was found at index [" << index << "]\n";
							break;
						}
						else
						{
							cout << "The value " << toFind << " was not found!";
							break;
						}
						 
					}
			case 4:bag.remove(); break;
			case 5:bag.sort(); cout << bag; break;
			default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
			}
			
			
			cout << '\n';
			system("pause");
		} while (true);
	}
	


}

