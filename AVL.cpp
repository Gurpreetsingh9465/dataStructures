#include<iostream>

class Node {
	public:
	Node *right;
	Node *left;
	int info;
	Node(int info) {
		this->info = info;
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
		int height(Node *root) {
			if(root == NULL) {
				return 0;
			}
			int r = height(root->right);
			int l = height(root->left);
			return r>l?r+1:l+1;
		}
		int maxValue(Node *root) {
	        if(root == NULL) {
	            return -1;
	        } else {
	        	int res = root->info;
				int r = maxValue(root->right);
	            int l = maxValue(root->left);
	            res = res > r ? res : r;
	            res = res > l ? res : l;
	            return res;
	        }
    	}
    	int minValue(Node *root) {
		        if(root == NULL) {
		            return 10000;
		        } else {
		        	int res = root->info;
					int r = minValue(root->right);
		            int l = minValue(root->left);
		            res = res < r ? res : r;
		            res = res < l ? res : l;
		            return res;
		        }
		}
		Node* maxNode(Node *root) {
	        if(root == NULL) {
	            return NULL;
	        } else {
	        	Node* res = root;
				Node* r = maxNode(root->right);
	            Node* l = maxNode(root->left);
	            if(r)
	            	res = res->info > r->info ? res : r;
	            if(l)
	            	res = res->info > l->info ? res : l;
	            return res;
	        }
    	}
		void _traverse(int method, Node *root) {
			if(root!=NULL) {
				if(method == -1) {
					std::cout<<root->info<<" ";
					_traverse(method,root->left);
					_traverse(method,root->right);
				} else if(method == 1) {
					_traverse(method,root->left);
					_traverse(method,root->right);
					std::cout<<root->info<<" ";
				} else {
					_traverse(method,root->left);
					std::cout<<root->info<<" ";
					_traverse(method,root->right);
				}
			}
		}
		Node * _delete(Node *root,info) {
			if(root== NULL) 
				return NULL;
			if(root->info > info) 
				root->left = _delete(root->left,info);
			else
				root->right = _delete(root->right,info);
			if(root->info == info) {
				if(root->right == NULL && root->left == NULL)
					root = NULL;
				if(root->right && root->left) {
					int val = maxNode(root->left)->info;
					root>info = val;
					root->left = _delete(root->left,val);
					
				}
				else {
					root = root->right?root->right:root->left;
				}
			}
			int balf = getBalFactor(root);
			if(balf != -1 || balf != 1 || balf != 0) {
				if(balf == 2) {
					if(root->left->info<info) { //lr
						root->left = leftRotate(root->left);
						return rightRotate(root);
					} else { //ll
						return rightRotate(root->left);
					}
				}
				if(balf == -2) {
					if(root->left->info<info) { //rr
						return leftRotate(root->right);
					} else { //rl
						root->right = rightRotate(root->right);
						return leftRotate(root);
					}
				}
			}
			return root;
			
			
		}
		Node * leftRotate(Node *x) {
			Node *y = x ->right;
			Node *t2 = y->left;
			y->left = x;
			x->right = t2;
			return y;
		}
		Node * rightRotate(Node *y) {
			Node *x = y ->left;
			Node *t2 = x->right;
			x->right = y;
			y->left = t2;
			return x;
		}
		int getBalFactor(Node *root) {
			int l = height(root->left);
			int r = height(root->right);
			return l-r;
		}
		Node * _insert(Node *root,int info) {
			if(root == NULL) {
				root = new Node(info);
				return root;
			}
			if(info < root->info)
				root->left = _insert(root->left,info);
			else 
				root->right = _insert(root->right,info);
			int balf = getBalFactor(root);
			if(balf != -1 || balf != 1 || balf != 0) {
				if(balf == 2) {
					if(root->left->info<info) { //lr
						root->left = leftRotate(root->left);
						return rightRotate(root);
					} else { //ll
						return rightRotate(root->left);
					}
				}
				if(balf == -2) {
					if(root->left->info<info) { //rr
						return leftRotate(root->right);
					} else { //rl
						root->right = rightRotate(root->right);
						return leftRotate(root);
					}
				}
			}
			return root;
		}
		public:
			AVLtree() {
				start = NULL;
			}
			void insert(int info) {
				start = _insert(start,info);
			}
			void traverse(int method) {
				_traverse(method,start);
				std::cout<<std::endl;
			}
};


main() {
	AVLtree * t = new AVLtree();
	t->insert(4);
	t->insert(45);
	t->insert(50);
//	t->insert(49);
//	t->insert(90);
//	t->insert(89);
//	t->insert(2);
//	t->insert(3);
//	t->insert(7);
//	t->insert(50);
	t->traverse(0);
	t->traverse(1);
	t->traverse(-1);
}
















