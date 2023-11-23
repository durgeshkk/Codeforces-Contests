#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int

int main() {
    ll t;
    std::cin>>t;
    while(t--){int n, q;
    std::cin >> n >> q;

    // Initialize the array and the count array to store the frequency of powers of 2
    std::vector<long long> a(n);
    std::vector<long long> count(31, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        // Count the frequencies of each power of 2 in the initial array
        for (int j = 0; j <= 30; ++j) {
            if (a[i] % (1LL << j) == 0) {
                count[j]++;
            }
        }
    }

    // Process each modification query
    while (q--) {
        int x;
        std::cin >> x;

        // Update the array and the count array
        for (int j = 0; j <= 30; ++j) {
            if (count[j] > 0) {
                // Increase aj by 2^(x-1) for all aj divisible by 2^x
                a[j] += (1LL << (x - 1)) * count[j];
                count[j] = 0;
            }
        }
    }

    // Output the final array
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }}

    return 0;
}
