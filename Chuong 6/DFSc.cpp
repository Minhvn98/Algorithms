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

int color[n + 1] = {0}; // 0 - White / 1 - Gray / 2 - Black
int d[n + 1]; // thoi gian bat dau
int f[n + 1]; // thoi gian ket thuc
int parent[n + 1];
int time = 0;

void showPath(){
	int v = endd;
	while(v != start){
		cout<<v<<" ";
		v = parent[v];
	}
	cout<<start<<endl;
}

void DFS(int u){		
	d[u] = ++time;
	color[u] = 1;
	for(int v = 1; v <= n; v++){
		if(color[v] == 0 && G[u][v] > 0){
			parent[v] = u;
			DFS(v);				
		}
	}
	f[u] = ++time;
	color[u] = 2;
}

int main(){
	for(int i = 1; i <= n; i++){
		d[i] = -1;
		f[i] = -1;
		parent[i] = -1;
		color[i] = 0;
		for(int j = 1; j <= n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int u = 1; u <= n; u++){
		if(color[u] == 0){
			DFS(u);
		}
	}	
	for(int i = 1; i <= n; i++)cout<<d[i]<<" ";cout<<endl;
	for(int i = 1; i <= n; i++)cout<<f[i]<<" ";cout<<endl;
	return 0;
}
