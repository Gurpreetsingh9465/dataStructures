#include "iostream"
#include "stdlib.h"
#include "string"
using namespace std;
void print(int *a,int n) {
	cout<<"[";
	for(int i=0;i<n-1;i++) {
		cout<<a[i]<<",";
	}
	cout<<a[n-1]; cout<<"]"; cout<<endl; }
void swap(int *a,int *b) {
	int temp;
	temp = *a; *a = *b; *b = temp;
}
int partition(int *a,int p,int q)
{
	int pivot = a[q]; int i = p-1;
	for (int j=p;j<q;j++) {
		if(a[j] <= pivot ) {
			i+=1;
			swap(&a[i],&a[j]);
		} }
	swap(&a[i+1],&a[q]); return i+1; }
void quickSORT(int *a,int p,int q)
{
	if(q > p)
	{
		int r = partition(a,p,q);
		quickSORT(a,p,r-1);
		quickSORT(a,r+1,q);
	}
}
main()
{
	int a[] = {7,6,5,4,3,2,1};
	print(a,7);
	quickSORT(a,0,6);
	print(a,7);
}
