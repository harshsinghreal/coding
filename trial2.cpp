#include <bits/stdc++.h>

using namespace std;

long long max_cost = 0;
array<long long, 2> dfs(int i, int p, vector<vector<int>> &al, vector<int>& price) {
    array<long long, 2> res({price[i], 0});
    for (int j : al[i])
        if (j != p) {
            auto res_j = dfs(j, i, al, price);
            max_cost = max({ max_cost, res[0] + res_j[1], res[1] + res_j[0] });
            res[0] = max(res[0], res_j[0] + price[i]);
            res[1] = max(res[1], res_j[1] + price[i]);
        }
    return i == 0 ? array<long long, 2>({max_cost, 0}) : res;
}
long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    vector<vector<int>> al(n);
    for(auto& e : edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    return dfs(0, -1, al, price)[0];
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }

    vector<int> price(n);
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    
    cout << maxOutput(n, edges, price) << endl;

    return 0;
}
