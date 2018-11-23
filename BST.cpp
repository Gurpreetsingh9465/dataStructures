#include<iostream>
#include<stdlib.h>
class BST
{
	private:
		struct node {
			node *right;
			node *left;
			int info;
		};
		node **start;
		node * insert(int info, node * root) {
			if(root == NULL) {
				node *newnode = newnode;
				newnode->right = NULL;
				newnode->left = NULL;
				newnode->info = info;
				return newnode;
			} else {
				if(root->info < info) {
					insert(info,root->right);
				} else {
					insert(info,root->left);
				}
			}
			return root;
		}
		void traverse(int method, node *root) {
			while(root) {
				if(method == 0) {
					traverse(method,root->left);
					std::cout<<root->info<<" ";
					traverse(method,root->right);
				}
			}
		}
	public:
		BST() {
			*start = NULL;
		}
		void insertNode(int info) {
			*start = this->insert(info,*start);
		}
		void traverseNodes(int method = 0) {
			this->traverse(method, *start);
		}
};


main()
{
	BST *bst = new BST();
	bst->insertNode(5);
	bst->insertNode(4);
	bst->insertNode(8);
	bst->insertNode(10);
	bst->insertNode(0);
	bst->insertNode(9);
	bst->traverseNodes();
}
