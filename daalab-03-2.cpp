#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<stack>
#include<queue>
using namespace std;
int main() {

    long long int bricks,ladders,i=0;
    cin>>ladders>>bricks;
    vector<long long int>nums;
    for(long long int i=0;i<42;i++){
        long long int x;
        cin>>x;
        nums.push_back(x);
    }  

    long long int tempBrick = bricks, checker = 0, j =0, counter=0,tempLadder = ladders ;
    for(long long int counter=0;counter<=41 and (tempBrick>0 || tempLadder>0 );counter++)
    {
       long long int maxi = 0;
       bricks = tempBrick, ladders = tempLadder, i= j ;
       while (i<nums.size())
       {if(bricks==0){
            break; }
            if((maxi <nums[i]) and ladders>0){
                maxi = nums[i];
                j = i+1;
                tempBrick = bricks; }
            if(nums[i]<=bricks){
                bricks-=nums[i];
                i++; 
                }
          else break;
       
       
    }  if(i>=nums.size()){
        cout<<nums.size();
        checker = 1;
        break;
       }

       tempLadder--; 

}
    int ans;
    if(checker==0) ans = i;

    cout<<ans;
    return 0;
}
