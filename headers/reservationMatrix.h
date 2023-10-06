#ifndef RESERVATIONMATRIX_H
#define RESERVATIONMATRIX_H

#include <iostream>
#include <fstream>
using namespace std;

class Reservation {
private:
    bool reservationMatrix[9][7];
    string reserverMatrix[9][7];
public:
    Reservation();
    Reservation(ifstream& boolFile, ifstream& reserverFile);
    bool getStatus(int row, int col) const;
    void changeStatus(int row, int col, bool val);
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

void Reservation::changeStatus(int row, int col, bool val) {
    reservationMatrix[row][col] = val;
}

void Reservation::getData(ifstream& boolFile, ifstream& reserverFile) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            boolFile >> reservationMatrix[i][j];
            reserverFile >> reserverMatrix[i][j];
        }
    }
}



#endif // RESERVATIONMATRIX_H_
