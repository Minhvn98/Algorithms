#include <iostream>
using namespace std;

int count = 0;

void in(int a[], int n){
	for(int i = 1; i <= n; i++)cout<<a[i];cout<<endl;
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

void BTKPhan(int a[], int n, int i){
	for(int j = 1; j <= n; j++){
		a[i] = j;
		if(i == n){
			in(a, n);
			count++;
		}
		else BTKPhan(a, n, i + 1);
	}
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

void BTHoanVi(int a[], bool c[], int n, int i){
	for(int v = 1; v <= n; v++){
		if(!c[v]){
			a[i] = v;
			c[v] = true;
			if(i == n){
				in(a, n);
				count++;
			}				
			else
				BTHoanVi(a, c, n, i+1);		
			c[v] = false;
		}
	}
}

int main(){
	int n = 5;
	int k = 3;
	//cin>>n;
	//cin>>k;
	int a[n + 1];
	//BTNhiPhan(a, n, 1);
	//BTKPhan(a, n, 1);
	
//	a[k + 1];
//	a[0] = 0;
//	BTToHop(a, n, k, 1);
	
	bool c[n + 1];
	for(int i = 1; i <= n; i++)c[i] = false;
	BTHoanVi(a, c, n, 1);
	
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
