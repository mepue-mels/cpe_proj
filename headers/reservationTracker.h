#ifndef RESERVATIONTRACKER_H
#define RESERVATIONTRACKER_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Reservation {
private:
    int time;
    int day;
public:
    Reservation() {
        time = 0;
        day = 0;
    }

    Reservation(int t, int d) {
        time = t;
        day = d;
    }

    int getTime() const {
        return time;
    }

    int getDay() const {
        return day;
    }

    void setTime(int t) {
        time = t;
    }

    void setDay(int d) {
        day = d;
    }
};

class ReservationTracker {
private:
    vector<Reservation> reservationList;
    int reservationCount;
public:

    int getReservationCount() const {
        return reservationCount;
    }

    void setReservationCount(int rC) {
        reservationCount = rC;
    }

    void addReservation(int t, int d) {
        Reservation res(d,t);
        reservationList.push_back(res);
        reservationCount++;
    }

    void initialAddReservation(int t, int d) {
        Reservation res(t,d);
        reservationList.push_back(res);
    }

    bool searchReservation(int t, int d) {
        vector<Reservation>::iterator vecIter;
        bool isFound = false;

        for (vecIter = reservationList.begin(); vecIter != reservationList.end(); ++vecIter) {
            if ( vecIter->getTime() == t && vecIter->getDay() == d ) {
                isFound = true;
                break;
            }
        }

        return isFound;
    }

    void removeReservation(int t, int d) {
        vector<Reservation>::iterator vecIter;
        bool isDeleted = false;

        for (vecIter = reservationList.begin(); vecIter != reservationList.end(); ++vecIter) {
            if ( vecIter->getTime() == t && vecIter->getDay() == d ) {
                reservationList.erase(vecIter);
                isDeleted = true;
                break;
            }
        }

        if (!isDeleted) {
            cout << "Reservation not found!" << endl;
        } else {
            reservationCount--;
        }
    }

    void clearUserReservationList() {
        while (!reservationList.empty()) {
            reservationList.pop_back();
        }
    }

    int getUserReservationTime(int listIndex) {
        return reservationList[listIndex].getTime();
    }

    int getUserReservationDay(int listIndex) {
        return reservationList[listIndex].getDay();
    }
};
#endif
