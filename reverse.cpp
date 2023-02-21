#include<iostream>
#include<algorithm>
using namespace std;


void reversing(string& s,int i,int j){
    if (i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }

else{
    reversing(s,i,j);
}
    
}

int main(){
    string a="babbar";
    int j=a.size(),i=0;
    j--;
    int x = j;
    cout<<j<<endl;
    
    reversing(a,i,j);

    for (int i = 0; i <= x; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}