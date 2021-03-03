#include "LimitedList.h"

class Brain: public LimitedList
{
public:
    Brain(int capacity): LimitedList(capacity){
        cap = capacity;
    }
    void remember (const string & fact) {
        remove(find(fact));
        learn(fact);
    }
    void learn (const string & fact) {
        try{
            insert(size(), fact);
        }catch(exception& e){
            remove(0);
            insert(size(), fact);
        }
    }
private:
    int cap; // any data or methods you would like to add
};