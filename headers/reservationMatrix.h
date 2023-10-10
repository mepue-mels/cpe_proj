#ifndef RESERVATIONMATRIX_H
#define RESERVATIONMATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class Reservation {
private:
    bool reservationMatrix[9][7];
    string reserverMatrix[9][7];
    string currentUser;
public:
    Reservation();
    Reservation(ifstream& boolFile, ifstream& reserverFile);
    bool getStatus(int row, int col) const;
    string getReserver(int row, int col) const;
    void setCurrentUser(string u);
    void changeStatus(int row, int col, bool val);
    void reserve(int row, int col);
    void remove(int row, int col);
    void getData(ifstream& boolFile, ifstream& reserverFile);
};

Reservation::Reservation() {

}

Reservation::Reservation(ifstream& boolFile, ifstream& reserverFile) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            boolFile >> reservationMatrix[i][j];
            reserverFile >> reserverMatrix[i][j];
        }
    }
}

bool Reservation::getStatus(int row, int col) const {
    return reservationMatrix[row][col];
}

string Reservation::getReserver(int row, int col) const {
    return reserverMatrix[row][col];
}

/*
void Reservation::changeStatus(int row, int col, bool val) {
    if (getStatus(row,col) == true) { // if deleting
        if (currentUser == reserverFile[row][col]) 
    }
    reservationMatrix[row][col] = val;
    reserverMatrix[row][col] = currentUser;
}
*/

void Reservation::reserve(int row, int col) {
    if (reservationMatrix[row][col] == true) {
        cout << "Cannot reserve in a reserved slot!";
    } else {
        reservationMatrix[row][col] = true;
        reserverMatrix[row][col] = currentUser;
    }

}

void Reservation::remove(int row, int col) {
    if (reservationMatrix[row][col] == true) {
        if (currentUser == reserverMatrix[row][col]) {
            reservationMatrix[row][col] = false;
            reserverMatrix[row][col] = "NULL";
        }
    } else {
        cout << "You can only delete your own reservations!";
    }
}

void Reservation::getData(ifstream& boolFile, ifstream& reserverFile) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            boolFile >> reservationMatrix[i][j];
            reserverFile >> reserverMatrix[i][j];
        }
    }
}

void Reservation::setCurrentUser(string u) {
    currentUser = u;
}



#endif // RESERVATIONMATRIX_H_
