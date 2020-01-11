#include <iostream>
#include <math.h>

using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n - 1; i++)cout<<a[i]<<" + ";cout<<a[n - 1];
}

bool isSNT(int soA)
{
	if (soA < 2)
	{
		return false;
	}
	else if (soA>2)
	{
		if (soA % 2 == 0)
		{
			return false;
		}
		for (int i = 3; i < sqrt((float)soA); i += 2)
		{
			if (soA%i == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool kt = false;
void TRY(int a[], int arrSNT[], int k, int t, int i, int sum[], int n){
	for(int j = 1; j <= t; j++){	
		if(kt)break;			
		if(sum[i - 1] + arrSNT[j - 1] > n)break;
		
		a[i] = arrSNT[j - 1];		
		sum[i] = sum[i - 1] + a[i];
		if(i == k - 1){
			if(sum[i] == n){
				in(a, k);
				cout<<" = "<<sum[i]<<endl;
				kt = true;
			}
		}
		else
			TRY(a, arrSNT, k, t, i + 1, sum, n);
	}
}

int main(){
	int n = 10;
	cout<<"Nhap n: ";cin>>n;
	
	if(isSNT(n)){
		cout<<n<<" = "<<n;
		return 0;
	}
	
	int arrSNT[n];
	int t = 0;
	for(int i = 2; i < n; i++){
		if(isSNT(i)){
			arrSNT[t] = i;
			t++;
		}
	}	
	cout<<"Array SNT: ";
	for(int i = 0; i < t; i++)cout<<arrSNT[i]<<" ";
	cout<<endl;	
	
	for(int k = 2; k <= n; k++){		
		if(kt)break;			
		int a[k];
		int sum[k];
		sum[0] = 0;
		TRY(a, arrSNT, k, t, 0, sum, n);		
	}
	if(!kt)cout<<"no solution";
	return 0;
}
