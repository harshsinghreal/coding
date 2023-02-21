#include<bits/stdc++.h>
using namespace std;





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