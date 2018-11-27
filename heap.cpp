#include <iostream>

class Heap
{
	public:
		void swap(int *a,int *b) {
			int temp;
			temp = *b;
			*b = *a;
			*a = temp;
		}
		void heapify(int *A,int i,int n) {
			int l = 2*i + 1;
			int r = 2*i + 2;
			int lar = i;
			if(l < n && A[l] > A[lar] ) {
				lar = l;
			}
			if( r<n && A[r] > A[lar]) {
				lar = r;
			}
			if(lar != i) {
				swap(&A[i],&A[lar]);
				heapify(A,lar,n);
			}
		}
		void print(int *A,int n) {
			for(int i =0;i<n;i++) {
				std::cout<<A[i]<<" ";
			}
			std::cout<<std::endl;
		}
		void heapSort(int A[],int n) {
			for(int i = n/2 -1;i>0;i--) {
				heapify(A,i,n);
			}
			for(int i = n-1;i>0;i--) {
				swap(&A[0],&A[i]);
				heapify(A,0,i);
			}
		}
};

main() {
	int a[] = {7,5,6,2,9,4,3};
	Heap h;
	h.print(a,7);
	h.heapSort(a,7);
	h.print(a,7);
	
}
