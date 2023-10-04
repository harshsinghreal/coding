#include <bits/stdc++.h> 
using namespace std;
 

unsigned int i=0;
int vaishnoDevi(vector<int>&slopes, int toffees, int energys){
      int j =0,maxi = 0, tempToffee = toffees , reached = 0 ;
    for(int totalSlopes=0; totalSlopes<=41 && (tempToffee>0 || energys>0 ) ; totalSlopes++,maxi = 0, energys--) {
      
       i= j ;
       while (i<42) {
        if(toffees==0) break;
        if((maxi <slopes[i]) && energys>0){
                maxi = slopes[i];
                tempToffee = toffees;
                j = i+1;
             }
            if(slopes[i]<=toffees){
                toffees-=slopes[i];
                i++;
            }
            else break;
       
    }
      if(i>=slopes.size()){
        cout<<slopes.size();
       return 1;
       }
 
 
 toffees = tempToffee;

}

return 0;
}


int main() {

    int toffees,energys;
    cin>>energys>>toffees;
    vector<int>slopes;
    for(int i=0;i<=41;i++){
        int x; cin>>x;
        slopes.push_back(x);
    }  

  
    vaishnoDevi(slopes,toffees,energys)==0 ? cout<<i :cout<<"" ;
    return 0;
}
