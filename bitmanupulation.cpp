#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;--i){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}


int main(){

    int n = 10;     
    n>>=1; cout<<n<<endl; //right shift    5
    n<<=1; cout<<n<<endl; // left shift     10
   // n = n&1;  
    cout<<(n&1)<<endl;      // right most bit


    cout<<"hello"<<char(1<<5)<<"raj"; //this is space character
     char c = 'a';
    char d = c&(~(1<<5)); // this will convert small a to capial A
    cout<<d<<" "<< char(d|(' ')) <<" "<< char(c&'_')<<endl;  //lowe to upper (&"_") upper to lower (|" ")
    
    int val=59;
    printBinary(val);

    //if we want to clear 4 lsb of 59
    int clearLsb = (val & (~((1<<(4))-1)));   
    printBinary(clearLsb);

    //check even odd
    if(val & (val-1)) cout<<val<<" is not power of two"<<endl;  // 16 = 10000  16-1 = 01111
    else cout<<"power of two"<<endl;


/*###################   SWAP TWO NUMBER WITHOUT 3RD VAIABLE ##################*/
    int a = 4, b=6;
    a = a^b;
    b = b^a;    // b^(a^b) ==> a^(b^b) ==> a
    a = a^b;    // (a^b) ^a ==> b
    cout<<a<<" "<<b<<endl;

/*#############################################################################*/    


    return 0;
}