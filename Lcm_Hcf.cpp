#include<iostream>
using namespace std;


class LcmHcf
{
    
public:
     int  x,y;
     int input(int x,int y){
        this->x = x;
        this->y = y;
        return 0;
     }
    int num = 1;
     int lcm(){
         while (true){
        if(num%x==0 && num%y==0){
                cout<<"LCM-> "<<num;
                break;
         }
       
            num++;
        }
        return 0;
     }
};


int main()
{
    LcmHcf l;
    int x,y;
    cout<<"INPUT BOTH NUMBER ";
    cin>>x>>y;
    l.input(x,y);
    l.lcm();
    return 0;
} 