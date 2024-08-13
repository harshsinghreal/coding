#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<stack>

using namespace std;

string multiply(string a, string b) {
    int m = a.size(), n = b.size();
    vector<int> result(m + n, 0);
    
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }
    
    string product;
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }
    
    return product.empty() ? "0" : product;
}

bool hasAdjacentDuplicates(const vector<int>& digits) {
    for (int i = 0; i < digits.size() - 1; ++i) {
        if (digits[i] == digits[i + 1]) {
            return true;
        }
    }
    return false;
}

int ArrayChallenge(int n) {
    string numStr = to_string(n);
     
    int counter = 1;
    stack<string>st;
    st.push(numStr);
    while (true) {

        string tempStr = numStr;

        for(int i=0;i<st.size();i++){
            stack<string>st2;
        for (char c : tempStr) {
            vector<int>digits;
            string productStr = multiply(tempStr, string(1, c));
            // cout<<productStr<<endl;
            string jointString = tempStr+productStr;
            
            st2.push(jointString);
            st.push(productStr);
            for (char ch : jointString) {
                digits.push_back(ch - '0');
            }
             if (hasAdjacentDuplicates(digits) ) {
            return counter;
        }
        }
        }

        // numStr = multiply(tempStr, tempStr.substr(0, 1)); // update n to be n * its first digit
        numStr = st.top();st.pop();
        counter++;
         if(counter>15) break;
         
    }

    return counter;
}

int main() {
    cout << ArrayChallenge(134) << endl; // Output: 1
    cout << ArrayChallenge(8) << endl; // Output: 3
    cout << ArrayChallenge(14) << endl; // Output: 3
    cout << ArrayChallenge(198) << endl; // Output: 2
    return 0;
}
