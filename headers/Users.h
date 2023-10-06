#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

class User {
private:
	string username;
	string pass;
	string name;
	string faculty_id;
	string department;
public:
	User() {
		username = "";
		pass = "";
	}

	User(string u, string p, string n, string i, string d) {
		username = u;
		pass = p;
		name = n;
		faculty_id = i;
		department = d;
	}

	void set(string u, string p, string n, string i, string d) {
		username = u;
		pass = p;
		name = n;
		faculty_id = i;
		department = d;
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
};

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

		while (inFile) {
//			inFile >> user >> pass >> name >> faculty_id >> department;
			getline(inFile, user);
			getline(inFile, pass);
			getline(inFile, name);
			getline(inFile, faculty_id);
			getline(inFile, department);
			buf.set(user,pass, name, faculty_id, department);
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
			cin >> pass;

			cout << "Verify password: ";
			cin >> passtemp;
		}

		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter faculty ID: ";
		getline(cin, faculty_id);
		cout << "Enter your department: ";
		getline(cin, department);

		User newUser(username, pass, name, faculty_id, department);
		userList.push_back(newUser);

		cout << "User added!" << endl;
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

};



string login(Users& UserList) {
	string username, password;
	int counter = 0;
	cout << "Enter username: ";	
	cin >> username;

	if ( UserList.searchUsername(username) ) { //username found
		cout << "Enter password: ";
		cin >> password;
		
		while (password != UserList.returnUser(username)->getPassword() && counter != 3) {
			counter++;
			cout << "Wrong password! " << counter << " out of 3 tries." << endl <<  "Please re-enter: ";
			cin >> password;
		}

		if (counter == 3) {
			return "NULL";
		} else {
			return username;
		}
		
	} else {
		return "Username not found or password incorrect";
	}
}
