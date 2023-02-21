#include<iostream>
using namespace std;

int main(){
    int a[]={1,2,3,4,5,7};
    int start=0,end=6,x;
    cout<<"enter no to search"<<endl;
    cin>>x;
    while ( start<=end)
    {
         int mid = start +(end-start)/2;
         if(x==a[mid]){
           cout<<mid<<" ";
           break;
         }
         if (x>a[mid])
        {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        
         
    }
    
       
        
    
    
    
    return 0;
}