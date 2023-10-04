#include<iostream>
#include<math.h>
using namespace std;

void merge(int arr[],int l, int mid,int h){
    int i=l,j=mid+1,k=l;
    int b[123];
    while(i<=mid && j<=h){
    if(arr[i]<arr[j]){
        b[k++]=arr[i++];}
    else{
        b[k++]=arr[j++];}
    
    }
    for(;i<=mid;i++){
        b[k++]=arr[i];
    }
    for(;j<=h;j++){
        b[k++]=arr[j];
    }


    for(int i = l;i<=h;i++){
        arr[i]=b[i];
    }
}
void mergeSort(int arr[],int n){
        int p,l,mid,h,i;
        for(p=2;p<=n;p=p*2){
            for ( i = 0; i+p-1<n; i=i+p)
            {
                l=i;
                h=i+p-1;
                mid=(l+h)/2;
               // mid = l+(h-l)/2;
                merge(arr,l,mid,h);
            }
            
        }
   // cout<<p<<" "<<n<<" "<<endl;
        if(p/2<n)
            merge(arr,0,p/2-1,n);
}

int main(){

    int arr[]={1,7,9,12,3,14,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<n<<endl;
    mergeSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl<<"done "<<log10(1000);
    return 0;
}