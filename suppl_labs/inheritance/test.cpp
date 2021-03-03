#include <exception>

bool subsequence(Node* a, Node* b, Node* c){
	if(c == NULL){ return false; }
	if(a == NULL && b->next == NULL){
		return (c->next == NULL) && (c->value == b->value);
} else if(a->next == NULL && b == NULL){
	return (c->next == NULL) && (c->value == a->value);
}
  
  if(c->value == a->value){
      return subsequence(a->next, b, c->next);
    } else if(c->value == b->value){
      return subsequence(a, b->next, c->next);
    } else {
      return false;
  }
}
