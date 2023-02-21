#include<iostream>
#include<stack>
using namespace std;
class Stack{
public:
    int *arr;
    int top;
    int size;

    Stack(int size){
       this-> size = size;
        arr = new int[size];
        top=-1;
       
    }

    void push(int data){
        if(size >top+1){
            top++;
            arr[top]=data;
        }
    }


        void pop(){
            if(top>=0){
                top--;
            }
        }
        void tope(){
            cout<<arr[top]<<endl;
        }


};


int main(){
    stack<int> st;
    st.push(5);
    st.push(34);
    int x=st.empty();
    cout<<st.top()<<" "<<x<<endl;

    Stack se(5);
    se.push(3);
    se.push(2);
    se.push(7);
    se.push(6);
    se.pop();
    se.tope();

    return 0;
}