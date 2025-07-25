#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Auth.h"
#include "Utils.h"

using namespace std;

void registration();

void forgot();

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

void registration() {
	int flag = 0;
	string ruserId, ruserPswd, rid, rpswd;
	system("cls");

	cout << "\t\t\t Please enter your LOGIN : \n USERNAME " << endl;
	cin >> ruserId;

	ifstream input("data.txt");

	while (input >> rid >> rpswd) {
		if (ruserId == rid) {
			cout << "ERROR : USERNAME is already exist \n Create a new one" << endl;
			flag = 1;
			main();
		}
	}

	if (flag != 1) {
		input.close();

		cout << "\t\t\t Please enter your PASSWORD : \n PASSWORD " << endl;
		cin >> ruserPswd;

		ofstream output("data.txt", ios::app);

		output << ruserId << ' ' << ruserPswd << endl;

		system("cls");

		cout << "Registration is completed!" << endl;

		output.close();
	}
}

void forgot() {
	int option;
	int count = 0;
	string userId, id, pswd, userPswd;

	system("cls");
	cout << "\t\t\tYou forgot the password?\t\t\t" << endl;
	cout << "\tPress 1 to search your password by username\t" << endl;
	cout << "\tPress 2 to exit in a main menu\t" << endl;
	cout << "\tEnter your choice\t" << endl;
	cin >> option;

	ifstream output("data.txt");

	switch (option) {
	case 1 :
		cout << "\n\t Enter username : ";
		cin >> userId;

		while (output >> id >> pswd) {
			if (userId == id) {
				count = 1;
				break;
			}
		}
		output.close();
		if (count == 1) {
			cout << "\n\t Your account is found! \t" << endl;
			cout << "\n\t Here is your password : \t" << pswd << endl;
			main();
		}
		else {
			cout << "\n\t Your account is not found!" << endl;
			main();
		}
		break;
	case 2 : 
		output.close();

	default: 
		output.close();
		main();
	}
}