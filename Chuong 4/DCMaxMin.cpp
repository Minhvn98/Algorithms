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

int DCmin(int a[], int l, int r){
	if(r - l <= 1){
		return (a[l] < a[r]) ? a[l] : a[r];
	}
	else{
		int min1 = DCmin(a, l, (l + r) / 2);
		int min2 = DCmin(a, (l + r) / 2 + 1, r);
		return (min1 < min2) ? min1 : min2;
	}
}

int DCmax(int a[], int l, int r){
	if(r - l <= 1){
		return (a[l] > a[r]) ? a[l] : a[r];
	}
	else{
		int max1 = DCmax(a, l, (l + r) / 2);
		int max2 = DCmax(a, (l + r) / 2 + 1, r);
		return (max1 > max2) ? max1 : max2;
	}
}

void DCmaxmin(int a[], int l, int r, int &max, int &min){
	if(r - l <= 1){		
		max = (a[l] > a[r]) ? a[l] : a[r];
		min = (a[l] < a[r]) ? a[l] : a[r];
		return;
	}
	else{
		int max1, min1, max2, min2;
		DCmaxmin(a, l, (l + r) / 2, max1, min1);
		DCmaxmin(a, (l + r) / 2 + 1, r, max2, min2);
		max = (max1 > max2) ? max1 : max2;
		min = (min1 < min2) ? min1 : min2;
		return;
	}
}

main(){
	int n = 20;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	
	int min = DCmin(a, 1, n);
	int max = DCmax(a, 1, n);
	
	int mmin, mmax;
	DCmaxmin(a, 1, n, mmax, mmin);
	
	cout<<"output: ";
	
	cout<<" min: "<<min;
	cout<<" max: "<<max;
	
	cout<<" mmin: "<<mmin;
	cout<<" mmax: "<<mmax;
	return 0;
}
