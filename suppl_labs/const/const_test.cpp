#include <iostream>
#include "const.h"

using namespace std;

int main() {
    ConstExample constExample(0);

    int& localA = constExample.returnAConst();

    while (localA < 10) {
        constExample.constMemberFunction();
        localA++;
    }

    if (constExample.constParameter(localA)) {
        cout << "localA is equal to member a." << endl;
    } else {
        cout << "ERROR: localA is no longer equal to member a!" << endl;
    }

    return 0;
}