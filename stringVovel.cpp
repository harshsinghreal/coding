#include<iostream>
using namespace std;

int main(){
    string s="hello",j="";
    for(int i=0;i<5;i++){
      //  if(s[i]=='z')
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            s[i]+=1;
            j.push_back(s[i]);
            cout<<s[i]<<" ";
        }
        else{
            s[i]-=1;
             j.push_back(s[i]);
            cout<<s[i]<<" ";
        }
    }

    cout<<j;

    return 0;
}