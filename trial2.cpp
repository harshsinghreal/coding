#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minInitialBonus(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

vector<vector<int>> dp(m, vector<int>(n, 0));
dp[m-1][n-1] = max(1, 1 - grid[m-1][n-1]);
 for (int j = n - 2; j >= 0; j--) {
        dp[m-1][j] = max(1, dp[m-1][j + 1] - grid[m-1][j]);
    }
 for (int i = m - 2; i >= 0; i--) {
        dp[i][n-1] = max(1, dp[i + 1][n-1] - grid[i][n-1]);
    }
 for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            int minCostOnExit = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, minCostOnExit - grid[i][j]);
        }
    }
  return dp[0][0];
}

int main() {
    int m, n;
   cin >> m;
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
   for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = minInitialBonus(grid);
    cout  << result << endl;

    return 0;
}
