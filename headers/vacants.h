#ifndef VACANTS_H
#define VACANTS_H

#include <iostream>
using namespace std;

class Vacants {
private:
    int count;
    int index;
public:
    Vacants() {
        count = 0;
        index = 0;
    }
    void set (int c, int i) {
        count = c;
        index = i;
    }

    int getCount() {
        return count;
    }

    int getIndex() {
        return index;
    }
};



#endif // VACANTS_H_
