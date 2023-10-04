#include <bits/stdc++.h>
using namespace std;


void merge(  vector<int>&a, int start, int center, int last) {
    int firstArraySize = center - start + 1,secondArraySize = last - center,firstArray[firstArraySize],secondArray[secondArraySize];

    for (int i = 0; i < firstArraySize; i++) firstArray[i] = a[start + i];
    for (int j = 0; j < secondArraySize; j++) secondArray[j] = a[center + 1 + j];

    int j=0,i=0,k = start;

    if (firstArray[i] <= secondArray[j]) {
        while (i < firstArraySize) a[k++] = firstArray[i++];
        while (j < secondArraySize)  a[k++] = secondArray[j++];
    } 
    else {
        while (j < secondArraySize)  a[k++] = secondArray[j++];
        while (i < firstArraySize)  a[k++] = firstArray[i++];    
    }
}

void solver(  vector<int>&a, int start, int last) {
    if (start < last) {
        int center = (start + last) / 2;
        solver(a, start, center);
        solver(a, center + 1, last);
        merge(a, start, center, last);
    }
}

int main() {

 int n_dp, r_op = 0, u_op = 0, x_op = 0;
    cin>>n_dp;
    vector<int> vec_dp (n_dp,0);
    vector<int> :: iterator j;
    for(int i = 0; i<n_dp; i++)
    {
        cin>>vec_dp[i];
    }

    int num;
    cin >> num; 
   vector<int>arr;
    for (int i = 0; i < num; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    solver(arr, 0, num-1);
    
    for(int x: arr) cout<<x<<" ";
    return 0;
}
