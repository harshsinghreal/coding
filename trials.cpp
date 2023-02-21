#include"bits/stdc++.h"
using namespace std; 
int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        string f,s;
        cin>>f>>s;
        
        reverse(f.begin(),f.end());
        s+=f;
        
        int count=0;
        for(int i=0;i<n+m-1;i++){
            if(s[i]==s[i+1]) count++;
        }
        
        if(count<=1) cout<< "YES "<<endl;
        else cout<< "NO"<<endl;
    }

    return 0;
}