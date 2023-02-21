#include<iostream>
using namespace std;


struct Result{
    
    char x;
    int f;
    char y;
    
}; 


#pragma pack(1) //here pragma is use to not pad automatically by compiler else it will pad 4 bytes

struct padd{
    
    char x;
    int f;
    char y;
    
}; 

int main(){
    cout<<sizeof(Result)<<endl;
    cout<<sizeof(padd)<<endl;
    return 0;
}