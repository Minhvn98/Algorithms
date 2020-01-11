#include <iostream>

using namespace std;
const int n = 100;
int c[n][n] = {0};

void DP(string X, string Y){
	//C[i, j]: do dai max cua X1 -> Xi va Y1 -> Yj
	for(int i = 1; i <= X.size(); i++){
		for(int j = 1; j <= Y.size(); j++){
			if(X[i - 1] == Y[j - 1]){
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else{
				c[i][j] = (c[i - 1][j] > c[i][j - 1]) ? c[i - 1][j] : c[i][j - 1];
			}
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	//Truy hoi
	int row = X.size(), col = Y.size();
	char seq[n];
	int nb = 0;
	while(c[row][col] != 0){
		if(X[row - 1] == Y[col - 1]){
			seq[nb++] = X[row - 1];
			row--;
			col--;
		}
		else{
			if(c[row][col] == c[row - 1][col])row--;
			else col--;
		}
	}
	for(int i = nb - 1; i >= 0; i--)cout<<seq[i];
}

int main(){
	string X = "abcfd";
	string Y = "abcd";
	DP(X, Y);
	return 0;
}
