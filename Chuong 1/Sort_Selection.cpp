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

int main(){
	int n = 10;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	selection_sort(a, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
