#include <bits/stdc++.h>
using namespace std;
  int V ;
 bool canTwoJudgeForm( vector< vector<int>>G, int closeFriend)
{
    
    int graphColor[V];
    for (int i = 0; i < V; ++i)
        graphColor[i] = -1;
   
    graphColor[closeFriend] = 1;
    queue <int> q;
    q.push(closeFriend);
  
     while (!q.empty())
    {
         int u = q.front();
        q.pop();
        if (G[u][u] == 1)
        return 0; 
  
         for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && graphColor[v] == -1)
            {
                graphColor[v] = 1 - graphColor[u];
                q.push(v);
            }
  
            else if (G[u][v] && graphColor[v] == graphColor[u])
                return 0;
        }
    }
  
    return 1;
}
   
int main()
{
    int n,c;
     cin>> n>>c;
      V=n;
   vector<vector<int>> G(n, vector<int>(n, 0));
  
  
    for(int i=0;i<c;i++){
         int x,y;
         cin>>x>>y;
         G[x][y] = 1;
         G[y][x] = 1;
     } 
  
    canTwoJudgeForm(G, 0) ? cout << 1 : cout << 0;
    return 0;
}