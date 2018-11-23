#include<iostream>
using namespace std;
void merge(int A[], int n1, int index1, int B[], int n2, int index2, int C[], int index){
	
	while(n1 && n2){
		if(A[index1]<B[index2]){
			C[index] = A[index1];
			Index++; index1++; n1--; }
		else{
			C[index] = B[index2];
			Index++; index2++; n2--;
		}
	}
	while(n1){
		C[index] = A[index1];
		index++;
		index1++;
		N1--; };
	while(n2){
		C[index] = B[index2];
		index++;
		index2++;
		N2--; }
};

void mergepass(int A[], int N, int L, int B[]){
	int j, LB;
	int Q,S,R;
	Q = N/2*L;
	S= Q*2*L;
	R=N-S;
	for(j=0; j<Q; j++){
		LB = (2*j)*L;
		merge(A,L,LB, A,L,LB+L, B, LB);}
	if(R<=L){ for(j=0;j<R;j++)
		B[S+j]= A[S+j]; }
	Else{ merge(A,L,S, A, R-L, S+L, B, S); }	
}
void merge_sort(int A[], int N){
	int L=1, B[8];
	while(L<N){
		mergepass(A,N,L,B);
		mergepass(B,N,2*L, A);
		L = L*4;	} }
main(){
	int a[] = {12,1,435,2345,76,11,0,12};
	for(int i=0; i<8; i++){	cout<<a[i]<<" ";}
	merge_sort(a, 8);
	for(int i=0; i<8; i++){
		cout<<a[i]<<" ";
	}

