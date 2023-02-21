#include<bits/stdc++.h>
using namespace std;


class polymorphism{
  public:
  void func(int x){
      cout<<"first"<<endl;
  }
  void func(int x, float y){
    cout<<"second"<<y<<endl;
  }

};


class encalpsulation{

        private:
            int var;
        public:
            void set(int a){
                cout<<"setted "<<endl;
                this->var = a;
            }

            int get(){
                    return this->var;
            }
};


int main(){
    
    encalpsulation obj;
    obj.set(4);
    cout<<obj.get();

    return 0;
}