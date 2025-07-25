#include <iostream>
#include <fstream>
#include <string>

#include "Auth.h"
#include "Utils.h"

using namespace std;

int main() {

	printMenu();

	int c;
	bool flag = true;

	while (flag == true) {
		clearScreen();
		printMenu();

		cin >> c;

		switch (c) {
		case 1:
			login();
			break;
		case 2:
			registration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout << "\t\t\t Thank you! " << endl;
			flag = false;
			break;
		default:
			clearScreen();
			cout << "\t\t\t Please select number from 1 to 4" << endl;
			main();
		}
	}
}

