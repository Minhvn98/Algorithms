#include <iostream>
using namespace std;

void in(int a[], int k){
	for(int i = 1; i <= k; i++)cout<<a[i]<<" ";
}

void BTToHop(int a[], int rs[], int n, int k, int i, int w[], int tw[], int b[], int tb[], int W, int &best, int save[], int &size){
	for(int j = a[i-1] + 1; j <= n - (k-i); j++){
		if(tw[i - 1] + w[j - 1] > W)continue;
		
		a[i] = j;
		rs[i] = w[j - 1];
		tw[i] = tw[i - 1] + w[j - 1];
		tb[i] = tb[i - 1] + b[j - 1];

		if(i == k){
			in(rs, k);
			cout<<" = "<<tw[i]<<" ==> "<<tb[i]<<endl;
			
			if(best < tb[i]){
				best = tb[i];
				for(int t = 1; t <= k; t++)save[t] = rs[t];
				size = k;
			}			
		}
		else BTToHop(a, rs, n, k, i+1, w, tw, b, tb, W, best, save, size);
	}
 }
int main(){
	int n = 5, W = 12;
	cin>>n>>W;
	int w[n] = {2, 5, 3, 9, 4};
	int b[n] = {8, 10, 6, 2, 3};
	for(int i = 0; i < n; i++)cin>>w[i];
	for(int i = 0; i < n; i++)cin>>b[i];

	int best = 0;
	int size = 0;
	int save[n];	
	for(int k = 1; k <= n; k++){
		int a[k + 1];	
		int tw[k + 1];
		int tb[k + 1];
		int rs[k + 1];
		a[0] = 0;
		tw[0] = 0;
		tb[0] = 0;		
		BTToHop(a, rs, n, k, 1, w, tw, b, tb, W, best, save, size);
	}	
	in(save, size);cout<<"= "<<best;
  return 0;
 }
