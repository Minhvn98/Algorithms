#include<iostream>
using namespace std;

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = n - 1; j > i; j--){
			if(arr[j] < arr[j-1]){
				Swap(&arr[j], &arr[j-1]);
			}
		}
	}

} 

void BubbleSortOptimize (int A[], int n) {
	for (int i = n-1; i > 0; i--) {
		bool check = true;
		for (int k = 0; k < i; k++) {
			if (A[k] > A[k+1]) {
				Swap(&A[k], &A[k+1]);
				check = false;
			}
		}
		if (check) {
			break;
		}
	}
}
void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "  ";
	}
}

main(){	
	int arr[] = {9, 0, 4, 7, 6, 1, 5, 3, 2};
	int n = sizeof(arr)/sizeof(int);
	// BubbleSort(arr, n);
	// cout << "Array sau khi sắp xếp :  " << endl;
	// printArray
	BubbleSortOptimize(arr, n);
	cout << "\nArray sau khi sắp xếp :  " << endl;
	printArray(arr, n);

}