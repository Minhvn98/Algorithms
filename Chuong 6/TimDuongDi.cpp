#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define max 99
int m = max, n = max;
int G[max + 1][max + 1];
bool visited[max + 1][max + 1] = {0};

int ch[3] = {1, 0, -1};
int cc[3] = {0, 1, 0};

struct Point{
	int i;
	int j;
};

Point start, end;
vector<Point> save;

bool Check(Point v, Point u){
	for(int t = 0; t < 3; t++){
		int i = u.i - ch[t];
		int j = u.j - cc[t];			
		if(i == v.i && j == v.j)
			return true;
	}
	
	return false;
}

void BFS(Point s){
	queue<Point> Q;
	Q.push(s);		
	Point u;
	Point v;
	while(!Q.empty()){
		u = Q.front();		
		//cout<<u.i<<" "<<u.j<<endl;
		save.push_back(u);
		if(u.i == end.i && u.j == end.j)
			break;
		visited[u.i][u.j] = true;				
		Q.pop();
		for(int t = 0; t < 3; t++){
			v.i = u.i + ch[t];
			v.j = u.j + cc[t];			
			if(!visited[v.i][v.j] && G[v.i][v.j] == G[u.i][u.j]){
				visited[v.i][v.j] = true;
				Q.push(v);
			}
		}
	}
//	cout<<save.size()<<endl;
//	for(int i = 0; i < save.size(); i++)
//		cout<<save[i].i<<" "<<save[i].j<<endl;
	
	Point arr[save.size()];
	arr[0] = save[save.size() - 1];
	int count = 1;
	
	Point fu = arr[0];
	
	for(int k = save.size() - 2; k >= 0; k--){
		if(Check(save[k], fu)){
			arr[count++] = save[k];
			fu = save[k];
		}
	}	
	cout<<count<<endl;
	for(int i = count - 1; i >= 0; i--)
		cout<<arr[i].i<<" "<<arr[i].j<<endl;
}

int main(){
	freopen("dd1.inp", "r", stdin);
	freopen("dd1.out", "w", stdout);
	cin>>n;
	cin>>m;
	cin>>start.i;
	cin>>start.j;
	cin>>end.i;
	cin>>end.j;	
	
//	cout<<start.i<<" "<<start.j<<endl;
//	cout<<end.i<<" "<<end.j<<endl;
		
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>G[i][j];			
		}
	}
	
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout<<G[i][j] << " ";			
//		}
//		cout<<endl;
//	}
		
	BFS(start);
	
	return 0;
}
