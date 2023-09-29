#ifndef QUEUESYS_H
#define QUEUESYS_H

#include <iostream>
#include <vector>
#include "vacants.h"
#include "Database.h"

class Queueing {
private:
    Database Data;
    vector<Vacants> vacList;
    vector<Vacants> maxVacList;
public:
    Queueing(Database d);
    void getVacants(int dayIndex);
    void printVacantList();
    int mostVacants();
};

Queueing::Queueing(Database d) {
    Data = d;
}

void Queueing::getVacants(int dayIndex) {
    int count = 0;
    Vacants vacantCount;

    for (int j = 0; j < 7; j++) {
        for (int i = 0; i < 9; i++) {
            if ( Data.returnMatrix(dayIndex).getStatus(i,j)) {
                count++;
            }
        }
        vacantCount.set(count, j);
        vacList.push_back(vacantCount);
        count = 0;
    }
}

void Queueing::printVacantList() {
    vector<Vacants>::iterator vecIter;

    for (vecIter = vacList.begin(); vecIter != vacList.end(); ++vecIter) {
        cout << vecIter->getCount() << " ";
    }
}


#endif // QUEUESYS_H_
