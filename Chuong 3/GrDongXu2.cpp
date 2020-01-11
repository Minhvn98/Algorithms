#include <iostream>

using namespace std;

void in(int S[], int n, int c[]){
	for(int i = 0; i < n; i++){
		if(S[i] != 0)
			cout<<S[i]<<" Dong xu loai "<<c[i]<<endl;
	}
}

void Gr(int x, int c[], int S[], int n){
	while(x > 0){
		int k = n - 1;
		while(k >= 0){
			if(c[k] <= x)break;
			k--;
		}
		if(k == -1){
			S[0] = -1; // Case False
			break;
		}
		else{			
			S[k] = x / c[k];
			x -=  S[k] * c[k];
		}
	}
}

int main(){
	int n = 5;
	int c[n] = {1, 5, 10, 25, 100};
	int S[n] = {0, 0, 0, 0, 0};
	int x = 61;
	//cin>>x;	
	Gr(x, c, S, n);	
	if(S[0] == -1){
		cout<<"no solution";		
	}
	else{
		in(S, n, c);	
	}	
	return 0;
}
