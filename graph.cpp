#include<bits/stdc++.h>
using namespace std;


 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> ans;
      queue<int> q;
     unordered_map<int,bool> visited;
     q.push(0);
     visited[0]=1;
     
     while(!q.empty()){
         int curr  =  q.front(); q.pop();
         ans.push_back(curr);
         for(auto i : adj[curr]){
             if(!visited[i]){
                 
             q.push(i);
             visited[i]=1;
             }
         }
     }
     
       return ans;
       
    }

vector<int> dfsTraversal;
void dfs(int start,vector<int> adj[],unordered_map<int,bool> &visited){
        
        visited[start] =1;
        dfsTraversal.push_back(start);
        for(auto x:adj[start]){
            if(!visited[x])
             dfs(x,adj,visited);
        }
    }
  

int main(){

    
    vector<vector<int>> edges ={ {1,0},{1,2},{2,0}};


    // Adjacency list
    unordered_map<int,vector<int>> adj; 
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_map<int,bool> visited;

        for (int i = 0; i < adj.size(); i++)
        {
          cout<<adj[i][0]<<" "<<adj[i][1]<<endl;
        }
        
    

    return 0;
}