// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<string, int>& a,
		pair<string, int>& b)
{
	return a.second < b.second;
}
void sort(map<string, int>& M)
{

	vector<pair<string, int> > A;

	for (auto& it : M) {
		A.push_back(it);
	}

	sort(A.begin(), A.end(), cmp);

	for (auto& it : A) {

		cout << it.first << ' '
			<< it.second << endl;
	}
}

// Driver Code
int main()
{
	
	// Declare Map
	map<string, int> M;

	// Given Map
	M = { { "GfG", 3 },
		{ "To", 2 },
		{ "Welcome", 1 } };

	// Function Call
	sort(M);
	return 0;
}
