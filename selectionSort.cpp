#include<iostream>
using namespace std;

void selection(int a[],int n){
    int i,j,k;
   cout<<n<<endl;
    for(int i=0;i<n-1;i++){
         k=j=i;
          
        while(j<n){
            if(a[j]<a[k]){
                k=j;
                
            }
            j++;
        }
        swap(a[i],a[k]);
    }
}

int main(){
int a[] = {4,12,5,10,7,1,43};
int n = sizeof(a)/sizeof(a[0]);


selection(a,n);
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

    return 0;
}