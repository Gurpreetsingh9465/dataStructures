#include<iostream>
#include<stdlib.h>

class Node {
	public:
		Node *right;
		Node * left;
		int info;
		Node(int info) {
			this->info = info;
			right = left = NULL;
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
};
main()
{
	BST *bst = new BST();
	bst->insertNode(5);
	bst->insertNode(0);
	bst->insertNode(45);
	bst->insertNode(4);
	bst->insertNode(8);
	bst->insertNode(10);
	bst->insertNode(9);
	bst->traverseNodes(0);
	bst->traverseNodes(-1);
	bst->traverseNodes(1);
}
