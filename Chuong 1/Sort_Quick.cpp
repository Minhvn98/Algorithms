#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void random(int a[], int n){
	srand(time(NULL));
	for(int i = 1; i <= n; i++)
		a[i] = rand() % 1000 + 1;
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

int main(){
	int n = 100;
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
	return 0;	
}
