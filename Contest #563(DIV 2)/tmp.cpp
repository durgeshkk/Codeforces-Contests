// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum length array
void maxLengthArr(int x, int y)
{
	// To store if an element is
	// already taken or not
	bool ex[(1 << x)];

	// To store visited numbers
	ex[0] = 1;
	vector<int> pre({ 0 });

	// For all possible values of pre[]
	for (int i = 1; i < (1 << x); i++) {

		// If it is already taken
		if (ex[i ^ y])
			continue;

		pre.push_back(i);
		ex[i] = 1;
	}

	// Not possible
	if (pre.size() == 1) {
		cout << "-1";
		return;
	}

	// Print the array constructing it
	// from the prefix-xor array
	for (int i = 1; i < pre.size(); i++)
		cout << (pre[i] ^ pre[i - 1]) << " ";
}

// Driver code
int main()
{
	int X = 17, Y = 262143;

	maxLengthArr(X, Y);

	return 0;
}
