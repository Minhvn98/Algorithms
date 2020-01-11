#include <iostream>
#include <stack>
 
using namespace std;
const int n = 6;
int G[n + 1][n + 1] = {
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0},
	{0, 1, 0, 1, 1, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 0, 0}
};

void euler(){	
	// Kiem tra euler
	int deg[n + 1] = {0};
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(G[i][j] > 0){
				deg[i]++;	
				deg[j]++;
			}
	bool isEuler = true;
	for(int u = 1; u <= n; u++)
		if(deg[u] % 2 == 1){
			isEuler = false;
			break;
		}		
	if(!isEuler){
		cout<<"Khong phai do thi Euler";
		return;
	}
	else{
		stack<int> S;
		stack<int> CE;
		int u = 1;
		S.push(u);
		int x;
		while(!S.empty()){
			x = S.top();
			
			bool isFind = false;
			// Tim 1 dinh y ke vs x
			for(int y = 1; y <= n; y++){
				if(G[x][y] > 0){
					G[x][y] = 0;
					G[y][x] = 0;
					S.push(y);
					isFind = true;
					break;
				}
			}			
			
			if(!isFind){
				S.pop();
				CE.push(x);
			}
		}
		
		int v;
		while(!CE.empty()){
			v = CE.top();
			CE.pop();
			cout<<v<<" ";
		}
		cout<<endl;
	}
}

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	euler();
	return 0;
}
