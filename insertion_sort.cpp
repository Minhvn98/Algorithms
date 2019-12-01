#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)  
{  
    for (int i = 1; i < n; i++) 
    {  
        int key = arr[i]; // bien luu tru gia tri arr[i]
        int j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
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
	insertionSort(arr, n);
	cout << "Array sau khi sắp xếp :  " << endl;
	printArray(arr, n);

}