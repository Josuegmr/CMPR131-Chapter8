#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "input.h" // use for validate input
#include "Patient.h"

using namespace std;

class Option2
{
private:
	priority_queue<Patient> pq2;
	vector<Patient> submit;
public:

	// Main Menu
	void mainMenu()
	{
		do
		{
			cout << "\t2> Simulation of an emergency room (ER) using priority queue STL";
			cout << "\n\t==========================================================================================================";
			cout << "\n\t\tA> Register a patient";
			cout << "\n\t\tB> Transfer patient(s) to the designation";
			cout << "\n\t\tC> Display transferred patients";
			cout << "\n\t----------------------------------------------------------------------------------------------------------";
			cout << "\n\t\t0> Return";
			cout << "\n\t==========================================================================================================\n";

			int option = inputChar("\n\tOption: ");
			system("cls");
			if (option == '0') break;

			cout << '\n';
			switch (option)
			{
			case 'A':
			{
				Patient patient;
				string name;
				cout << "\n\tEnter the patient's name: ";
				getline(cin, name);
				patient.setName(name);
				patient.setAge(inputInteger("\tEnter the patient's age: ", true));
				patient.setCheckedInTime(time(0));
				patient.setGender(toupper(inputChar("\tChoose the patient's gender (F-female or M - male) : ", 'F', 'M')));
				patient.setPriority(inputInteger("\tChoose the ER level 1)Non-urgent, 2)Less Urgent, 3)Urgent, 4)Emergent, or 5)Resuscitation: ", 1, 5));
				pq2.push(patient); // enqueue
				cout << "\n\t\tPatient information has been registered.\n";
			} break;
			case 'B':
			{
				if (!pq2.empty())
				{
					if (pq2.top().getPriority() == 5)
					{
						submit.push_back(pq2.top());
						cout << "\n\t\t" << pq2.top().getName() << " - transfers to ICU...\n";
						pq2.pop(); // dequeue
						break;
					}
					else if (pq2.top().getPriority() == 4)
					{
						submit.push_back(pq2.top());
						cout << "\n\t\t" << pq2.top().getName() << " - transfers to	surgery room...\n";
						pq2.pop();
						break;
					}
					else if (pq2.top().getPriority() == 3)
					{
						submit.push_back(pq2.top());
						cout << "\n\t\t" << pq2.top().getName() << " - transfers to	emergency room...\n";
						pq2.pop();
						break;
					}
					else if (pq2.top().getPriority() == 2)
					{
						submit.push_back(pq2.top());
						cout << "\n\t\t" << pq2.top().getName() << " - transfers to xray lab...\n";
						pq2.pop();
						break;
					}
					else if (pq2.top().getPriority() == 1)
					{
						submit.push_back(pq2.top());
						cout << "\n\t\t" << pq2.top().getName() << " - examines and	gives prescription...\n";
						pq2.pop();
						break;
					}
				}
				else
					cout << "\tThe queue of patients is empty.\n";
			} break;
			case 'C':
			{
				if (!submit.empty())
				{
					sort(submit.begin(), submit.end());
					reverse(submit.begin(), submit.end());
					cout << '\n';
					for (int i = 0; i < submit.size(); i++)
						cout << "\t\t" << i + 1 << " - " << submit[i] << '\n';
				}
				else
					cout << "\n\t\tNo patient has been transferred.\n";
			} break;
			default: cout << "\tERROR - Invalid option. Please re-enter.\n"; break;
			}
			cout << '\n';
		} while (true);
	}


};


