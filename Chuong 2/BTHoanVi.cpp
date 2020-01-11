#include <iostream>
using namespace std;

int count = 0;

void in(int a[], int n){
	for(int i = 1; i <= n; i++)cout<<a[i];cout<<" | ";
}

void BTHoanVi(int a[], bool c[], int n, int k, int i){
	for(int v = 1; v <= k; v++){
		if(!c[v]){
			a[i] = v;
			c[v] = true;
			if(i == n){
				in(a, n);
				count++;
			}				
			else
				BTHoanVi(a, c, n, k, i+1);		
			c[v] = false;
		}
	}
}

int main(){
	int n = 3;
	//cin>>n;
	int k = 5;
	//cin>>k;
	int a[n + 1];	
	bool c[n + 1];
	for(int i = 1; i <= n; i++)c[i] = false;
	BTHoanVi(a, c, n, k, 1);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
