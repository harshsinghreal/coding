#include<bits/stdc++.h>
using namespace std;

int main(){

    deque<int> q;
    q.push_back(5);
    q.push_front(8);
    q.push_back(52);

    int x = q.front();
    q.pop_front();
    q.push_back(x);
    cout<<q.front()<<" "<<q.back()<<" "<<q.size();

    return 0;
}