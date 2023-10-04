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
