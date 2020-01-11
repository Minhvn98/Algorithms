#include <iostream>
#include <queue>
using namespace std;

const int maxx = 99;
int n, start, endd;
int G[maxx][maxx];
bool visited[maxx + 1] = {0};
int path[maxx];
int nb = 0;
int parent[maxx + 1];

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
		//Neu u chua tham va co duong di u->v
		if(!visited[v] && G[u][v] != 0){
			// Tham v
			visited[v] = true;
			path[++nb] = v;
			// Neu ket thuc
			if(v == endd){
				// In ra duong di
				for(int i = 0; i < nb; i++)
					cout<<path[i]<<" => ";
				cout<<path[nb]<<endl;
			}
			else
				DFS(v);
			nb--;
			visited[v] = false;
		}
	}
}

void BFS(int s){
	visited[s] = true;
	queue<int> Q;
	Q.push(s);
	int u = 0;
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int v = 1; v <= n; v++){
			if(!visited[v] && G[u][v] > 0){
				visited[v] = true;
				parent[v] = u;
				Q.push(v);		
			}
		}
	}
}

int main(){	
	freopen("DFS.INP", "r", stdin);
	cin>>n;
	cin>>start;
	cin>>endd;
	
	for(int i = 1; i <= n; i++){
		parent[i] = -1;
		for(int j = 1; j <= n; j++){
			cin>>G[i][j];
		}
	}
	
	path[0] = start;
	visited[start] = true;
	DFS(start);

//	BFS(start);
//	showPath();
	
	return 0;
}
