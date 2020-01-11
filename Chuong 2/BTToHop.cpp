#include <iostream>
using namespace std;

int count = 0;

void in(int a[], int k){
	for(int i = 1; i <= k; i++)cout<<a[i];cout<<" | ";
}

void BTToHop(int a[], int n, int k, int i){
	for(int j = a[i-1] + 1; j <= n - (k-i); j++){
		a[i] = j;
		if(i == k){
			in(a, k);
			count++;
		}
		else BTToHop(a, n, k, i+1);
	}
}

int main(){
	int n = 5;
	//cin>>n;
	int k = 3;
	//cin>>k;	
	int a[k + 1];
	a[0] = 0;
	BTToHop(a, n, k, 1);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
