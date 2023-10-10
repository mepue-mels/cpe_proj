#include <iostream>
#include <fstream>
#include "headers/Database.h"
using namespace std;

void setup(int& choice, string currentUser, Users userList);
void loop(int& choice, Database dat);

int main() {
	ifstream userFile, boolFile, reserverFile;
	userFile.open("sampledata/userFile");
	boolFile.open("sampledata/boolFile");
	reserverFile.open("sampledata/reserverFile");

	int choice;
	string currentUser;
	Users userList(userFile);
	Database Data(boolFile, reserverFile, userList);


	currentUser = login(userList);

	if (currentUser == "NULL") {
		cout << "Program exiting, cannot find user!";
	} else {
		setup(choice, currentUser, userList);
		loop(choice, Data);
	}


}

void setup(int& choice, string currentUser, Users userList) {
	cout << endl;
	cout << "CLRS beta v1.0" << endl
		 << "Welcome " << userList.returnName(currentUser) << endl << endl;
	cout << "(1) Create a reservation" << endl
		 << "(2) Delete a reservation" << endl
		 << "(3) Find a reservation" << endl << endl
		 << "Enter choice: ";
	cin >> choice;
}


void showReservations(Database dat) {
	int room, day;

	string timeArray[9] = {
		"7:30AM-9:00AM", "9:00AM-10:30AM",
		"10:30AM-12:00NN", "12:00NN-1:30PM",
		"1:30PM-3:00PM", "3:00PM-4:30PM",
		"4:30PM-6:00PM", "6:00PM-7:30PM",
		"7:30PM-9:00PM"
	};

	cout << "Rooms:" << endl
		 << "N200 - 0" << endl
		 << "N201 - 1" << endl
		 << "N202 - 2" << endl
		 << "N203 - 3" << endl
		 << "N204 - 4" << endl
		 << "N205 - 5" << endl;

	cout << "Enter your desired room: "; cin >> room;

	cout << "Enter your desired day of reservation: "; cin >> day;

	cout << "Remaining time slots:" << endl;

	for (int i = 0; i < 9; i++) {
		if (!dat.returnMatrix(room).getStatus(i,day)) {
			cout << timeArray[i] << endl;
		}
	}

	cout << endl;
	cout << "Reserved time slots:" << endl;

	for (int i = 0; i < 9; i++) {
		if (dat.returnMatrix(room).getStatus(i,day)) {
			cout << timeArray[i] << " - reserved by " << dat.getReserverName(room, i, day);
		}
	}


}

void createReservations(Database dat) {

}

void loop(int& choice, Database dat) {
	switch (choice) {
		case 1:
			showReservations(dat);
		case 2:
			createReservations(dat);
	}
}
