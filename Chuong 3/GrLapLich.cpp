#include <iostream>

using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
}

void BBsortF(int f[], int n, int idx[]){
	for(int i = 0; i < n-2; i++){
		for(int j = 0; j < n-i-1; j++){
			if(f[idx[j]] > f[idx[j + 1]]){
				swap(idx[j], idx[j+1]);
			}
		}		
	}
}

void GrF(int A[], int n, int s[], int f[], int idx[]){
	int nb = 0;	
	A[nb++] = idx[0];
	for(int j = 1; j < n; j++){
		if(s[idx[j]] >= f[A[nb -1]])
			A[nb++] = idx[j];
	}
	in(A, nb);
}

int main(){
	int n = 8;
	int s[n] = {0, 1, 3, 3, 4, 5, 6, 8};
	int f[n] = {6, 4, 5, 8, 7, 9, 10, 11};
	int A[n];
	
	int idx[n];
	for(int i = 0; i < n; i++)idx[i] = i;
//	in(s, n);cout<<endl;
//	in(f, n);cout<<endl;
//	in(idx, n);cout<<endl;
	
	BBsortF(f, n, idx);
	in(idx, n);cout<<endl;
	
	GrF(A, n, s, f, idx);
	return 0;
}
