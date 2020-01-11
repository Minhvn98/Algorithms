#include <iostream> 
#include <queue> 
#include <vector> 
#include <map>

#define Pair pair<int, int>
using namespace std; 

void WaterJug(int a, int b, int c) 
{ 
	map<Pair, int> m; 
	bool isSolvable = false; 
	vector<Pair> path; 

	queue<Pair> q;
	q.push(Pair(0, 0));

	while (!q.empty()) { 
		Pair u = q.front();
		q.pop();

		if (m[Pair(u.first, u.second)] == 1) 
			continue; 

		if ((u.first > a || u.second > b || u.first < 0 || u.second < 0)) 
			continue; 

		path.push_back(Pair(u.first, u.second)); 

		m[Pair(u.first, u.second)] = 1; 

		if (u.first == c || u.second == c) { 
			isSolvable = true; 
			int sz = path.size(); 
			for (int i = 0; i < sz; i++) 
				cout << "(" << path[i].first << ", " << path[i].second << ")\n"; 
			break; 
		} 
		
		q.push(Pair(u.first, 0)); 	// x, 0
		q.push(Pair(0, u.second)); 	// 0, y
		q.push(Pair(a, u.second));	// a, y
		q.push(Pair(u.first, b));	// x, b		
		
		if(u.first + u.second >= a)
			q.push(Pair(a, u.first + u.second - a)); 
		else
			q.push(Pair(u.first + u.second, 0));
						
		if(u.first + u.second >= b)
			q.push(Pair(u.first + u.second - b, b)); 
		else
			q.push(Pair(0, u.first + u.second)); 		 
	} 

	if (!isSolvable) 
		cout << "No solution"; 
} 

int main(){ 
	WaterJug(9, 7, 5); 
	return 0;  
} 

