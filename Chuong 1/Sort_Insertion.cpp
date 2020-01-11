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

int main(){
	int n = 10;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	insertion_sort(a, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
