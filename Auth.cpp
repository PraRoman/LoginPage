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

		}
	}

	if (count == 1) {
		cout << userId << "\n Your LOGIN is successful \n";
	}
	else {
		cout << "\n LOGIN ERROR \n Please check your username and password\n";
	}

	waitForEnter();
};