#include <iostream>
#define max 999

using namespace std;
int n, S;
int A[max + 1];

void in(int a[], int n){
	for(int i = 1; i <= n; i++){
		cout<<a[i]<<endl;	
	}
}

int sum = 0;
bool found = 0;

void Try(int a[], int i, int k){
	for(int j = a[i-1] + 1; j <= n - (k-i); j++){
		a[i] = j;
		if(sum + A[j] > S || found) break;
		sum += A[j];
		if(i == k){			
			if(sum == S){
				cout<<k<<endl;
				in(a, k);
				//cout<<" = "<<sum<<endl;	
				found = 1;
				break;
			}
		}
		else{
			Try(a, i+1, k);
		}
		sum -= A[j];
	}
}

int main(){
	freopen("tong.inp", "r", stdin);
	freopen("tong.out", "w", stdout);
	cin>>n;
	cin>>S;
	
	for(int i = 1; i <= n; i++){
		cin>>A[i];
	}
		
		
	for(int k = 1; k <= n; k++){
		if(!found){
			int a[k + 1];
			a[0] = 0;
			Try(a, 1, k);
		}
	}
	return 0;
}
