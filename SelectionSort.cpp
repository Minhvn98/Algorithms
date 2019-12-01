#include<iostream>
using namespace std;

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 

void selectionSort(int arr[], int n)  
{  
    int i, j, min_index;  
  
   
    for (i = 0; i < n-1; i++)  
    {  
        // Tìm phần tử nhỏ nhất trong Array
        min_index = i;  
        for (j = i+1; j < n; j++)  
	        if (arr[j] < arr[min_index])  
	            min_index = j;  
  
        // Hoán đổi vị trí của phần tử nhỏ nhất với phần tử đầu tiên của Array
        swap(&arr[min_index], &arr[i]);  
    }  
}  


void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "  ";
	}
}

main(){
	int arr[] = {9, 0, 4, 1, 5};
	int n = sizeof(arr)/sizeof(int);
	selectionSort(arr, n);
	cout << "Array sau khi sắp xếp :  " << endl;
	printArray(arr, n);

}