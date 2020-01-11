#include <iostream>
#include <vector>

using namespace std;

void BBsort(int w[], int b[], int n){
	bool isSwap = false;
	do{
		isSwap = false;
		for(int i = 0; i < n - 1; i++){
			if(b[i] * 1.0 / w[i] > b[i+1] * 1.0 / w[i+1]){
				swap(b[i], b[i+1]);
				swap(w[i], w[i+1]);
				isSwap = true;
			}
		}
	}while(isSwap);
}

void in(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
}

void in(vector<int> S){
	for(int i = 0; i < S.size(); i++)cout<<S[i]<<" ";
}

vector<int> Gr(int x, int n, int w[], int b[], bool c[], int &t){
	vector<int> S;
	while(x > 0){
		int k = n - 1;
		while(k >= 0){
			if(w[k] <= x && !c[k])break;
			k--;
		}
		if(k == -1){
			break;
		}
		else{
			x -= w[k];
			t += b[k];
			c[k] = true;
			S.push_back(w[k]);
		}		
	}
	return S;
}

int main(){
	int n = 5, W = 12;
	cin>>n>>W;
	int w[n] = {2, 5, 3, 9, 4};
	int b[n] = {8, 10, 6, 2, 3};
	for(int i = 0; i < n; i++)cin>>w[i];
	for(int i = 0; i < n; i++)cin>>b[i];
	
	bool c[n] = {0, 0, 0, 0, 0};
	int rs[n];

	BBsort(w, b, n);
//	in(w, n);
//	cout<<endl;
//	in(b, n);
//	cout<<endl;	

	int t = 0;
	vector<int> S;
	S = Gr(W, n, w, b, c, t);
	
	in(S);
	cout<<"= "<<t;
	return 0;
}
