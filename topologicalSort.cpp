#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;
//  khans topo sort begin
void khansToposort(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    for (auto neigh : adj[node]) {
        if (!visited[neigh]) {
            khansToposort(neigh, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> khansTopologicalSort(vector<vector<int>>& edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            khansToposort(i, visited, s, adj);
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// kahns topo sort end




int main() {
    int v = 6; // Number of vertices
    int e = 6; // Number of edges
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = khansTopologicalSort(edges, v, e);

    cout << "Topological Sort Order: ";
    for (int node : result) {
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