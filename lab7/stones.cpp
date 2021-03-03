#include "stones.h"
#include <queue> // to use std::priority_queue
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    //intiate the priority queue
    for(vector<int>::iterator it = stones.begin(); it != stones.end(); it++){
        pq.push(*it);
    }
    //edge case: if 0 element in vector
    if(pq.size() == 0){
        return 0;
    }
    //edge case: if only 1 element in vector
    if(pq.size() == 1){
        return pq.top();
    }
    while(pq.size() > 1){
        int big1, big2;
        bool equal;
        big1 = pq.top();
        pq.pop();
        big2 = pq.top();
        pq.pop();
        equal = big1 == big2;
        if(!equal){
            pq.push(big1-big2);
        }
    }
    if(pq.size() == 0){
        pq.push(0);
    }
    //now there's only one element in the pq
    return pq.top();

}
