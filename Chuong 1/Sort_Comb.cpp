#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

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

void comb_sort(int a[], int n){
	int gap = n;
	float shrink = 1.3;
	bool sorted = false;
	while((gap > 1) || (sorted == false)){
		gap = floor(gap / shrink);
		if(gap < 1) gap = 1;		
		if(gap == 1)sorted = true;
		int i = 1;
		while(i + gap <= n){
			if(a[i] > a[i + gap]){
				swap(a[i], a[i + gap]);
				if(gap == 1)sorted = false;
			}
			i++;
		}
	}
}

int main(){
	int n = 200;
//	cin>>n;
	int a[n+1];
//	for(int i = 1; i <= n; i++)
//		cin>>n;
	random(a, n);
	cout<<"input:  ";
	in(a, n);
	comb_sort(a, n);	
	cout<<"output: ";
	in(a, n);
	return 0;	
}
