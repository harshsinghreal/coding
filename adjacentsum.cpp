#include <bits/stdc++.h> 
using namespace std;
 int solve(vector<int> &nums, int n,vector<int> &dp){
    
    if(n<0)
        return 0;
    if(dp[n]!=-1) return dp[n];
    int inc = solve(nums,n-2,dp)+nums[n];
    int exc = solve(nums,n-1,dp);
    
    dp[n]= max(inc,exc);
     return dp[n];
} 


int solver(vector<int>&nums){
    int n = nums.size();
    vector<int>dp(n,0);
     dp[0] = nums[0];
    for(int i=2;i<n;i++){
            int inc = dp[i-2] + nums[i];
            int exc = dp[i-1] + 0;
            dp[i] = max(inc,exc);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solver(nums);
   // return solve(nums,n-1,dp);
    
}

int main(){
    vector<int> v={1,2,3,4,15,6};

    int x = maximumNonAdjacentSum(v);
    cout <<x;
    return 0;
}