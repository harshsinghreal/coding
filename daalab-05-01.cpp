#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> R, U;
    int rVal = 0, uVal = 0, xVal = 0, num;
    scanf("%d",&num);
    for (int i = 0; i < num; i++){
        int garbage;
        cin >> garbage;
        R.push(garbage);
    }

    while (!R.empty()){
        int garbage = R.top();
        if (U.empty() || garbage <= U.top())  U.push(garbage),R.pop(),rVal++;
        
        else if (U.size() > 1 and garbage > U.top() ) {
            int uGarbage = U.top();
            U.pop(),R.pop(),R.push(uGarbage);
            if (garbage <= U.top()) U.push(garbage);
            else R.push(garbage), uVal++;
             xVal+=1;
          }

        else if ( U.size() == 1 and garbage > U.top() ) {
            int uGarbage = U.top();
            U.pop(),R.pop(),xVal++;
            U.push(garbage),R.push(uGarbage);
         }
    }
   printf("%d%d%d",rVal,uVal,xVal);
    return 0;
}