#include<iostream>
#include<math.h>
using namespace std;

const int N = 5;

// Bieu dien do thi duoi dang ma tran ke
int M[N][N] = {
    {0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0}
};

// tim tat ca duong di tu dinh 3 -> 4
int NodeStart = 2, NodeEnd = 3;
bool visited[N];
int parent[N];
int pathCount = 0;

void printPath()
{
    int v = NodeEnd;
    int seq[N], nb = 0;
    while (v > -1)
    {
        seq[nb++] = v;
        v = parent[v];
    }
    cout << "Path " << (++pathCount) << ": ";
    for (int i = nb-1; i >= 0; i--) cout << (seq[i]+1) << " ";
    cout << endl;
}

void dfs(int u)
{
    for (int v = 0; v < N; v++)
    {
        if ( M[u][v] > 0 && !visited[v] )
        {
            visited[v] = true;
            parent[v] = u;
            if (v == NodeEnd)
            {
                printPath(); // in ra mot duong di
            } else {
                dfs(v);
            }
            parent[v] = -1;
            visited[v] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    
    for (NodeStart = 0; NodeStart < N; NodeStart++)
    {
        for (NodeEnd = 0; NodeEnd < N; NodeEnd++)
        {
            if (NodeStart != NodeEnd)
            {
                visited[NodeStart] = true;
                pathCount = 0;
                
                cout << "--- Cac duong di tu " << (NodeStart+1) << " den " << (NodeEnd+1) << " --- " << endl;
                dfs(NodeStart);
                
                visited[NodeStart] = false;
            }
        }
    }
    
    return 0;
}