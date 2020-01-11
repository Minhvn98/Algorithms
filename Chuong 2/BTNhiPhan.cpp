#include <iostream>
using namespace std;

int count = 0;

void in(int a[], int n){
	for(int i = 1; i <= n; i++)cout<<a[i];cout<<" | ";
}

void BTNhiPhan(int a[], int n, int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			in(a, n);
			count++;
		}
		else BTNhiPhan(a, n, i + 1);
	}
}

void BTKPhan(int a[], int n, int k, int i){
	for(int j = 1; j <= k; j++){
		a[i] = j;
		if(i == n){
			in(a, n);
			count++;			
		}
		else
			BTKPhan(a, n, k, i + 1);
	}
}

int main(){
	int n = 5;
	//cin>>n;
	int a[n + 1];
	//BTNhiPhan(a, n, 1);
	int k = 4;
	//cin>>k;
	BTKPhan(a, n, k, 1);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
