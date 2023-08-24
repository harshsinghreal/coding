#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 10;
    n>>=1; cout<<n<<endl; //right shift    5
    n<<=1; cout<<n<<endl; // left shift     10
   // n = n&1;  
    cout<<(n&1);      // right most bit
    return 0;
}