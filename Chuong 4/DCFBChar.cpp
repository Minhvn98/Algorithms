#include <iostream>

using namespace std;

int len(int n){
	if(n == 1 || n == 2)return 1;
	else return len(n - 2) + len(n - 1);
}

char DC(int i, int n){
	if(n == 1) return 'A';
	else if(n == 2) return 'B';
	else{
		if(i <= len(n - 2)){
			return DC(i, n - 2);
		}
		else{
			return DC(i - len(n-2), n - 1);
		}
	}
}

int main(){
	int n = 7;
	int i = 1;
	cout<<"Nhap i: ";cin>>i;
	cout<<"Nhap n: ";cin>>n;
	cout<<DC(i, n);
	return 0;
}
