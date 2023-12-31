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
    vector<ReservationContainer> roomArray;
    Users userList;
public:
    Database();
    Database(ifstream& boolFile, ifstream& reserverFile, Users u, string currentUser);
    ReservationContainer &returnMatrix(int roomIndex);
    string getReserverName(int roomIndex, int row, int col);
    void reserveMatrixEntry(int roomIndex, int row, int col);
    void printMatrix(int roomIndex);
    void outputMatrix(ofstream& boolFile, ofstream& reserverFile);
    void removeUserReservations(string username);
    void addUser();
};


Database::Database() {

}

Database::Database(ifstream& boolFile, ifstream& reserverFile, Users u, string currentUser) {
    ReservationContainer buffer;
    roomArray.assign(5, buffer); // initialize five reservation matrices
    vector<ReservationContainer>::iterator vecIter;

    for (vecIter = roomArray.begin(); vecIter != roomArray.end(); ++vecIter) { // fetches reservation data for each room
        vecIter->getData(boolFile, reserverFile);
        vecIter->setCurrentUser(currentUser);
    }

    userList = u;
}

string Database::getReserverName(int roomIndex, int row, int col) {
    return userList.returnName(returnMatrix(roomIndex).getReserver(row,col));
}

ReservationContainer& Database::returnMatrix(int roomIndex) {
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

void Database::removeUserReservations(string username) {
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 7; j++) {
                if (returnMatrix(k).getReserver(i,j) == username) {
                    returnMatrix(k).remove(i,j);
                    returnMatrix(k).setReserver("NULL", i, j);
                }
            }
        }
    }
}

void Database::outputMatrix(ofstream& boolFile, ofstream& reserverFile) {
    vector<ReservationContainer>::iterator roomItr;
    vector<User>::iterator userItr;

    for (roomItr = roomArray.begin(); roomItr != roomArray.end(); ++roomItr) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 7; j++) {
                boolFile << roomItr -> getStatus(i,j) << " ";
                reserverFile << roomItr -> getReserver(i,j) << " ";
            }
            boolFile << endl;
            reserverFile << endl;
        }
    }
}

void Database::addUser() {
    userList.addUser();
}

void Database::reserveMatrixEntry(int roomIndex, int row, int col) {
    returnMatrix(roomIndex).reserve(row, col);
}


#endif // DATABASE_H_
