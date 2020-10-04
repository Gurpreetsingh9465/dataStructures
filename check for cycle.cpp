#include<iostream>
#include<list>
class Node {
	public:
		char name;
		Node *next;
		int weight;
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
		bool in(std::list<char> mylist,char n) {
			if(!mylist.empty()) {
				for (std::list<char>::iterator it=mylist.begin(); it != mylist.end(); ++it)
	    			if(*it == n) 
	    				return true;
			}
			return false;
		}
		bool isCycle() {
			std::list<char> s;
			std::list<char> visited;
			s.push_back(array[0]->name);
			while (!s.empty()) {
				char u = s.back();
				Node *temp =  array[getIndex(s.back())]->next;
				s.pop_back();
				while(temp!= NULL) {
					if(in(visited,temp->name))
						return true;
					s.push_back(temp->name);
					temp= temp->next;
				}
				visited.push_back(u);
			}
			return false;
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
	g->addEdge('A','B',1);
	g->addEdge('A','C',1);
	g->addEdge('B','D',1);
	g->addEdge('C','E',1);
	std::cout<<g;
	std::cout<<g->isCycle();
}
