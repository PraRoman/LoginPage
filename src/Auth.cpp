#include "Auth.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void login() {
	int count = 0;
	string userId, pswd, id, userPswd;
	clearScreen();
	cout << "\t\t\t Please enter the username and password : " << endl;
	cout << "\t\t\t USERNAME ";
	cin >> userId;
	cout << "\t\t\t PASSWORD ";
	cin >> userPswd;

	ifstream input("data.txt");

	if (!input.is_open()) {
		cerr << "Failed to open file for reading.\n";
		return;
	}

	while (input >> id >> pswd) {
		if (userId == id && pswd == userPswd) {
			count = 1;

		}
	}

	input.close();

	if (count == 1) {
		cout << userId << "\n Your LOGIN is successful \n";
	}
	else {
		cout << "\n LOGIN ERROR \n Please check your username and password\n";
	}

	waitForEnter();
};

void registration() {
	clearScreen();
	int flag = 0;
	string ruserId, ruserPswd, rid, rpswd;

	cout << "\t\t\t Please enter your LOGIN : \n USERNAME " << endl;
	cin >> ruserId;

	ifstream input("data.txt");

	if (!input.is_open()) {
		cerr << "Failed to open file for reading.\n";
		return;
	}

	while (input >> rid >> rpswd) {
		if (ruserId == rid) {
			cout << "ERROR : USERNAME is already exist \n Create a new one" << endl;
			flag = 1;
			break;
		}
	}

	input.close();

	if (flag != 1) {
		

		cout << "\t\t\t Please enter your PASSWORD : \n PASSWORD " << endl;
		cin >> ruserPswd;

		ofstream output("data.txt", ios::app);

		if (!output.is_open()) {
			cerr << "Could not open data.txt for reading.\n";
			return;
		}

		output << ruserId << ' ' << ruserPswd << endl;

		output.close();

		clearScreen();

		cout << "Registration is completed!" << endl;		
	}

	waitForEnter();
}

void forgot() {
	int option;
	int count = 0;
	string userId, id, pswd, userPswd;

	clearScreen();
	cout << "\t\t\tYou forgot the password?\t\t\t" << endl;
	cout << "\tPress 1 to search your password by username\t" << endl;
	cout << "\tPress 2 to exit in a main menu\t" << endl;
	cout << "\tEnter your choice : \t" << endl;
	cin >> option;

	

	switch (option) {
	case 1: {
		cout << "\n\t Enter username : ";
		cin >> userId;
		ifstream output("data.txt");

		if (!output.is_open()) {
			cerr << "Could not open data.txt for reading.\n";
			return;
		}

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
		}
		else {
			cout << "\n\t Your account is not found!" << endl;
		}
		waitForEnter();
		break;
	}
	case 2:
		break;

	default:
		cout << "\n\tWrong choice\n\n\tPlease, choose 1 or 2" << endl;
	}
}