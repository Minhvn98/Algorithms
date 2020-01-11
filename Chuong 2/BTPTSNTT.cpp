#include <iostream>
using namespace std;

int count = 0;

void in(int a[], int n){
	for(int i = 1; i < n; i++)cout<<a[i] << " + ";cout<<a[n]<<"\n";
}

int f = 0;
void BTPTSNTT(int a[], int n, int M, int i){
	int Mt, Md;
	if(i == n){
		Mt = M - f;
		Md = M - f;
	}
	else{
		Mt = M - f - (n - i);
		Md = 1;
	}
	for(int v = Md; v <= Mt; v++){
		a[i] = v;
		cout<<v<<" ";
		f += v;
		if(i == n){
			in(a, n);
			count++;
		}
		else BTPTSNTT(a, n, M, i + 1);
		f -= v;
	}
}

int main(){
	int n = 3;
	int M = 6;
	//cin>>n;
	//cin>>M;
	int a[n + 1];
	BTPTSNTT(a, n, M, 1);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
