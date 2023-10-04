#include <bits/stdc++.h>
using namespace std;
int mini = INT_MAX;
        
void solve(vector<vector<int>>& grid, int i, int j, int row, int col, int cnt, int x2,int y2){
        if(i < 0 or i >= row or j < 0 or j >= col or grid[i][j] != 0) return;
        if(grid[i][j] == 0) cnt++;
        
        if(i == x2 and j == y2){
            mini = min(mini, cnt);
            return;
        } 
        grid[i][j] = 2;
      
     solve(grid, i-1, j, row, col, cnt,x2,y2);
     solve(grid, i, j-1, row, col, cnt,x2,y2);
     solve(grid, i, j+1, row, col, cnt,x2,y2);
     solve(grid, i+1, j, row, col, cnt,x2,y2);
                
        
        grid[i][j] = 0;
    }
    int solver(vector<vector<int>>& grid,int x1,int y1, int x2, int y2, int m, int n) {
        solve(grid, x1,y1, m, n, 0,x2,y2);
        if(mini == INT_MAX) return -1;
        return mini;
    }

int main() {


    string s;
    int n,x1,y1,x2,y2;
    cin>>s>>n>>x1>>y1>>x2>>y2;
    int m = s.length()/n;
    int k = 0;
    vector<vector<int>> maze(m,vector<int>(n,0));
   for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            s[k]=='1' ?  maze[i][j]=1 : maze[i][j] = 0;
            k++;
             
        }    
    }
    
     
   cout<< solver(maze,x1,y1,x2,y2,m,n)-1;
     for(int i=0;i<m;i++){cout<<endl;
        for(int j=0;j<n;j++){
                cout<<maze[i][j]<<" ";
        }}

return 0;
}