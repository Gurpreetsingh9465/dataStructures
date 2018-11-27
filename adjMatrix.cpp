#include<iostream>
#define INF 30000
class ADJmat {
	private:
		int V;
		int E;
		int *adj;
	public:
		ADJmat(int V) {
			this->V = V;
			this->E = 0;
			adj = new int[V*V];
			this->infinity();
		}
		void zeroes() {
			for(int i = 0 ; i< V*V;i++) {
				adj[i] = 0;
			}
		}
		void infinity() {
			for(int i = 0 ; i< V*V;i++) {
				adj[i] = INF;
			}
		}
		void insert(int i,int j, int x) {
			if(i>=0 && i<V && j>=0 && j <= V ) {
				adj[i*V+j] = x;
				E+=1;
			}
		}
		friend std::ostream & operator << (std::ostream &,ADJmat *);
};
std::ostream & operator << (std::ostream &out,ADJmat *a) {
	for(int i = 0;i<a->V*a->V;i++) {
		if(a->adj[i] == INF) {
			out<<"INF"<<" ";
		} else {
			out<<a->adj[i]<<" ";
		}
		if( (i+1)%(a->V) == 0) {
			out<<std::endl;
		}
	}
	return out;
}
main() {
	ADJmat *a = new ADJmat(3);
	a->zeroes();
	a->insert(0,1,45);
	a->insert(0,2,4);
	a->insert(1,2,10);
	a->insert(2,1,10);
	std::cout<<a;
}
