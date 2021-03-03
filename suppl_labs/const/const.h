#include <iostream>

class ConstExample {
    public:
        ConstExample(int val);

        // Return a.
        const int& returnAConst();

        // Output a.
        void constMemberFunction() const;

        // Return true if a is equal to b.
        bool constParameter(const int& b);
    private:
        int a;
};