#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solver(int k, int n) {
       unordered_map<string, int> memo;
       return routers(k, n, memo);
    }

private:
    int routers(int k, int n, std::unordered_map<std::string, int>& memo) {
        string key = to_string(k) + "#" + to_string(n);
        if (memo.find(key) != memo.end())  return memo[key];
        
        if (k == 1 || n==0) {
            memo[key] = n;
            return n;
        }
 

        int l = 1, h = n, mini = INT_MAX;

        while (l <= h) {
            int currentFloor = (l + h) >> 1;
            int breakResult = routers(k - 1, currentFloor - 1, memo);
            int notBreakResult = routers(k, n - currentFloor, memo);
            int totalSteps = 1 + std::max(breakResult, notBreakResult);

            mini = min(mini, totalSteps);
            breakResult < notBreakResult ?  l = currentFloor + 1 : h = currentFloor - 1;
             
        }
    
        return memo[key] = mini;
    
    }
};




int main() {
    Solution solution;
    int k1, n1;
    cin>>n1>>k1;
    cout << solution.solver(k1, n1);
 
    return 0;
}