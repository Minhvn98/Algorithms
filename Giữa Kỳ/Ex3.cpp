#include <iostream>
using namespace std;

int count = 0;
int rs = 0;

void in(int a[], int k){
	for(int i = 1; i < k; i++)cout<<a[i]<<" + ";cout<<a[k];
}

int f = 0;
void BTToHop(int a[], int n, int k, int i){
	for(int j = a[i-1] + 1; j <= n - (k-i); j++){
		a[i] = j;
		f += j;
		if(i == k){
			count++;
			if(f % k == 0){
				in(a, k);
				cout<<" = "<<f<<endl;
				rs++;
			}
		}			
		else{
			BTToHop(a, n, k, i+1);
		}
		f -= j;
	}
}

int main(){
	int n = 20;
	int k = 5;
	cout<<"Nhap n: ";cin>>n;
	cout<<"Nhap k: ";cin>>k;
	int a[k + 1];
	a[0] = 0;
	BTToHop(a, n, k, 1);
	cout<<"Truy van: "<<rs<<" / "<<count;
	return 0;
}
