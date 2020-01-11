#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

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

// Insertion Sort
void insertion_sort(int a[], int n){
	for(int k = 2; k <= n; k++){
		int last = a[k];
		int j = k;
		while(j > 1 && a[j - 1] > last){
			a[j] = a[j - 1];
			j--;
		}
		a[j] = last;
		cout<<"        ";
		in(a, n);
	}
}

// Selection Sort
void selection_sort(int a[], int n){
	for(int k = 1; k <= n; k++){
		int min = k;
		for(int i = k+1; i <= n; i++){
			if(a[min] > a[i]){
				min = i;
			}
		}
		swap(a[k], a[min]);
		cout<<"        ";
		in(a, n);
	}
}

// Bubble Sort
void bubble_sort(int a[], int n){
//	for(int i = 1; i <= n-2; i++){
//		for(int j = 1; j <= n-i-1; j++){
//			if(a[j] > a[j+1]){
//				swap(a[j], a[j+1]);
//			}
//		}		
//	}
	bool isSwap = false;
	do{
		isSwap = false;
		for(int i = 1; i < n; i++){
			if(a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				isSwap = true;
			}
		}
	}while(isSwap);
}

// Merge Sort
void merge(int a[], int L, int M, int R, int n){
	int TA[n + 1];
	int i = L;
	int j = M+1;
	for(int k = L; k <= R; k++){
		if(i > M){
			TA[k] = a[j];
			j++;
		}
		else if(j > R){
			TA[k] = a[i];
			i++;
		}
		else{
			if(a[i] < a[j]){
				TA[k] = a[i];
				i++;
			}
			else{
				TA[k] = a[j];
				j++;
			}
		}
	}
	for(int k = L; k <= R; k++){
		a[k] = TA[k];
	}
}

void merge_sort(int a[], int L, int R, int n){
	if(L < R){
		int M = (L + R) / 2;
		merge_sort(a, L, M, n);
		merge_sort(a, M + 1, R, n);
		merge(a, L, M, R, n);
	}
}

// Quick Sort
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

// Heap Sort
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

// Comb Sort
void comb_sort(int a[], int n){
	int gap = n;
	float shrink = 1.3;
	bool sorted = false;
	while((gap > 1) || (sorted == false)){
		gap = floor(gap / shrink);
		if(gap < 1) gap = 1;		
		if(gap == 1)sorted = true;
		int i = 1;
		while(i + gap <= n){
			if(a[i] > a[i + gap]){
				swap(a[i], a[i + gap]);
				if(gap == 1)sorted = false;
			}
			i++;
		}
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
		
	//insertion_sort(a, n);		
	//selection_sort(a, n);
	bubble_sort(a, n);
	//merge_sort(a, 1, n, n);
	//quick_sort(a, 1, n);
	//heap_sort(a, n);
	//comb_sort(a, n);
	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
