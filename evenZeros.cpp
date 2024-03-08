// #include <bits/stdc++.h>

// using namespace std;

// const vector<char> p = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// int countStrings(int n, int aCount) {
//     if (n == 0) return (aCount % 2 == 0) ? 1 : 0;
//     int totalStrings = 0;
//     for (char ch : p) {
//         if (ch == 'a') {
//             totalStrings += countStrings(n - 1, aCount + 1);
//         } else {
//             totalStrings += countStrings(n - 1, aCount);
//         }
//     }

//     return totalStrings;
// }

// int main() {
//     int n;
//     cin >> n;

//     int result = countStrings(n, 0);

//     cout << result << endl;

//     return 0;
// }




















// #include <bits/stdc++.h>
// using namespace std;

// const int N = 11;
// vector<vector<int>> dp(N, vector<int>( N, -1));

// int countStrings(int n, int aCount) {
//     if (n == 0)
//         return (aCount % 2 == 0) ? 1 : 0;

//     if (dp[n][aCount] != -1)
//         return dp[n][aCount];

//     int totalStrings = 0;
//     vector<char> p = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

//     for (char ch : p) {
//         if (ch == 'a') {
//             totalStrings += countStrings(n - 1, aCount + 1);
//         } else {
//             totalStrings += countStrings(n - 1, aCount);
//         }
//     }

//     return dp[n][aCount] = totalStrings;
// }

// int main() {
//     int n;
//     cin >> n;

//     int result = countStrings(n, 0);

//     cout << result << endl;

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;

// int solveTab(int n){
    
//     vector<vector<int>> dp(n+1, vector<int>(n * n, 0));
//     dp[0][0]=1;
//     int totalStrings = 0;
//     vector<char> p = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

// for(int i=1;i<=n;i++){
//      totalStrings = 0;
//     for (int aCount = 0; aCount <= n * n / 2; ++aCount) {
//     for (char ch : p) {
//         if (ch == 'a') {
//             totalStrings += dp[i - 1][ aCount + 1];
//         } else {
//             totalStrings += dp[i - 1][ aCount];
//         }
       
//     }
    
//      dp[n][aCount] = totalStrings;
//      }
// }
//     return totalStrings;
// }

// int main(){
//     int n;
//     cin>>n;
//     int result = solveTab(n);
//     cout<<result;
// }






//Tabulation method
// #include <bits/stdc++.h>

// using namespace std;

// int SolveTab(int n){
//      vector<vector<int>>dp(n+1,vector<int>(n,0));
//      for(int i=0;i<=n;i+=2){
//          dp[0][i] = 1;
//      }
//     for (int len = 1; len <= n; ++len) {
//         for (int aCount = 0; aCount <= n; ++aCount) {
//             for (char ch : {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}) {
//                 if (ch == 'a') {
                    
//                      dp[len][aCount] += dp[len - 1][aCount + 1];
                    
//                 } else {
//                     dp[len][aCount] += dp[len - 1][aCount];
//                 }
//             }
//         }
//     }

  
//     return dp[n][0];
// }

// int main() {
//     int n;
//     cout << "Enter the length of the string (n): ";
//     cin >> n;
//     int res = SolveTab(n);
//     cout << "Number " << res << endl;

//     return 0;
// }









#include <bits/stdc++.h>
using namespace std;
int SolveTab(int n){
     vector<vector<int>>dp(n+1,vector<int>(n,0));
     vector<char> sigmaSet = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

     for(int i=0;i<=n;i+=2) dp[0][i] = 1;
      
    for (int len = 1; len <= n; ++len) {
        for (int aCount = 0; aCount <= n; ++aCount) {
            for (char ch : sigmaSet) {
                if (ch == '0')  dp[len][aCount] += dp[len - 1][aCount + 1];
                    else        dp[len][aCount] += dp[len - 1][aCount];
             }
        }
    }

  
    return dp[n][0];
}

int main() {
    int n;
    cin >> n;
    int res = SolveTab(n);
    cout << res << endl;

    return 0;
}
