#include <iostream>

using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n - 1; i++)cout<<a[i]<<" + ";cout<<a[n - 1];
}

bool kt = false;
void BTKPhan(int a[], int arrCP[], int k, int t, int i, int sum[], int n){
	for(int j = 1; j <= t; j++){	
		//if(kt)break;			
		//if(sum[i - 1] + arrCP[j - 1] > n)break;
		
		a[i] = arrCP[j - 1];		
		sum[i] = sum[i - 1] + a[i];
		if(i == k - 1){
			if(sum[i] == n){
				in(a, k);
				cout<<" = "<<sum[i]<<endl;
				kt = true;
			}
		}
		else
			BTKPhan(a, arrCP, k, t, i + 1, sum, n);
	}
}

int main(){
	int n = 125;
	//cout<<"Nhap n: ";cin>>n;
	int arrCP[n];
	int t = 0;
	while(true){
		int scp = (t + 1) * (t + 1);
		if(scp > n)break;
		else{
			arrCP[t] = scp;			
			t++;			
		}
	}
	cout<<"Mang SCP: ";
	for(int i = 0; i < t; i++)cout<<arrCP[i]<<" ";
	cout<<endl;
	
	for(int k = 1; k <= n; k++){
		//if(kt)break;
		int a[k];
		int sum[k];
		sum[0] = 0;
		BTKPhan(a, arrCP, k, t, 0, sum, n);		
	}
	if(!kt)cout<<"no solution";
	return 0;
}
