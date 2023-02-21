#include <bits/stdc++.h>
using namespace std;

 int countSetBits(int n)
{
	 int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

int main()
{
	int i = 5;
	cout << countSetBits(i)<<endl;
    cout<<__builtin_popcount(4);
	return 0;
}
