#include "bst.h"

using namespace std;

int rangeSum(Node *root, int L, int R) {
	//base case
	if(root == NULL){
		return 0;
	}
	int ans = 0;
	//recursive case
	ans += rangeSum(root->left, L, R);
	ans += rangeSum(root->right, L, R);
	if(root->key <= R && root->key >= L){
		ans += root->key;
	}

	return ans;
}
