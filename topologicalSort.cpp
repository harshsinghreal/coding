#include <bits/stdc++.h>

using namespace std;
//   topo sort begin
void Toposort(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, vector<int>>& adj) {
    visited[node] = true;
    for (auto neigh : adj[node]) {
        if (!visited[neigh]) {
            Toposort(neigh, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> TopologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            Toposort(i, visited, s, adj);
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// kahns topo sort end



vector<int> kahnsTopologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    queue<int>q;
    vector<int>ans;
    vector<int>indegree(v);
    for(int i=0;i<v;i++){
            for(auto x : adj[i]){
                    indegree[x]++;
            }

    }
    
    for(int i=0;i<v;i++) if(indegree[i]==0) q.push(i);
    while(!q.empty()){
        int top = q.front(); q.pop();
        ans.push_back(top);
        for(auto neigh : adj[top]){
                indegree[neigh]--;
                if(indegree[neigh]<=0) q.push(neigh);
        }
    }
    return ans;

}
int main() {
    int v = 6; // Number of vertices
    int e = 6; // Number of edges
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3,5}
    };

    //dfs
    vector<int> result = TopologicalSort(edges, v, e);

    //bfs kahns algo
    vector<int> result2 = kahnsTopologicalSort(edges, v, e);

    cout << "Topological Sort Order DFS: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Topological Sort Order BFS: ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}



/*

2
2 1
1 0
3 2
0 1
0 2


*/