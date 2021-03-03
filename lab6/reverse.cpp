
#include <stddef.h>
using namespace std;


struct Node {
  int val; 
  Node* next; 

  Node(int v) : val(v), next(NULL) {}
  Node() : val(0), next(NULL) {}
}; 

Node* reverse (Node* head) {
    //base case
    if(head->next == NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    //the old head->next is now at the end of the newHead array
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Example usage
int main() {
  Node* head = new Node(1); 
  head->next = new Node(3); 
  head->next->next = new Node(5); 

  Node* new_head = reverse(head); // should get 5->3->1
}