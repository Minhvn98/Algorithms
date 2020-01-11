#include<iostream>
using namespace std;
const int n = 4;
const int m = 5;
const int max_nb = 10000;
int a[n+2][m]= {
	{max_nb , max_nb , max_nb , max_nb , max_nb},
	{4 , 1 , 4 , 6 , 5},
	{6 , 2 , 1 , 5 , 1},
	{1 , 5 , 4 , 4 , 3},
	{2 , 4 , 5 , 3 , 4},
	{max_nb , max_nb , max_nb , max_nb , max_nb}
};
int S[n+2][m];
void dp() {
	// gan gia tri cho cot 0 cua S bang cot 0 cua a
	for(int i = 1 ; i <= n ; i++) {
		S[i][0] = a[i][0];
	}
	// tinh toan va dien cac gia tri cho cac cot 1 -> cot m-1
	for(int c =  1 ; c<m ; c++) {
		for(int r = 1; r <= n; r++) {
			S[r][c] =  min(min(S[r-1][c-1],S[r][c-1]),S[r+1][c-1]) +  a[r][c];
		}
	}

//	for(int  r = 1 ; r <= n ; r++) {
//		for(int c = 0 ; c <m; c++) {
//			cout<<S[r][c]<<"\t";
//		}
//		cout<<endl;
//	}

	// truy hoi`  de tim duong di
	int row[m];
	int min_value = max_nb;
	int r0 = 0;
	for(int r = 1 ; r <= n ; r++ ){
		if(min_value > S[r][m-1]){
			min_value = S[r][m-1];
			r0 = r;
		}
	}
	row[m-1] =  r0;
	int c = m-1 , r = r0; // lui dan tu vi tri (r0,m-1) ve cot 0
	while(c > 0){
		
		r = row[c];
		// tim gia tri min trong 3  o ke  truoc voi  o (r,c)
		// (r-1,c-1) ,  (r,c-1) , (r+1,c-1)
		min_value = S[r-1][c-1];
		r0 = r-1;
		if(min_value > S[r][c-1]){
			min_value = S[r][c-1];
			r0 = r;
		}
		if(min_value > S[r+1][c-1]) r0 = r+1;
		row[--c] = r0;
	}
	cout<<" duog di ngan nhat la :";
	for(int i = 0 ; i<m;i++){
		cout<<"("<<row[i]<<","<<i+1<<") -> ";
	}
	cout<<endl;
}

int main() {
	for(int i = 0 ; i < n+2; i++) {
		for(int j = 0; j<m; j++) {
			S[i][j] =  max_nb;
		}
	}

	dp();

	return 0;
}