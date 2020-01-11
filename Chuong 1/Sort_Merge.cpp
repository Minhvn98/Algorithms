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

void merge(int a[], int L, int M, int R, int n){
	int TA[n + 1];
	int i = L;
	int j = M+1;
	for(int k = L; k <= R; k++){
		if(i > M){
			TA[k] = a[j];
			j++;
		}
		else if(j > R){
			TA[k] = a[i];
			i++;
		}
		else{
			if(a[i] < a[j]){
				TA[k] = a[i];
				i++;
			}
			else{
				TA[k] = a[j];
				j++;
			}
		}
	}
	for(int k = L; k <= R; k++){
		a[k] = TA[k];
	}
}

void merge_sort(int a[], int L, int R, int n){
	if(L < R){
		int M = (L + R) / 2;
		merge_sort(a, L, M, n);
		merge_sort(a, M + 1, R, n);
		merge(a, L, M, R, n);
	}
}

int main(){
	int n = 100;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	merge_sort(a, 1, n, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
