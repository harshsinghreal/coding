#include<iostream>
using namespace std;

void bubblesort(int *arr,int n){
   int flag;
 for(int i=0; i<n-1;i++){
     flag=0;
     for(int j=0;j<n-1-i;j++){
         if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag=1;
         }
     }
     if(flag==0){
         cout<<"yes";
         break;
     }
 }
}


int main(){

    int a[]={5,4,3,1,2};
    int d = sizeof(a)/sizeof(a[0]);
    bubblesort(a,d);
    // for(int i=0;i<4; i++){
    //     for (int j = 0; j < 5; j++)
    //     {
    //          if(a[i]<a[j]){
    //              swap(a[i],a[j]);
    //              cout<<a[i]<<","<<a[j]<<" ";
    //          }
    //     }cout<<endl;
        
    // }

    cout<<"final array"<<endl;
    for (int i = 0; i < 5; i++)
    {
       cout<<a[i]<<" ";
    }
    
    return 0;
}