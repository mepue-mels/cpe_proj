#ifndef RESERVATIONMATRIX_H
#define RESERVATIONMATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class ReservationContainer {
private:
    bool reservationMatrix[9][7];
    string reserverMatrix[9][7];
    string currentUser;
public:
    ReservationContainer();
    ReservationContainer(ifstream& boolFile, ifstream& reserverFile);
    bool getStatus(int row, int col) const;
    string getReserver(int row, int col) const;
    void setReserver(string name, int row, int col);
    void setCurrentUser(string u);
    void changeStatus(int row, int col, bool val);
    void reserve(int row, int col);
    void remove(int row, int col);
    void removeUserReservations(string username);
    void getData(ifstream& boolFile, ifstream& reserverFile);
};

ReservationContainer::ReservationContainer() {

}

ReservationContainer::ReservationContainer(ifstream& boolFile, ifstream& reserverFile) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            boolFile >> reservationMatrix[i][j];
            reserverFile >> reserverMatrix[i][j];
        }
    }
}

bool ReservationContainer::getStatus(int row, int col) const {
    return reservationMatrix[row][col];
}

string ReservationContainer::getReserver(int row, int col) const {
    return reserverMatrix[row][col];
}

void ReservationContainer::setReserver(string name, int row, int col) {
    reserverMatrix[row][col] = name;
}

/*
void Reservation::changeStatus(int row, int col, bool val) {
    if (getStatus(row,col) == true) { // if deleting
        if (currentUser == reserverFile[row][col]) 
    }
    reservationMatrix[row][col] = val;
e    reserverMatrix[row][col] = currentUser;
}
*/

void ReservationContainer::reserve(int row, int col) {
    if (reservationMatrix[row][col] == true) {
        cout << "Cannot reserve in a reserved slot!" << endl << endl;
    } else {
        reservationMatrix[row][col] = 1;
        reserverMatrix[row][col] = currentUser;
    }

}

void ReservationContainer::remove(int row, int col) {
    if (reservationMatrix[row][col] == true) {
        if (currentUser == reserverMatrix[row][col]) {
            reservationMatrix[row][col] = false;
            reserverMatrix[row][col] = "NULL";
        }
    } else {
        cout << "You can only delete your own reservations!";
    }
}

void ReservationContainer::removeUserReservations(string username) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            if (reserverMatrix[i][j] == username) {
                reservationMatrix[i][j] = false;
            }
        }
    }
}

void ReservationContainer::getData(ifstream& boolFile, ifstream& reserverFile) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            boolFile >> reservationMatrix[i][j];
            reserverFile >> reserverMatrix[i][j];
        }
    }
}

void ReservationContainer::setCurrentUser(string u) {
    currentUser = u;
}



#endif // RESERVATIONMATRIX_H_
