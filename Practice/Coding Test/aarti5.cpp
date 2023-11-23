// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;

// Function to find the sum of first
// N natural numbers represented
// in binary representation
void sumOfBinaryNumbers(int n)
{
	// Stores the resultant sum
	int ans = 0;

	int one = 1;

	// Iterate until the value of
	// N is greater than 0
	while (1) {

		// If N is less than 2
		if (n <= 1) {
			ans = (ans + n) % MOD;
			break;
		}

		// Store the MSB position of N
		int x = log2(n);

		int cur = 0;
		int add = (one << (x - 1));

		// Iterate in the range [1, x]
		// and add the contribution of
		// the numbers from 1 to (2^x-1)
		for (int i = 1; i <= x; i++) {

			// Update the value of the
			// cur and add
			cur = (cur + add) % MOD;
			add = (add * 10 % MOD);
		}

		// Add the cur to ans
		ans = (ans + cur) % MOD;

		// Store the remaining numbers
		int rem = n - (one << x) + 1;

		// Add the contribution by MSB
		// by the remaining numbers
		int p = pow(10, x);
		p = (p * (rem % MOD)) % MOD;
		ans = (ans + p) % MOD;

		// The next iteration will
		// be repeated for 2^x - 1
		n = rem - 1;
	}

	// Print the result
	cout << ans<<endl;
}

// Driver Code
int main()
{
    ll tt;
    cin>>tt;
    while(tt--){
	    // int N = 3;
        ll n;
        cin>>n;
	    sumOfBinaryNumbers(n);
    }

	return 0;
}
