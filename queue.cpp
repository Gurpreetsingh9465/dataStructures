#include "iostream"

class Queue
{
	private: int capacity,front,rear,len; int *array;
	public:
		Queue(int capacity) { this->capacity = capacity;
			array = new int[capacity]; front = -1; rear = -1;
			len = 0; }
		bool isFull() { return len == capacity; }
		bool isEmpty() { return front == -1; }
		void insert(int val) {
			if(len == capacity) { throw "queue is full"; }
			if(front == -1) { front+=1; rear+=1; array[front] = val;
				len+=1;
			} else {
				if(rear == capacity -1) { rear = 0; array[rear] = val;
				} else { rear+=1; array[rear] = val; } len += 1; } }
		int pop() {
			if(rear == -1) { throw "underflow"; } int val;
			if(front == rear) { val = array[front]; front = -1;
				rear = -1; return val;
			} else { if(front == capacity -1) {
					val = array[capacity-1]; front=0;
				} else { val = array[front]; front += 1; } }
			len-=1; return val; }
		int getRear() { if(rear== -1) { throw "underflow"; }
			return array[rear]; }
		int getFront() { if(front == -1) { throw "underflow"; }
			return array[front]; } 
		int getLen() { return len; }
	friend std::ostream& operator<<(std::ostream &,Queue *);
};
std::ostream& operator<<(std::ostream &out,Queue *p) {
	if(p->isEmpty()) { return out<<"[]"<<std::endl;
	} else { if(p->front == p->rear) return out<<"["<<p->array[p->rear]<<"]"<<std::endl;
		out<<"[";
		if(p->front < p->rear) {
			for(int i=p->front;i<=p->rear;i++) { out<<p->array[i]<<","; }
		} else {
			for(int i=p->front;i<p->capacity;i++) {
			 	out<<p->array[i]<<","; }
			for(int i=0;i<=p->rear;i++) { out<<p->array[i]<<",";
			} } out<<"]"<<std::endl; return out; }
}
main()
{
	Queue *p = new Queue(5);
	std::cout<<p;
	p->insert(5);
	std::cout<<p;
	p->insert(45);
	std::cout<<p;
	p->insert(457);
	std::cout<<p;
	p->insert(9);
	std::cout<<p;
	std::cout<<p->pop()<<std::endl;
	std::cout<<p;
	p->insert(10);
	std::cout<<p;
	p->insert(5);
	std::cout<<p;
	std::cout<<p->pop()<<std::endl;
	std::cout<<p;
	std::cout<<p->pop()<<std::endl;
	std::cout<<p;
	std::cout<<p->pop()<<std::endl;
	std::cout<<p;
	std::cout<<p->pop()<<std::endl;
	std::cout<<p;
	p->insert(78);
	std::cout<<p;
}
