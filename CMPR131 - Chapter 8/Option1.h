#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "input.h" // use for validate input

class Option1
{
private:
	int nCards;
	vector<int> pile;
	queue<int> P1;
	queue<int> P2;

public:
	// Constructor
	Option1()
	{
		cout << "\t1> Simulation of War (card game) using deque STL";
		cout << "\n\t==================================================================\n";
		nCards = inputInteger("\n\tEnter a number of cards per suite: ", 1, 13);
	}


	// Main Process
	void mainProcess()
	{
		// Establish the deck
		for (int i = 0; i < 4; i++)
			for (int j = 1; j <= nCards; j++)
				pile.push_back(j);

		int random;
		do
		{
			// Cards of Player 1
			random = rand() % pile.size();
			//cout << "\n\tRandom1 = " << random << " PileRand = " << pile[random];
			P1.push(pile[random]);
			pile.erase(pile.begin() + random);

			// Cards of Player 2
			random = rand() % pile.size();
			//cout << "\n\tRandom2 = " << random << " PileRand = " << pile[random] << '\n';
			P2.push(pile[random]);
			pile.erase(pile.begin() + random);

		} while (!pile.empty());

		do
		{
			if (!P1.empty() || !P2.empty())
			{
				cout << "\n\t\tPlayer 1: " << P1.front() << "\tPlayer 2: " << P2.front();

				if (P1.front() > P2.front())
				{
					cout << "  -> Player 1 wins!";
					// Add the cards that the player 1 won of the Tie Beaker
					for (int i = 0; i < pile.size(); i++)
						P1.push(pile[i]);
					pile.push_back(P2.front());
					pile.push_back(P1.front());
					// Add the cards that the player 1 won of the round
					for (int i = 0; i < pile.size(); i++)
						P1.push(pile[i]);
				}
				else if (P2.front() > P1.front())
				{
					cout << "  -> Player 2 wins!";

					// Add the cards that the player 2 won of the Tie Beaker
					for (int i = 0; i < pile.size(); i++)
						P2.push(pile[i]);
					pile.push_back(P1.front());
					pile.push_back(P2.front());
					// Add the cards that the player 2 won of the round
					for (int i = 0; i < pile.size(); i++)
						P2.push(pile[i]);
				}
				else
				{
					cout << "  -> Tie breaker begins!";
					P1.pop();
					P2.pop();
					if (P1.empty() || P2.empty())
					{
						//Both players does not have cards after simultaneous tiebreakers
						if (P1.empty() && P2.empty())
							cout << "\n\n\tIt's a Tie!\n";
						//Decide who won the game if a player has no more cards after a tiebreaker
						else
							cout << "\n\n\tPlayer " << (!P1.empty() ? "1" : "2") << " takes all because Player " << (P1.empty() ? "1" : "2") << " has no more card.\n";
						break;
					}
					else
					{
						pile.push_back(P2.front());
						pile.push_back(P1.front());
						continue;
					}
				}
				P1.pop();
				P2.pop();
				pile.clear();
				if (P1.empty() || P2.empty())
				{
					//Both players does not have cards after
					if (P1.empty() && P2.empty())
						cout << "\n\n\tIt's a Tie!\n";
					//Decide who won the game if a player has no more cards
					else
						cout << "\n\n\tPlayer " << (!P1.empty() ? "1" : "2") << " takes all because Player " << (P1.empty() ? "1" : "2") << " has no more card.\n";
					break;
				}
			}
			else
			{
				break;
			}
			cin.get();
		} while (true);

		// Result
		cout << "\tPlayer " << (!P1.empty() ? "1" : "2") << " wins the war with most number of cards (" << (4 * nCards) << ").\n";
		
	}

	// Precondition: v (vector)
	// Postcondition: Display all elements of the specified vector
	void printVector(vector<int> v)
	{
		for (int i = 0; i < v.size(); i++)
			cout << "\n\t\tVECTOR: [" << i << "]: " << v[i];
		cout << endl;
	}
	// Precondition: v (queue)
	// Postcondition: Display all elements of the specified queue
	void printQueue(queue<int> q)
	{
		//printing content of queue 
		for (int i = 0; i < P1.size(); i++)
		{
			cout << "\n\t\tQUEUE: [" << i << "]: " << q.front();
			q.pop();
		}
		cout << endl;
	}

};
