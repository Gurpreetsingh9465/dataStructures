#include<iostream>

class Node {
	Node *right;
	Node *left;
	int val;
	int h;
	Node(int info) {
		this->val = info;
		h = 1;
		right = NULL;
		left = NULL;
	}
	~Node() {
		right = NULL;
		left = NULL;
	}
};
class AVLtree {
	private:
		Node * start;
		void insert(int info);
		int findHeight(Node *root) {
			if(root == NULL) {
				return 0;
			}
			int r = findHeight(root->right);
			int l = findHeight(root->left);
			return r>l?r+1:l+1;
		}
		Node * _insertNode(Node *root, info) {
			if(root == NULL) {
				root = new Node(info);
				root->bf = findHeight(root->left) - findHeight(root->right);
			}
			if(info < root->val)
				root->left = insertNode(root->left,info);
			else
				root->right = insertNode(root->right,info);
			return root;
		}
	public:
		AVLtree() {
			start = NULL;
		}
		void insertNode(int info) {
			start = _insertNode(start,info);
		}
};


main() {
	AVLtree * t = new AVLtree();
}
















