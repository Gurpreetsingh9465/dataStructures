#include <iostream>
using namespace std;
int main()
{
	int a[5] = {23,99,1,24,1};
	int temp,j;
	
	for(int i=1; i<=4; i++){
		temp = a[i];
		for(j=i-1; j>=0 && temp<a[j]; j--)
			a[j+1] = a[j];
		a[j+1] = temp;
	}
	
	for(int i=0; i<5; i++){
		cout<<a[i]<<endl;
	}
}

