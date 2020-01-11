#include <iostream>
#include <queue>

using namespace std;
const int n = 5;
int G[n + 1][n + 1] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1},
	{0, 1, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0}
};

int color[n + 1] = {0}; // 0 - White / 1 - Gray / 2 - Black
int d[n + 1]; // thoi gian bat dau
int f[n + 1]; // thoi gian ket thuc
int time = 0;
int nb = 0;
int L[n + 1];

void DFS(int u){
	d[u] = ++time;
	color[u] = 1;
	for(int v = 1; v <= n; v++){
		if(color[v] == 0 && G[u][v] > 0){
			DFS(v);				
		}
	}
	f[u] = ++time;
	color[u] = 2;
	L[nb++] = u;
}

void topo_sort(){	
	queue<int> Q;
	int ind[n + 1] = {0};
	// Tinh in degree
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(G[i][j] > 0)ind[j]++;
	
	for(int v = 1; v <= n; v++)
		if(ind[v] == 0)
			Q.push(v);
		
	int v;	
	while(!Q.empty()){
		v = Q.front();Q.pop();
		cout<<v<<" ";
		
		for(int u = 1; u <= n; u++){
			if(G[v][u] > 0){
				ind[u]--;
				if(ind[u] == 0)
					Q.push(u);
			}
		}
	}
	cout<<endl;
}

int main(){
	for(int i = 1; i <= n; i++){
		d[i] = -1;
		f[i] = -1;
		for(int j = 1; j <= n; j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	
	topo_sort();
	
	for(int u = 1; u <= n; u++){
		if(color[u] == 0){
			DFS(u);
		}
	}	
	for(int i = 1; i <= n; i++)cout<<d[i]<<" ";cout<<endl;
	for(int i = 1; i <= n; i++)cout<<f[i]<<" ";cout<<endl;
	for(int i = nb - 1; i >= 0; i--)cout<<L[i]<<" ";cout<<endl;
	return 0;
}
