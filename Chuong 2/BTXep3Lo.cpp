#include <iostream>

using namespace std;

void in(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
}

void BT(int rs[], int n, int i, int w[], int b[], int W, bool c[], int tw[], int tb[], int &best, int save[], int & count){
	for(int v = 0; v < n; v++){
		if(!c[v]){
			rs[i] = w[v];
			tw[i] = tw[i - 1] + w[v];
			tb[i] = tb[i - 1] + b[v];
			c[v] = true;
			
			if(i == n - 1 || tw[i] > W){
				cout<<"rs: ";
				in(rs, i);
				cout<<endl;
				cout<<"tw: ";
				in(tw, i);
				cout<<endl;
				cout<<"tb: ";
				in(tb, i);
				cout<<endl;
				cout<<endl;
				
				if(best < tb[i - 1]){
					best = tb[i - 1];
					count = i;
					for(int j = 0; j < i; j++)
						save[j] = rs[j];
				}
			}				
			else{
				BT(rs, n, i+1, w, b, W, c, tw, tb, best, save, count);		
			}
			c[v] = false;
		}
	}
}

int main(){
	int n = 5;
	int w[n] = {2, 5, 3, 9, 4};
	int b[n] = {8, 10, 6, 2, 3};
	bool c[n] = {0, 0, 0, 0, 0};	
	int rs[n];
	int tw[n];
	tw[0] = 0;
	int tb[n];
	tb[0] = 0;
	int best = w[0];
	int save[n];
	int count;
	
	int W = 12;
	//cin>>W;
	
	BT(rs, n, 0, w, b, W, c, tw, tb, best, save, count);
	cout<<"Tong :";
	in(save, count);
	cout<<"= "<<best;
			
	return 0;
}
