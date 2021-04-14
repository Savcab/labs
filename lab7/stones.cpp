#include "stones.h"
#include <queue> // to use std::priority_queue

//using my own implemented heap
#include "../../Scratch/Heap/heap.h"
#include "../../Scratch/Heap/heap.cpp"

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    Heap<int> pq;
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
        //debug
        pq.printHeap();
        int big1, big2;
        bool equal;
        big1 = pq.top();
        pq.pop();
        big2 = pq.top();
        pq.pop();
        equal = (big1 == big2);
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
