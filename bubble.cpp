#include "stdlib.h"
#include "iostream"
void swap(int *a,int *b) {
	int temp; temp = *a; *a = *b; *b = temp;
}
void print(int *A,int n)
{
	std::cout<<"[";
	for(int i = 0;i<n;i++)
	{
		if (i == n - 1)
		{
			std::cout<<A[i]; break;
		}
		std::cout<<A[i]<<" ,";
	}
	std::cout<<"]"<<std::endl;
}
void bubbleSORT(int *A,int n)
{
	for(int i = 0 ; i < n-1; i++ )
	{
		for(int j = 0 ;j < n-i-1 ;j++)
		{
			if(A[j+1] < A[j])
			{
				swap(&A[j+1],&A[j]);
			}
		}
	}
}
main()
{
	int a[10] = {3,5,2,4,7,10,1,56,4,2};
	bubbleSORT(a,10);
	print(a,10);
}
