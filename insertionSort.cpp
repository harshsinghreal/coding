#include<iostream>
using namespace std;

void insertion(int a[],int n){

for(int i=1;i<n;i++){
    int j= i-1,x=a[i];
    
    while(j>-1&& x<a[j]){
        //cout<<a[j]<<" "<<a[i]<<endl;
     a[j+1]=a[j];
        j--;
    
    }
    a[j+1]=x;
}

}

int main(){

    int a[]= {5,4,13,2,01};
    int n = 5;
    insertion(a,n);


    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
    return 0;
}