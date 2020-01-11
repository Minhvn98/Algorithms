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

int main(){
	int n = 10;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	bubble_sort(a, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
