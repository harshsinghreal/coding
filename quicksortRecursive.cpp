#include<iostream>
using namespace std;


void quicksort(int arr[],int start, int end){
    if(end<=1){
        return;
    }int count = 0,pivot=arr[0];
    for(int i=0;i<end;i++){
        if(pivot<arr[i]){
            count++;
        }
    }
    quicksort(arr,start,count+start);
}
int main(){
    int arr[] = {1,3,2,54,4};
    int n=5;
    return 0;
}