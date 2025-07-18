#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void login();

void registration();

void forgot() {
	return;
};

int main() {
	int c;

	cout << "\t\t\t_________________________________________________________\n\n";
	cout << "\t\t\t                  Welcome to the Login Page    \n\n";
	cout << "\t\t\t_______________            MENU           ________________\n\n";
	cout << "													\n\n";
	cout << "\t| Press 1 to LOGIN                                  |" << endl;
	cout << "\t| Press 2 to REGISTER                               |" << endl;
	cout << "\t| Press 3 if you forgot your PASSWORD               |" << endl;
	cout << "\t| Press 4 to EXIT                                   |" << endl;

	cin >> c;

	cout << endl;

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
		break;
	default:
		system("cls");
		cout << "\t\t\t Please select number from 1 to 4" << endl;
		main();
	}
}

void login() {
	int count = 0;
	string userId, pswd, id, userPswd;
	system("cls");
	cout << "\t\t\t Please enter the username and password : " << endl;
	cout << "\t\t\t USERNAME ";
	cin >> userId;
	cout << "\t\t\t PASSWORD ";
	cin >> userPswd;

	ifstream input("data.txt");

	while (input >> id >> pswd) {
		if (userId == id && pswd == userPswd) {
			count = 1;
			system("cls");
		}
	}

	if (count == 1) {
		cout << userId << "\n Your LOGIN is successful \n";
		main();
	}
	else {
		cout << "\n LOGIN ERROR \n Please check your username and password\n";
		main();
	}
};

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