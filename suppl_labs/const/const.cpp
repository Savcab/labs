#include <iostream>
#include "const.h"

using namespace std;

ConstExample::ConstExample(int val) {
    a = val;
}

// Return type will be const.
const int& ConstExample::returnAConst() {
    return a;
}

// Cannot modify any member variables
void ConstExample::constMemberFunction() const {
    a++;
    cout << a << endl;
}

// Cannot modify b.
bool ConstExample::constParameter(const int& b) {
    a++;
    b++;
    return a == b;
}