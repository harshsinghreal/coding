#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&arr){
    for(auto &x:arr)cout<<x<<" ";
}

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int mini = arr[i],index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<mini){
                mini = arr[j];
                index = j;
            }
        }

        swap(arr[i],arr[index]);

    }
    print(arr);
}


void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
    print(arr);
}


void merge(vector<int>&arr,int left,int mid,int right){
    int len1 = mid-left+1;
    int len2 = right-mid;

    vector<int>temp1(len1),temp2(len2);
    for(int i=0;i<len1;i++)
        temp1[i] = arr[left+i];
    for(int i=0;i<len2;i++)
        temp2[i] = arr[mid+i+1];
    
    int i=0,j=0,k=left;

    while(i<len1 && j<len2){
        if(temp1[i]<=temp2[j])arr[k++] = temp1[i++];
         else arr[k++] = temp2[j++];
     }

    while(i<len1)arr[k++] = temp1[i++];
    while(j<len2)arr[k++] = temp2[j++];

}

void mergeSort(vector<int>&arr,int i,int j){
    if(i>=j) return;
    int mid = i+(j-i)/2;
    mergeSort(arr,i,mid);
    mergeSort(arr,mid+1,j);
    merge(arr,i,mid,j);
}
int main(){

    vector<int>arr = {2,1,4,6,3,7};
    // selectionSort(arr);
    // bubbleSort(arr);
    mergeSort(arr,0,arr.size()-1);
    print(arr);


    return 0;
}