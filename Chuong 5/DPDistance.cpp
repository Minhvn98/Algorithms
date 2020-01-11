#include <iostream>
#include <string>

using namespace std;
const int n = 100;
int d[n][n];

string to_string(char a) { 
    string s;
    if('0' <= a && a <= '9')a + 'A';
    s += a;
    return s; 
} 

void DP(string X, string Y){
	//Khoi tao
	d[0][0] = 0;
	for(int j = 1; j < Y.size(); j++)d[0][j] = j; //TT1
	for(int i = 1; i < X.size(); i++)d[i][0] = i; //TT2
	//C[i, j]: khoang cach nho nhat X1 -> Xi va Y1 -> Yj 
	for(int i = 1; i < X.size(); i++){
		for(int j = 1; j < Y.size(); j++){
			if(X[i] == Y[j]){
				d[i][j] = d[i - 1][j - 1];
			}
			else{
				//TT1
				int min = d[i][j - 1];
				//TT2
				min = (min > d[i - 1][j]) ? d[i - 1][j] : min;
				//TT3
				min = (min > d[i - 1][j - 1]) ? d[i - 1][j - 1] : min;
				d[i][j] = min + 1;
			}
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	//Truy hoi
	int row = X.size() - 1, col = Y.size() - 1;
	string seq[n];
	int nb = 0;
	while(row >= 0 || col >= 0){
		if(X[row] == Y[col]){
			row--;
			col--;
		}
		else{			
			if(d[row][col] == d[row][col - 1] + 1){
				seq[nb++] = "Them ky tu " + to_string(Y[col]) + " vao vi tri " + to_string(row);	
				col--;
			}
			else if(d[row][col] == d[row - 1][col] + 1){
				seq[nb++] = "Xoa ky tu tai vi tri " + to_string(row);	
				row--;
			}
			else{//d[row][col] == d[row - 1][col - 1] + 1
				seq[nb++] = "Thay the ky tu tai vi tri " + to_string(row) + " bang ky tu " + to_string(Y[col]);
				row--;
				col--;
			}
		}
	}
	for(int i = nb - 1; i >= 0; i--)cout<<seq[i]<<endl;
}

int main(){
	string X = "abc";
	string Y = "be";
	DP(X, Y);
	return 0;
}
