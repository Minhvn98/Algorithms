/*
Input: Matran C(n x m)
YC:
Tim duong di tu cot 1 --> n sao cho chi phi nho nhat
EX 1 + 2 + 1 + 4 + 1 = 9
*/

#include <iostream>

using namespace std;
#define max 999

const int n = 4, m = 5;
int C[n][m] = {
	{4, 1, 4, 6, 5},
	{6, 2, 1, 5, 1},
	{1, 5, 4, 4, 3},
	{2, 4, 5, 3, 4}
};

void in(int S[n][m], int k){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			cout<<S[i][j]<<" ";
		}
		cout<<endl;
	}
}

int S[n][m] = {0};

void DP(int m){
	for(int i = 0; i < n; i++) S[i][0] = C[i][0];
	
	for(int j = 1; j < m; j++){
		for(int i = 0; i < n; i++){
			int a, b, c;				
			a = (i == 0) ? max: S[i - 1][j - 1];
			b = S[i][j - 1];
			c = (i == n - 1) ? max: S[i + 1][j - 1];
			int tmp = (a < b) ? a : b;
			tmp = (tmp < c) ? tmp : c;
			S[i][j] = C[i][j] + tmp;	
		}
	}
	
	in(S, m);
	
	int row[m];
	//Tim min - vach dich
	int min = S[0][m - 1];
	int idx = 0;
	for(int i = 1; i < n; i++){
		if(min > S[i][m - 1]){
			idx = i;
			min = S[i][m - 1];
		}
	}
	//cout<<idx<<" , "<<m - 1<<" = "<<C[idx][m - 1]<<" "<<endl;
	//cout<<C[idx][m - 1]<<" ";
	row[m-1] = idx;
	//Truy hoi
	for(int j = m - 1; j > 0; j--){
		int a, b, c;				
		a = (idx == 0) ? max: S[idx - 1][j - 1];
		b = S[idx][j - 1];
		c = (idx == n - 1) ? max: S[idx + 1][j - 1];
		int tmp = b;
		int r = idx;
		if(a < tmp){
			idx = r - 1;
			tmp = a;
		}
		if(c < tmp){
			idx = r + 1;
			tmp = c;
		}		
//		cout<<a<<" , "<<b<<" , "<<c<<" => "<<tmp<<" ==> ";
//		cout<<idx<<" , "<<j - 1<<" = "<<C[idx][j - 1]<<" "<<endl;
		//cout<<C[idx][j - 1]<<" ";
		row[j - 1] = idx;
	}
	
	for(int i = 0; i < m - 1; i++){
		cout<<"("<<row[i]<<" ,"<<i<<") => ";
	}
	cout<<"("<<row[m - 1]<<" ,"<<m - 1<<")";
}

int main(){
	int k = m;
	DP(k);
	return 0;	
}
