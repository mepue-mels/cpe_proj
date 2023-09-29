#ifndef GUI_H
#define GUI_H

#include <iostream>
#include "reservationMatrix.h"
#include "queueSys.h"

using namespace std;

class GUI {
private:
    int decision;
    int EXIT_FLAG;
    Reservation* matrix;
    Queueing* queue;
public:
    GUI(Reservation* m, Queueing* q);
    int getDecision();
    int getFlag();
    void setDecision(int d);
    void setFlag(int f);
    void initialize();
    void showReservations();
};

GUI::GUI(Reservation* m, Queueing* q) {
    matrix = m;
    queue = q;
}

int GUI::getDecision() {
    return decision;
}

int GUI::getFlag() {
    return EXIT_FLAG;
}


void GUI::setDecision(int d) {
    decision = d;
}

void GUI::setFlag(int f) {
    EXIT_FLAG = f;
}

void GUI::showReservations() {
   string dayArray[7] = {"Monday", "Tuesday",
                    "Wednesday", "Thursday",
                    "Friday", "Saturday",
                    "Sunday"
   };

}

void GUI::initialize() {
    cout << "Intramuros Project v1.0 alpha"
         << endl
         << "(1) ";
}



#endif // GUI_H_
