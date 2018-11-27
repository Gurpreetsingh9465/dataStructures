#include<iostream>
#include<stdlib.h>
#include<stack>
#include <queue> 

class Node {
	public:
		Node *right;
		Node * left;
		int info;
		Node(int info) {
			this->info = info;
			right = left = NULL;
		}
		~Node() {
			right = NULL;
			left = NULL;
		}
};

class BST
{
	private:
		Node *start;
		Node * insert(int info, Node * root) {
			if(root == NULL) {
				Node *newnode = new Node(info);
				root = newnode;
			} else {
				if(root->info < info) {
					root->right = insert(info,root->right);
				} else {
					root->left = insert(info,root->left);
				}
			}
			return root;
		}
		void traverse(int method, Node *root) {
			if(root!=NULL) {
				if(method == -1) {
					std::cout<<root->info<<" ";
					traverse(method,root->left);
					traverse(method,root->right);
				} else if(method == 1) {
					traverse(method,root->left);
					traverse(method,root->right);
					std::cout<<root->info<<" ";
				} else {
					traverse(method,root->left);
					std::cout<<root->info<<" ";
					traverse(method,root->right);
				}
			}
		}
		int height(Node *root) {
			if (root == NULL) {
				return 0;
			} else {
				int r = height(root->left);
				int l = height(root->right);
				int max = r>l?r:l;
				return max+1;
			}
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
    	Node* minNode(Node *root) {
	        if(root == NULL) {
	            return NULL;
	        } else {
	        	Node* res = root;
				Node* r = minNode(root->right);
	            Node* l = minNode(root->left);
	            if(r)
	            	res = res->info < r->info ? res : r;
	            if(l)
	            	res = res->info < l->info ? res : l;
	            return res;
	        }
    	}
		Node * find(Node *root, int val) {
			if(root == NULL) {
				return NULL;
			} else {
				if(root->info == val) {
					return root;
				}
				if(root->info > val) {
					return find(root->left,val);
				} else {
					return find(root->right,val);
				}
			}
		}
		Node * _findParent(Node *root, int val) {
			if(root == NULL) {
				return NULL;
			}
			if(root->info == val)
				return root;
			if(root->left == NULL && root->right == NULL) {
				return NULL;
			}
			if (root->left || root->right)
				if(root->left)
					if(root->left->info == val)
						return root;
				if(root->right)
					if(root->right->info == val)
						return root;
			if(root->info > val && root->left) {
				return _findParent(root->left,val);
			} else {
				return _findParent(root->right,val);
			}
		}
		Node * _deleteNode(Node *root,int val) {
			if(root == NULL)
				return root;
			if(val < root->info)
				root->left = _deleteNode(root->left,val);
			else if(val > root->info)
				root->right = _deleteNode(root->right,val);
			else {
				if(!root->left) {
					Node *temp = root->right;
					delete root;
					return temp;
				}
				if(!root->right) {
					Node *temp = root->left;
					delete root;
					return temp;
				}
				Node * temp = maxNode(root->left);
				root->info = temp->info;
				root->left = _deleteNode(root->left,temp->info);
				return root;
			}
		}
		int _countNodes(Node *root) {
			if(root == NULL) {
				return 0;
			}
			if(root->left == NULL && root->right == NULL) {
				return 1;
			}
			int r;
			int l;
			r = _countNodes(root->right);
			l = _countNodes(root->left);
			return r+l+1;
		}
		bool _checkExist(Node *root,int val) {
			Node *node = find(root,val);
			return node?true:false;
		}
	public:
		BST() {
			start = NULL;
		}
		void insertNode(int info) {
			start = this->insert(info,start);
		}
		void test() {
			if(start) {
				std::cout<<start->info;	
				std::cout<<start->left->info;	
				std::cout<<start->right->info;
				std::cout<<start->right->left;
			}
		}
		int getMaxValue() {
			return maxNode(this->start)->info;
		}
		int getMinValue() {
			return minNode(this->start)->info;
		}
		void traverseNodes(int method = 0, bool print = true) {
			if(method == -1 && print) {
				std::cout<<"preOrder = ";
			} else if(method == 1 && print) {
				std::cout<<"postOrder = ";
			} else if(method == 0 && print){
				std::cout<<"inOrder = ";
			}
			traverse(method, start);
			std::cout<<std::endl;
		}
		int findPar(int val) {
			Node *temp = _findParent(start,val);
			return temp?temp->info:-1;
		}
		int findHeight() {
			return height(this->start);
		}
		void deleteNode(int val) {
			start = _deleteNode(start,val);
		}
		bool checkExist(int val) {
			return _checkExist(start,val);	
		}
		int count() {
			return _countNodes(start);
		}
};
main()
{
	BST *bst = new BST();
	bst->insertNode(23);
	bst->insertNode(2);
	bst->insertNode(89);
	bst->insertNode(34);
	bst->insertNode(99);
	bst->insertNode(67);
	bst->traverseNodes(0);
	bst->traverseNodes(-1);
	bst->traverseNodes(1);
//	bst->insertNode(48);
//	bst->insertNode(45);
//	bst->insertNode(4);
//	bst->insertNode(8);
//	bst->insertNode(10);
//	bst->insertNode(9);
//	bst->insertNode(2);
//	bst->insertNode(12);
//	bst->insertNode(72);
//	bst->insertNode(95);
//	bst->insertNode(46);
//	bst->insertNode(47);
//	bst->traverseNodes(0);
//	bst->traverseNodes(-1);
//	bst->traverseNodes(1);
//	std::cout<<bst->findHeight()<<std::endl<<bst->getMaxValue()<<" "<<bst->getMinValue()<<" "<<bst->count()<<std::endl;
//	std::cout<<bst->findPar(12)<<" "<<bst->checkExist(100)<<std::endl;
//	bst->deleteNode(72);
//	bst->deleteNode(8);
//	bst->deleteNode(5);
//	bst->deleteNode(9);
//	bst->traverseNodes(0);
//	bst->traverseNodes(-1);
//	bst->traverseNodes(1);
//	std::cout<<bst->count();
	
}
