#include <iostream>
#include <unordered_map>
using namespace std;

int romanToDecimal(string &str) {
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int ans = 0;
    int prev = 0; // To keep track of the previous Roman numeral's value

    for (int i = str.length() - 1; i >= 0; i--) {
        int current = m[str[i]];
        
        // Check if we need to subtract the previous numeral
        if (current < prev)
            ans -= current;
        else
            ans += current;

        prev = current;
    }

    return ans;
}

int main() {
    string romanNumeral = "IIV"; // Replace with your Roman numeral string
    int result = romanToDecimal(romanNumeral);
    cout << "Decimal equivalent: " << result << endl;
    return 0;
}
