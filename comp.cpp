#include <bits/stdc++.h>

using namespace std;


//sort in asc if same  sort in desc
bool comp(vector<int>a,vector<int>b){

    if(a[0]==b[0])
   return a[1] >b[1];
   else
        return a[0]<b[0];

}


int main()
{
    vector<vector<int>>v;
    for(int i=0;i<5;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
        
    }cout<<endl;
   sort(begin(v),end(v));
    for(int i=0;i<5;i++){
        cout<<v[i][0] <<" "<<v[i][1]<<endl;
    }
    return 0;
}