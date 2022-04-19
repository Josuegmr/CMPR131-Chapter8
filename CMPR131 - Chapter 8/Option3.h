#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "input.h"
using namespace std;

class Option3
{
private:
	queue<int> customers;
	int size;
public:
	// Constructor
	Option3() : size(0) {};
	// Accessor
	int getSize() const;
	void addCustomer();
	void removeCustomer();
	bool empty() const;

	bool operator <(const Option3& RHS);
	friend ostream& operator <<(ostream& outs, const Option3& obj);

};

// Accessor
int Option3::getSize() const
{
	return size;
}

bool Option3::operator <(const Option3& RHS)
{
	return(this->size < RHS.size);
}

ostream& operator <<(ostream& outs, const Option3& obj)
{
	if (obj.empty())
	{
		outs << " " << '\n';
		return outs;
	}
	else if (obj.size == 1)
	{
		outs << "|" << obj.customers.front() << "|\n";
		return outs;
	}
	else
	{
		outs << "|" << obj.customers.front() << "|\t";
		for (int i = 1; i < obj.size; i++)
		{
			outs << string(3, 254) << "  ";
		}
		outs << '\n';
		return outs;
	}
}

// Precondition: 
// Postcondition: return true if size is equal 0 otherwise false
bool Option3::empty() const
{
	return (size == 0);
}

// Precondition: 
// Postcondition: add a customer in the queue
void Option3::addCustomer()
{
	int customer = rand() % 100 + 1;
	customers.push(customer);
	size++;
}

// Precondition: 
// Postcondition: remove a customer in the queue
void Option3::removeCustomer()
{
	customers.pop();
	size--;
}

// Precondition: vec (vector<Option3>), helped (int), endTime(int)
// Postcondition: display the current time of operation of the store and the number of customers served
void displayLine(vector<Option3>& vec, int helped, int endTime)
{
	int currentTime = endTime - time(0);
	if (currentTime < 0)
		currentTime = 0;
	cout << "\n\tCostco Warehouse store open for " << currentTime << " \tNumber of customers served: " << helped << '\n';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "\n\tCash register #" << i + 1;
		cout << vec[i];
	}
}


// Precondition: 
// Postcondition: return the number of customer in a Cash register
int newCustomer()
{
	int amountOfCustomers = 5;
	int percentChance = 50;
	int random = 0;

	amountOfCustomers += (rand() % 2 + 1);
	return amountOfCustomers;
}

// Precondition: 
// Postcondition: return true if the operated time (holder) is less than endTime otherwise false
bool timer(int endTime)
{
	int holder;
	holder = time(0);
	return(holder < endTime);
}

// Precondition: vec (vector<Option3>)
// Postcondition: return the number of cash register that has less customers
int returnShortest(vector<Option3>& vec)
{
	int shortest = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < vec[shortest])
			shortest = i;
	}
	return shortest;
}



// Main Proccess
void SimOfCheckout()
{
	vector<Option3> cq;
	int helped = 0;
	int OpTime = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int curtime = time(0);
	int endTime = curtime + OpTime;
	int numberOfCheckstands = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);

	for (int i = 1; i <= numberOfCheckstands; i++)
	{
		Option3 queue;
		cq.push_back(queue);
	}
	do
	{
		Sleep(100);
		int customersPerLoop = newCustomer();
		for (int i = 1; i < customersPerLoop; i++)
		{
			if (numberOfCheckstands > 1)
			{
				cq[returnShortest(cq)].addCustomer();
				system("cls");
				displayLine(cq, helped, endTime);
				if (!timer(endTime))
					break;
			}
			else
			{
				cq[0].addCustomer();
				system("cls");
				displayLine(cq, helped, endTime);
			}

		}
		for (int i = 0; i < cq.size(); i++)
			if (!cq[i].empty() && (timer(endTime)))
			{
				cq[i].removeCustomer();
				helped++;
				system("cls");
				displayLine(cq, helped, endTime);
			}
	} while (timer(endTime));
}