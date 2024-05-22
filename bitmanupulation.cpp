#include<bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;--i){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int pow2(int a,int b){
    if(b==0) return 1;
    int res = pow2(a, b/2);
    if(b&1){
        return (a*res*res);
    }
    else{
        return (res*res);
    }
}


int pow3(int a, int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
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

double dbl = 1e23;
cout<<fixed<<setprecision(30)<<dbl<<endl; //double value is not stable
cout<<pow2(2,3)<<endl; //calculate power recursive
cout<<pow3(2,5)<<endl;  // calculate power iterative
    return 0;
}