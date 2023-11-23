#include <iostream>
#include <vector>
#include <cmath>
#include<bits/stdc++.h>

bool isPalindrome(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int findLargestPalindrome(const std::vector<int>& a) {
    int max_val = *max_element(a.begin(), a.end());
    int x = sqrt(max_val);

    while (x > 0) {
        std::vector<int> f_a;
        for (int val : a) {
            f_a.push_back(val % x);
        }

        if (isPalindrome(f_a)) {
            return x;
        }
        x--;
    }

    return -1;
}

int main() {
    // Example usage
    std::vector<int> a = {100, 1, 1000000000};
    int largestPalindrome = findLargestPalindrome(a);
    std::cout << "Largest palindrome x: " << largestPalindrome << std::endl;

    return 0;
}
