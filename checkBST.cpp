#include<iostream>
#include<stdlib.h>
#include<queue>
class Node {
	public:
		Node *right;
		Node * left;
		int data;
		Node(int info) {
			this->data = info;
			right = left = NULL;
		}
};
int maxValue(Node *root) {
        if(root == NULL) {
            return -1;
        } else {
        	int res = root->data;
			int r = maxValue(root->right);
            int l = maxValue(root->left);
            res = res > r ? res : r;
            res = res > l ? res : l;
            return res;
        }
}

int minValue(Node *root) {
        if(root == NULL) {
            return 100000;
        } else {
        	int res = root->data;
			int r = minValue(root->right);
            int l = minValue(root->left);
            res = res < r ? res : r;
            res = res < l ? res : l;
            return res;
        }
}

bool checkBST(Node* root) {
        
        if(root->left != NULL) {
            if(maxValue(root->left)> root->data)
                return false;
        } 
        if(root->right != NULL) {
            if(minValue(root->right) < root->data)
                return false;
        }
        bool r;
        bool l;
        l = root->left!=NULL?checkBST(root->left):true;
        r = root->right!=NULL?checkBST(root->right):true;
        if(r == false || l == false)
            return false;
        return true;
	}

bool isSimilar(Node *r1,Node *r2) {
	if(r1 == NULL && r2 != NULL) {
		return false;
	}
	if( r1 != NULL && r2 == NULL) {
		return false;
	}
	if( r1 == NULL && r2 == NULL) {
		return true;
	}
	if(!r1->right && !r1->left && !r2->left && !r2->right ) {
		return true;
	}
	bool r = isSimilar(r1->right,r2->right);
	bool l = isSimilar(r1->left,r2->left);
	if (r == true && l == true)
		return true;
	return false;
}

bool isEqual(Node *r1,Node *r2) {
	if(r1 == NULL && r2 != NULL) {
		return false;
	}
	if( r1 != NULL && r2 == NULL) {
		return false;
	}
	if( r1 == NULL && r2 == NULL) {
		return true;
	}
	if((r1->data == r2->data) && !r1->right && !r1->left && !r2->left && !r2->right ) {
		return true;
	}
	if((r1->data != r2->data) && !r1->right && !r1->left && !r2->left && !r2->right ) {
		return false;
	}
	bool r = isEqual(r1->right,r2->right);
	bool l = isEqual(r1->left,r2->left);
	if (r == true && l == true && r1->data == r2->data )
		return true;
	return false;
}
 bool isMirrorImage(Node *r1,Node *r2) {
 	if(r1 == NULL && r2 == NULL) {
 		return true;
	}
	if(!r1 || !r2) {
		return false;
	}
	if( r1->data == r2->data ) {
		bool r = isMirrorImage (r1->right,r2->left);
		bool l = isMirrorImage (r1->left,r2->right);
		return r && l;
	}
	return false;
 }
bool isPath(Node *root, int sum) {
	if ( root == NULL ) 
		return sum == 0;
	int subsum = sum - root->data;
	if( subsum == 0 && !root->right && !root->left) {
		return true;
	}
	bool r,l;
	if(root->right) {
		r = isPath(root->right, subsum);
	}
	if(root->left) {
		l = isPath(root->left,subsum);
	}
	return l || r;
}


main() {
	Node * r1,*r2,*r3;
	r1 = new Node(4);
	r1->left = new Node(5);
	r1->right = new Node(7);
	r1->left->left = new Node(8);
	r1->left->right = new Node(4);
	r1->right->left = new Node(6);
	r1->right->right = new Node(10);
	r1->right->right->right = new Node(10);
	r2 = new Node(4);
	r2->left = new Node(5);
	r2->right = new Node(7);
	r2->left->left = new Node(8);
	r2->left->right = new Node(4);
	r2->right->left = new Node(6);
	r2->right->right = new Node(1);
	r2->right->right->right = new Node(10);
	std::cout<<isSimilar(r1,r2)<<std::endl;
	std::cout<<isEqual(r1,r2)<<std::endl;
	r3 = new Node(4);
	r3->right = new Node(45);
	r3->left = new Node(45);
	std::cout<<isPath(r2,17)<<std::endl;
}
