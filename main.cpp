#include <iostream>
#include <fstream>
#include <vector>
#include "Database.h"
#include "queueSys.h"
#include "reservationMatrix.h"

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("data.txt");

    Database Data(inFile);
    Queueing Queue(Data);

    Queue.getVacants(1);

    Queue.printVacantList();

    /*
    bool reservationMatrix[9][7];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            inFile >> reservationMatrix[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            inFile >> reservationMatrix[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            cout << reservationMatrix[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}
