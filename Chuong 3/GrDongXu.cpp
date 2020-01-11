#include <iostream>
#include <vector>

using namespace std;

void in(vector<int> S){
	for(int i = 0; i < S.size(); i++)cout<<S[i]<<" ";
}

vector<int> Gr(int x, int c[], int n){
	vector<int> S;	
	while(x > 0){
		int k = n - 1;
		while(k >= 0){
			if(c[k] <= x)break;
			k--;
		}
		if(k == -1){
			S.clear();
			break;
		}
		else{
			int s = x / c[k];
			x -=  s * c[k];			
			for(int i = 0; i < s; i++)
				S.push_back(c[k]);
		}		
	}	
	return S;
}

int main(){
	int n = 5;
	int c[n] = {1, 5, 10, 25, 100};
	vector<int> S;
	int x = 56;
	cin>>x;
	S = Gr(x, c, n);
	if(S.size() != 0){
		in(S);
		cout<<endl;
	}
	else{
		cout<<"no solution";
	}
	return 0;
}
