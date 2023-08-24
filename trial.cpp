// #include <bits/stdc++.h>

// using namespace std;


// int solver(vector<int> arr){
//     int n = arr.size(), ans=0,count=0,tempSum=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         tempSum+=arr[i];
//         for(int j=i+1;j<n;j++){
//             tempSum+=arr[j];
//       int numCount = abs(j - i) + 1;
//       int sum = ((arr[i] + arr[j]) * numCount) / 2;
//       if(sum==tempSum && j-i>maxi){
//           ans=j-i;
//           maxi = j-i;
//       } 
//         }
//     }
//     return ans;
// }

// int main() {
//         int n ;
//         cin>>n;
//         vector<int>arr;
//         for(int i=0;i<n;i++){
//         int x; cin>>x;
//         arr.push_back(x);
//         }
    
//     cout<<solver(arr);
   

//     return 0;
// }


//2222222222222222222
// #include <bits/stdc++.h>

// using namespace std;

// int summer(int in,int jn){
//     int sum=0;
//     for(int i=in;i<=jn;i++) sum+=i;
//     return sum;
// }

// int solver(vector<int> arr){
//     int n = arr.size(), ans=0,count=0,tempSum=0,maxi=INT_MIN;
//     for(int i=0;i<n;i++){
//         tempSum=arr[i];
//         for(int j=i+1;j<n;j++){
//             tempSum+=arr[j];
//     //   int numCount = abs(j - i) + 1;
//     //   int sum = ((arr[i] + arr[j]) * numCount) / 2;
//     int sum = summer(arr[i],arr[j]);
//         cout<<j<<" "<<sum<<" "<< tempSum<<endl;
    
//       // if(sum!=tempSum) break;
//       if(sum==tempSum && j-i>maxi){
//           ans=j-i;
//           maxi = j-i;
//       } 
//         }
//     }
//     return ans+1;
// }

// int main() {
//         int n ;
//         cin>>n;
//         vector<int>arr;
//         for(int i=0;i<n;i++){
//         int x; cin>>x;
//         arr.push_back(x);
//         }
    
//     cout<<solver(arr);
   

//     return 0;
// }




//33333333333333
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// #include <bits/stdc++.h>

// using namespace std;
// int rangeSum(int first,int last){
//     int sum=0;
//     for(int i=first;i<=last;i++) sum+=i;
//     return sum;
// }

// int solver(vector<int>arr){
    
//     int range = 0,tempSum=0,sum=0,n=arr.size();
//     for(int i=0;i<n;i++){
//         tempSum = arr[i];
//         for(int j=i+1;j<n;j++){
//             sum = rangeSum(arr[i],arr[j]);
//             tempSum += arr[j];
//             cout<<sum<<" "<<tempSum<<endl;
//             if(sum==tempSum) range = max(range,j-i+1);
//         }
//     }
    
//     return range;
// }

// int main()
// {
//      int n ;
//         cin>>n;
//         vector<int>arr;
//         for(int i=0;i<n;i++){
//         int x; cin>>x;
//         arr.push_back(x);
//         }
    
//     cout<<solver(arr);
   


//     return 0;
// }





// #include <bits/stdc++.h>

// using namespace std;



// int findLargestSegment(vector<int>heights){
//       int n = heights.size(), maxDiff = 0;

//         for (int i = 0; i < n; i++) {
//             int mini = heights[i], maxi = heights[i];
//             unordered_set<int> seen;
//             seen.insert(mini);
            
//              for (int j = i + 1; j < n; j++) {
//                 if (seen.find(heights[j])!= seen.end()) {
//                     break;
//                 }

//                 mini = min(mini, heights[j]);
//                 maxi = max(maxi, heights[j]);
                
//                  if (maxi - mini == j - i) {
//                     maxDiff = max(maxDiff, j - i);
//                 }
//                 seen.insert(heights[j]);
//             }
//         }

//         return maxDiff+1;
// }

// int main()
// {
//         int n ;
//         cin>>n;
//         vector<int>arr;
//         for(int i=0;i<n;i++){
//         int x; cin>>x;
//         arr.push_back(x);
//         }
    
//         cout<<findLargestSegment(arr);
   

//     return 0;
// }



#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m,mini,maxi;
    cin >> n;
    vector<int> students;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        students.push_back(x);
    }
    
   
    for (int l = 0; l < n; l++) {
       maxi= mini = students[l];
        unordered_map<int, int> visited;  
        visited[students[l]]++;
        for (int h = l + 1; h < n && !visited[students[h]];visited[students[h]]++, h++) {
             mini = min(mini, students[h]);
             maxi = max(maxi, students[h]);
             h-l==maxi - mini ? m = max(h - l,m) : 0;
          }
     }
    
    cout<<m+1;

    return 0;
}
