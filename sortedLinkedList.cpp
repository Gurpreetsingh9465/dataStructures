#include<iostream>
#include<stdlib.h>
class SortedLL {
	private:
		class node {
			public:
				int info;
				node *next;
				node(int info) {
					this->info = info;
					next = NULL;
				}
				~node() {
					next = NULL;
				}
		};
		node *start;
		int size;
	public:
		SortedLL() {
			start = NULL;
			size = 0;
		}
		void insert(int info) {
			node *newNode = new node(info);
			size += 1;
			if(start == NULL) {
				start = newNode;
			} else {
				node *temp = start;
				node *prev = NULL;
				while(temp != NULL && temp->info < info) {
					prev = temp;
					temp = temp->next;
				} 
				if(prev == NULL) {
					newNode->next = start;
					start = newNode;
					return;
				}
				if(temp == NULL) {
					prev->next = newNode;
					return;
				}
				newNode->next = prev->next;
				prev->next = newNode;
				return;
			}
		}
		void remove(int info) {
			if(start == NULL) {
				throw "underflow";
			}
			node *temp = start;
			node *prev = NULL;
			while(temp != NULL && temp->info != info) {
				prev = temp;
				temp = temp->next;
			} 
			if(prev == NULL) {
				start = start->next;
				delete temp;
				size-=1;
				return;
			}
			if(temp == NULL) {
				return;
			}
			prev->next = temp->next;
			delete temp;
			size-=1;
			return;
		}
		friend std::ostream& operator<<(std::ostream &,SortedLL *);
};

std::ostream& operator<<(std::ostream &dout,SortedLL *p) {
	SortedLL::node *temp;
	temp = p->start;
	if(temp == NULL) {
		return dout<<"[]"<<std::endl;
	}
	dout<<"[";
	while(temp != NULL) {
		dout<<temp->info<<" ";
		temp = temp->next;
	}
	dout<<"]"<<std::endl;
	return dout;
}
main() {
	SortedLL *l = new SortedLL();
	l->insert(4);
	l->insert(6);
	l->insert(2);
	l->insert(7);
	l->insert(5);
	l->insert(1);
	l->insert(3);
	l->insert(14);
	l->insert(22);
	std::cout<<l;
	l->remove(14);
	l->remove(1);
	l->remove(4);
	l->remove(22);
	std::cout<<l;
}
