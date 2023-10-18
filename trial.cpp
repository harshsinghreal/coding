
#include <bits/stdc++.h>
using namespace std;

int gcd(int d,int s){
    if(d==0) return s;
    if(d>s) swap(d,s);
    return gcd(s%d,d);
}

int main(){

    cout<<gcd(105,147);

    return 0;
}