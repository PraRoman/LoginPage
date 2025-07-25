#include "Utils.h"
#include <iostream>

using namespace std;

void printMenu() {
	cout << "\t\t\t_________________________________________________________\n\n";
	cout << "\t\t\t                  Welcome to the Login Page    \n\n";
	cout << "\t\t\t_______________            MENU           ________________\n\n";
	cout << "													\n\n";
	cout << "\t| Press 1 to LOGIN                                  |" << endl;
	cout << "\t| Press 2 to REGISTER                               |" << endl;
	cout << "\t| Press 3 if you forgot your PASSWORD               |" << endl;
	cout << "\t| Press 4 to EXIT                                   |" << endl;
	cout << endl;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes
}

void waitForEnter() {
	cout << "\n\tPress Enter to continue... " << endl;
	cin.ignore();
	cin.get();
}