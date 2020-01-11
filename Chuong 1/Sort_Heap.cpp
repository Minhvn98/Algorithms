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

void heapify(int a[], int i, int n){
	int L = 2 * i;
	int R = 2 * i + 1;
	int max = i;
	if(L <= n && a[L] > a[i]){
		max = L;
	}	
	if(R <= n && a[R] > a[max]){
		max = R;
	}
	if(max != i){
		swap(a[i], a[max]);
		heapify(a, max, n);
	}
}

void buildHeap(int a[], int n){
	for(int i = n / 2; i >= 1; i--){
		heapify(a, i, n);
	}
}

void heap_sort(int a[], int n){
	buildHeap(a, n);
	for(int i = n; i > 1; i--){
		swap(a[1], a[i]);
		heapify(a, 1, i - 1);
	}
}

int main(){
	int n = 10;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	heap_sort(a, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
