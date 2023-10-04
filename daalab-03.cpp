#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(const vector<int>& heights, int energy, int toffee, int i) {
    if (i == heights.size() - 1) return 0;
     if(energy == 0 && toffee == 0 && heights[i] > 0) return 0;
       
    // Check if the result is already computed.
    if (dp[energy][toffee] != -6) return dp[energy][toffee];
    if(heights[i] <= 0) return 1 + solve(heights, energy-heights[i], toffee, i+1);
         
    // Calculate the result for the current state.
    int byEnergy = 0, byToffee = 0;
    if (energy >= heights[i]) {
        byEnergy =  1+solve(heights, energy - heights[i], toffee, i + 1);
    }
    if (toffee > 0) {
        byToffee =  1+solve(heights, energy, toffee - 1, i + 1);
    }

    // Store the result in the dp table.
    return dp[energy][toffee] = max(byEnergy, byToffee);
}

int furthestBuilding(vector<int>& heights, int energy, int toffee) {
    dp = vector<vector<int>>(energy + 100, vector<int>(toffee + 100, -6));
    return solve(heights, energy, toffee, 0);
}

int main() {
    int energy, toffee;
    cin >> toffee >> energy;
    vector<int> heights(42); // Assuming there are 42 elements in the heights array.
    
    cout << "Enter heights:" << endl;
    for (int i = 0; i < 42; i++) {
        cin >> heights[i];
    }
    
    cout << "Furthest reach: " << furthestBuilding(heights, energy, toffee)-1<< endl;
    return 0;
}
