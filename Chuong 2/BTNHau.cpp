#include <iostream>
#include <math.h>
using namespace std;

int count = 0;

void in(int x[], int n){
	for(int i = 1; i <= n; i++)cout<<"("<<x[i]<<" , "<<i<<") ,";cout<<"  |  ";
}

bool Candidate(int x[], int v, int i){
	for(int j = 1; j <= i - 1; j++){
		if(x[j] == v || abs(x[j] - v) == abs(j - i)){
			return false;
		}
	}
	return true;
}

void BTNHau(int x[], int n, int i){
	for(int v = 1; v <= n; v++){
		if(Candidate(x, v, i)){
			x[i] = v;
			if(i == n){
				in(x, n);
				count++;
			}
			else
				BTNHau(x, n, i + 1);
		}
	}		
}

void KhoiTao(bool c[], int a, int b){
	for(int i = a; i <= b; i++)c[i] = true;
}

void BTNHauTC(int x[], int n, int i, bool r[], bool d1[], bool d2[]){
	for(int v = 1; v <= n; v++){
		if(r[v] && d1[i - v + n] && d2[i + v]){
			x[i] = v;
			r[v] = false;
			d1[i - v + n] = false;
			d2[i + v] = false;
			if(i == n){
				in(x, n);
				count++;
			}
			else
				BTNHauTC(x, n, i + 1, r, d1, d2);
			r[v] = true;
			d1[i - v + n] = true;
			d2[i + v] = true;
		}
	}		
}

int main(){
	int n = 6;
	cin>>n;
	int x[n + 1];
	bool r[n + 1];
	bool d1[2*n];
	bool d2[2*n + 1];
	KhoiTao(r, 1, n);
	KhoiTao(d1, 1, 2*n - 1);
	KhoiTao(d2, 1, 2*n);
	//BTNHau(x, n, 1);
	BTNHauTC(x, n, 1, r, d1, d2);
	cout<<"So luong cau hinh: "<<count;
	return 0;
}
