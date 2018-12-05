#include<iostream>
int pass = 0;

int bs(int a[],int search, int start, int end) {
	int mid = (start + end)/2;
	pass+=1;
	if(a[mid] == search) 
		return mid;
	if(a[mid] > search)
		return bs(a,search,start,mid-1);
	else
		return bs(a,search,mid+1,end);
}

int bsi(int a[],int search, int start, int end) {
	int mid = (start + end)/2;
	while(a[mid] != search) {
		pass+=1;
		if(a[mid] > search) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
		mid = (start + end)/2;
	}
	return mid;
}

main() {
	int a[] = {1,2,3,4,5,6,8,9,45,56};
	std::cout<<bsi(a,3,0,10)<<std::endl;
	std::cout<<pass;	 
}


