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

	while (flag) {
		clearScreen();
		printMenu();

		cin >> c;
		if (cin.fail()) {
			cin.clear(); // сбрасываем флаг ошибки
			cin.ignore(10000, '\n'); // очищаем буфер
			cout << "Invalid input. Try again." << endl;
			continue; // пропускаем итерацию
		}

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
		}
	}
}

