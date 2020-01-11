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
int parent[n + 1];

void showPath(){
	int v = endd;
	while(v != start){
		cout<<v<<" ";
		v = parent[v];
	}
	cout<<start<<endl;
}

void DFS(int u){	
	for(int v = 1; v <= n; v++){
		if(visited[v] == false && G[u][v] == 1){
			visited[v] = true;
			parent[v] = u;
			if(v == endd){
				// In ra duong di
				showPath();
			}
			else			
				DFS(v);
			visited[v] = false;
		}
	}
}

int main(){
	for(int i = 1; i <= n; i++){
		parent[i] = -1;
		for(int j = 1; j <= n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}	
	visited[start] = true;
	DFS(start);
	return 0;
}
