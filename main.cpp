#include <iostream>
#include <fstream>
#include "Users.h"
using namespace std;

int main() {
	ifstream inFile;
	inFile.open("userdata");
	Users userList(inFile);

	cout << "LOGIN v.01" << endl;

	userList.addUser();

	userList.printData();
}
