#include <iostream>

using namespace std;
const int n = 5;
const int start = 3;
const int endd = 4;
int G[n + 1][n + 1] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 1},
	{0, 1, 0, 1, 0, 1},
	{0, 0, 1, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 1, 1, 0, 0, 0}
};

bool visited[n + 1] = {0};
int path[n], nb = 0;

void DFS(int u){	
	for(int v = 1; v <= n; v++){
		if(visited[v] == false && G[u][v] == 1){
			visited[v] = true;
			path[++nb] = v;
			if(v == endd){
				// In ra duong di
				for(int i = 0; i <= nb; i++) cout<<path[i]<<" ";cout<<endl;
			}
			else			
				DFS(v);
			nb--;
			visited[v] = false;
		}
	}
}

int main(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}	
	path[0] = start;
	visited[start] = true;
	DFS(start);
	return 0;
}
