#include<iostream>
#include<stdlib.h>
#define INF 30000

class Node {
	public:
		char name;
		Node *next;
		int weight;
	Node() { }
	Node(char name, int weight = 0) {
		this->name = name;
		this->weight = weight;
		next = NULL;
	}
};

class Graph {
	private:
		Node **array;
		int v;
		char *names;
		int edges;
		int getIndex(char c) {
			for(int i = 0;i<v;i++) {
				if(names[i] == c) 
					return i;
			}
			return -1;
		}
	public:
		Graph(char *A,int v) {
			this->v = v;
			names = new char[v];
			*array = new Node[v];
			for(int i = 0;i<v;i++) {
				array[i] = new Node(A[i]);
				names[i] = A[i];
			}
		}
		bool checkIn(char c) {
			for(int i = 0;i<v;i++) {
				if(names[i] == c) 
					return true;
			}
			return false;
		}
		void addEdge(char start,char end,int weight) {
			if(checkIn(start) && checkIn(end)) {
				Node *temp = array[getIndex(start)];
				if(temp->next == NULL) 
					temp->next = new Node(end,weight);
				else {
					while(temp->next!=NULL)
						temp = temp->next;
					temp->next = new Node(end,weight);
				}
				
			}
		}
		friend std::ostream & operator << (std::ostream &,Graph*);
};
std::ostream & operator << (std::ostream &out,Graph *a) {
	for(int i = 0;i<a->v;i++) {
		out<<a->array[i]->name<<" => ";
	    Node *temp = a->array[i]->next;
	    while(temp != NULL) {
	    	out<<"("<<temp->name<<" ,"<<temp->weight<<")"<<" => ";
	    	temp = temp->next;
		}
		out<<std::endl;
	}
	return out;
}
main() {
	char a[] = {'A','B','C','D','E'};
	Graph *g = new Graph(a,5);
	g->addEdge('A','B',45);
	g->addEdge('D','E',72);
	g->addEdge('A','C',4);
	g->addEdge('A','D',5);
	std::cout<<g;
}
