#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int maxBeautySubsequences(string s, int k) {
    unordered_map<char, int> charFreq;
    for (char c : s) {
        charFreq[c]++;
    }

    vector<int> freqList;
    for (auto it = charFreq.begin(); it != charFreq.end(); ++it) {
        freqList.push_back(it->second);
    }

    sort(freqList.rbegin(), freqList.rend());

    int maxBeauty = 0;
    for (int i = 0; i < k; ++i) {
        maxBeauty += freqList[i];
    }
    cout<<maxBeauty<<endl;
    int count = 0;
    for (int i = 0; i < freqList.size(); ++i) {
        if (freqList[i] == freqList[k - 1]) {
            count++;
        } else {
            break;
        }
    }

    // Calculate the number of ways to choose k characters from the group
    long long ans = 1;
    for (int i = 0; i < k; ++i) {
        ans *= (count - i);
        ans /= (i + 1);
    }

    return ans % MOD;
}

int main() {
    cout << maxBeautySubsequences("bcca", 2) << endl;  // Output: 4
    cout << maxBeautySubsequences("abbcd", 4) << endl;  // Output: 2

    return 0;
}
