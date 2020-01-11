#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void random(int a[], int n){
	srand(time(NULL));
	for(int i = 1; i <= n; i++)
		a[i] = rand() % 100 + 1;
}

void in(int a[], int n){
	for(int i = 1; i <= n; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int partition(int a[], int L, int R, int indexPivot){
	int pivot = a[indexPivot];
	swap(a[indexPivot], a[R]);
	int storeIndex = L;
	for(int i = L; i <= R - 1; i++){
		if(a[i] < pivot){
			swap(a[storeIndex], a[i]);
			storeIndex++;
		}
	}
	swap(a[storeIndex], a[R]);
	return storeIndex;
}

void quick_sort(int a[], int L, int R){
	if(L < R){
		int index = (L + R) / 2;
		index = partition(a, L, R, index);
		if(L < index)
			quick_sort(a, L, index - 1);
		if(R > index)
			quick_sort(a, index + 1, R);
	}
}

bool DCBNS(int a[], int L, int R, int x){
	if(L > R)return false;
	else{
		int M = (L + R) / 2;
		if(a[M] == x)return true;
		else if(x < a[M]){
			return DCBNS(a, L, M - 1, x);
		}
		else if(a[M] < x){
			return DCBNS(a, M + 1, R, x);
		}
	}
}

main(){
	int n = 20;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	quick_sort(a, 1, n);	
	cout<<"output: ";
	in(a, n);
	int x = 25;
	cout<<x<<" : "<<DCBNS(a, 1, n, x);
	return 0;
}

#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x){
	if(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == x)
			return mid;
		else if(x < arr[mid])
			return binarySearch(arr, left, mid-1, x);
		else
			return binarySearch(arr, mid+1, right, x);
	}
	return -1;

}

//su dung vong lap 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
} 

int main(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 9};
	cout << binarySearch(arr, 0, 8, 13);
}