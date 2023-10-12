#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "reservationMatrix.h"
#include "Users.h"
using namespace std;

class Database {
private:
    vector<Reservation> roomArray;
    Users userList;
public:
    Database();
    Database(ifstream& boolFile, ifstream& reserverFile, Users u);
    Reservation returnMatrix(int roomIndex);
    string getReserverName(int roomIndex, int row, int col);
    void printMatrix(int roomIndex);
    void outputMatrix(ofstream& outFile);
};


Database::Database() {

}

Database::Database(ifstream& boolFile, ifstream& reserverFile, Users u) {
    Reservation buffer;
    roomArray.assign(5, buffer); // initialize five reservation matrices
    vector<Reservation>::iterator vecIter;

    for (vecIter = roomArray.begin(); vecIter != roomArray.end(); ++vecIter) { // fetches reservation data for each room
        vecIter->getData(boolFile, reserverFile);
    }

    userList = u;
}

string Database::getReserverName(int roomIndex, int row, int col) {
    return userList.returnName(returnMatrix(roomIndex).getReserver(row,col));
}

Reservation Database::returnMatrix(int roomIndex) {
    return roomArray[roomIndex];
}

void Database::printMatrix(int roomIndex) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            cout << roomArray[roomIndex].getStatus(i,j) << " ";
        }
        cout << endl;
    }
}

void Database::outputMatrix(ofstream& outFile) {
    vector<Reservation>::iterator roomItr;
    vector<User>::iterator userItr;

    for (roomItr = roomArray.begin(); roomItr != roomArray.end(); ++roomItr) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 7; j++) {
                outFile << roomItr -> getStatus(i,j) << " ";
            }
            outFile << endl;
        }
    }
}



#endif // DATABASE_H_
