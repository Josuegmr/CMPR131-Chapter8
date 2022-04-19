// date: 04/14/2022
// description: Chapter 8 - Assignment

#include <iostream>
#include "input.h" // use for validate input
#include "Option1.h"
#include "Option2.h"
#include "Option3.h"

using namespace std;

// Prototype
int menuOption();

int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    do
    {
        switch (menuOption())
        {
        case 0: exit(1); break;
        case 1:
        {
            Option1 game;
            game.mainProcess();
        } break;
        case 2:
        {
            Option2 menu;
            menu.mainMenu();

        } break;
        case 3: SimOfCheckout(); break;

        default: cout << "\n\tERROR - Invalid option. Please re-enter.\n"; break;
        }
        /*cout << "\n";
        system("pause");*/
    } while (true);

    return EXIT_SUCCESS;
}

// return a valid option (0...n)
int menuOption()
{
    cout << "\n\t=========================================================================";
    cout << "\n\tCMPR131 Chapter 8: Chapter 8: Applications using Queues by:";
    cout << "\n\t";
    cout << "\n\t=========================================================================";
    cout << "\n\t\t1> Simulation of War (card game) using deque STL";
    cout << "\n\t\t2> Simulation of an emergency room (ER) using priority queue STL";
    cout << "\n\t\t3> Simulation of checkout lines at CostCo using multiple queues STL";
    cout << "\n\t-------------------------------------------------------------------------";
    cout << "\n\t\t0> Exit";
    cout << "\n\t=========================================================================\n";

    int option = inputInteger("\tOption: ", 0, 3);
    system("cls");

    cout << "\n";
    return option;
}