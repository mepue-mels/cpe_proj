#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "reservationTracker.h"

using namespace std;


/*********USER CLASS************/
class User {
private:
	string username;
	string pass;
	string name;
	string faculty_id;
	string department;
	ReservationTracker userReservationList;
public:
	User() {
		username = "";
		pass = "";
	}

	User(string u, string p, string n, string i, string d, int rC) {
		username = u;
		pass = p;
		name = n;
		faculty_id = i;
		department = d;
		userReservationList.setReservationCount(rC);
	}

	void set(string u, string p, string n, string i, string d, int rC) {
		username = u;
		pass = p;
		name = n;
		faculty_id = i;
		department = d;
		userReservationList.setReservationCount(rC);
	}
	
	string getUsername() const {
		return username;
	}

	string getPassword() const {
		return pass;
	}

	string getName() const {
		return name;
	}

	string getFacultyID() const {
		return faculty_id;
	}

	string getDepartment() const {
		return department;
	}

	int getUserTime(int listIndex) {
		return userReservationList.getUserReservationTime(listIndex);
	}

	int getUserDay(int listIndex) {
		return userReservationList.getUserReservationDay(listIndex);
	}

	int getUserReservationCount() const {
		return userReservationList.getReservationCount();
	}

	void fetchReservationDataToUser(int time, int day) {
		userReservationList.initialAddReservation(time, day);
	}

	void addReservationToUser(int time, int day) {
		userReservationList.addReservation(time, day);
	}

	void clearReservationData() {
		userReservationList.clearUserReservationList();
	}
};


/***********USERS CONTAINER CLASS**********/

class Users {
private:
	vector<User> userList;
public:
	Users() {
		//default constructor does nothing
	}

	Users(ifstream& inFile) {
		User buf;
		string user, pass, name, faculty_id, department;
		int reservationCount;

		while (inFile) {
//			inFile >> user >> pass >> name >> faculty_id >> department;
			getline(inFile, user);
			getline(inFile, pass);
			getline(inFile, name);
			getline(inFile, faculty_id);
			getline(inFile, department);
			inFile >> reservationCount;
			inFile.ignore(1, '\n');
			buf.set(user,pass, name, faculty_id, department, reservationCount);
			for (int i = 0; i < reservationCount; i++) { // if all things go wrong, it will be the insertion
				int day, time;
				inFile >> time; inFile.ignore(1, '\n');
				inFile >> day; inFile.ignore(1, '\n');
				buf.fetchReservationDataToUser(time, day);
			}
			userList.push_back(buf);

		}

		userList.pop_back(); //gets rid of that one extra annoying bug of istream
	}
	
	void addUser() {
		string username;
		string pass;
		string passtemp;
		string name;
		string faculty_id;
		string department;

		cout << "Enter username: ";
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, pass);
		cout << "Verify password: ";
		getline(cin, passtemp);

		while (passtemp != pass) {
			cout << "Passwords do not match! Enter a new password: ";
			getline(cin, pass);

			cout << "Verify password: ";
			getline(cin, passtemp);
		}

		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter faculty ID: ";
		getline(cin, faculty_id);
		cout << "Enter your department: ";
		getline(cin, department);

		User newUser(username, pass, name, faculty_id, department, 0);
		userList.push_back(newUser);

		cout << "User added!" << endl;
	}

	void deleteUser(string username) {
		userList.erase(returnUser(username));
	}

	bool searchUsername(string u) {
		vector<User>::iterator posItr;
		bool isFound = false;

		for (posItr = userList.begin(); posItr != userList.end(); ++posItr) {
			if (posItr->getUsername() == u) {
				isFound = true;
			}	
		}

		return isFound;
	}

	string returnName(string u) {
		return returnUser(u)->getName();
	}

	vector<User>::iterator returnUser(string u) {
		vector<User>::iterator posItr;

		for (posItr = userList.begin(); posItr != userList.end(); ++posItr) {
			if (posItr->getUsername() == u) {
				return posItr;
			}	
		}

		return userList.begin();
	}

	void printUsernames() {
		vector<User>::iterator iter;

		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			cout << iter->getUsername() << " ";
		}
	}

	void printPasswords() {
		vector<User>::iterator iter;

		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			cout << iter->getPassword() << " ";
		}
	}

	void printData() {
		vector<User>::iterator iter;

		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			cout << iter->getUsername() << " " << iter->getName() << " " << iter->getFacultyID() << " " << iter->getDepartment();
			cout << endl;
		}
	}
	void outputUserdata(ofstream& outUser) {
		vector<User>::iterator iter;

		for (iter = userList.begin(); iter != userList.end(); ++iter) {
			outUser << iter->getUsername() << endl
				    << iter->getPassword() << endl
				    << iter->getName() << endl
				    << iter->getFacultyID() << endl
				    << iter->getDepartment() << endl
			        << iter->getUserReservationCount() << endl;
			for (int i = 0; i < iter->getUserReservationCount(); i++) {
				outUser << iter->getUserTime(i) << " ";
				outUser << iter->getUserDay(i) << endl;
			}
		}
	}

};



string login(Users& UserList) {
	string username, password;
	int counter = 0;
	cout << "Enter username: ";	
	getline(cin, username);

	while (!UserList.searchUsername(username)) {
		cout << "Username not found! Try again: "; cin >> username;
	}

	if ( UserList.searchUsername(username) ) { //username found
		cout << "Enter password: ";
		getline(cin, password);

		while (password != UserList.returnUser(username)->getPassword() && counter != 3) {
			counter++;
			cout << "Wrong password! " << counter << " out of 3 tries." << endl <<  "Please re-enter: ";
			getline(cin, password);
		}

		if (counter == 3) {
			return "NULL";
		} else {
			return username;
		}
		
	} else {
		return "Username not found, or password incorrect";
	}
}
