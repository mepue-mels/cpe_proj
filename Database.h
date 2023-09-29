#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "reservationMatrix.h"
using namespace std;

class Database {
private:
    vector<Reservation> roomArray;
public:
    Database();
    Database(ifstream& inFile);
    Reservation returnMatrix(int dayIndex);
    void printMatrix(int dayIndex);
};


Database::Database() {

}

Database::Database(ifstream& inFile) {
    Reservation buffer;
    roomArray.assign(5, buffer); // initialize five reservation matrices
    vector<Reservation>::iterator vecIter;

    for (vecIter = roomArray.begin(); vecIter != roomArray.end(); ++vecIter) { // fetches reservation data for each room
        vecIter->getData(inFile);
    }
}

Reservation Database::returnMatrix(int dayIndex) {
    return roomArray[dayIndex];
}

void Database::printMatrix(int dayIndex) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            cout << roomArray[dayIndex].getStatus(i,j) << " ";
        }
        cout << endl;
    }
}


#endif // DATABASE_H_
