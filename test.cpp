#include <iostream>
#include <fstream>
#include "headers/Database.h"

using namespace std;

int main() {
    ifstream boolFile("sampledata/boolFile");
    ifstream reserverFile("sampledata/reserverFile");
    ifstream userFile("sampledata/userFile");

    Database Data(boolFile, reserverFile, userFile);

    Data.returnMatrix(1).reserve(0,1);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            cout << Data.returnMatrix(1).getStatus(i, j) << " ";
        }
        cout << endl;
    }

}
