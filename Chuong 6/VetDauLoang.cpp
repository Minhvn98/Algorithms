#include <iostream>
#include <queue>
using namespace std;
#define max 99
int m = max, n = max;
int G[max + 1][max + 1];
bool visited[max + 1][max + 1] = {0};
int best = -1;
int count = 1;
int ch[4] = {-1, 0, 0, 1};
int cc[4] = {0, -1, 1, 0};

struct Point{
	int i;
	int j;
};

Point start, endd;

void BFS(Point s){
	count = 1;
	queue<Point> Q;
	Q.push(s);		
	Point u;
	Point v;
	while(!Q.empty()){
		u = Q.front();	
		//cout<<u.i<<" ,"<<u.j<<endl;	
		visited[u.i][u.j] = true;		
		Q.pop();
		for(int t = 0; t < 4; t++){
			v.i = u.i + ch[t];
			v.j = u.j + cc[t];			
			if(!visited[v.i][v.j] && G[v.i][v.j] == G[u.i][u.j]){
				// Tham
				visited[v.i][v.j] = true;
				count++;
				if(best < count){
					best = count;
					start = s;
					endd = v;
				}
				// Push
				Q.push(v);
			}
		}
	}
}

int main(){
	freopen("dd.inp", "r", stdin);
	freopen("dd.out", "w", stdout);
	cin>>n;
	cin>>m;
		
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>G[i][j];			
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!visited[i][j]){
				Point s;
				s.i = i;
				s.j = j;
				BFS(s);
			}
		}		
	}
	
	cout<<best<<endl;
	//cout<<"start: "<<start.i<<" , "<<start.j<<endl;
	//cout<<"end: "<<end.i<<" , "<<end.j<<endl;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = 0;
		}		
	}	
	queue<Point> Q;
	Q.push(start);		
	Point u;
	Point v;
	while(!Q.empty()){
		u = Q.front();	
		cout<<u.i<<" "<<u.j<<endl;	
		visited[u.i][u.j] = true;		
		Q.pop();
		for(int t = 0; t < 4; t++){
			v.i = u.i + ch[t];
			v.j = u.j + cc[t];			
			if(!visited[v.i][v.j] && G[v.i][v.j] == G[u.i][u.j]){
				visited[v.i][v.j] = true;
				Q.push(v);
			}
		}
	}
	return 0;
}
