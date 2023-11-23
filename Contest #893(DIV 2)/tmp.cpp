#include <bits/stdc++.h>
using namespace std;

int maxrun(string& s, char c) {
  int ans = 0;
  int cur = 0;
  for (char d: s) {
    if (c == d) ans = max(ans, ++cur);
    else cur = 0;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> pos(2);
    for (int i = 0; i < n; i++) {
      pos[s[i]-'0'].emplace_back(i);
    }
    vector<pair<int, int>> options;
    for (int z: {0, 1}) {
      int tk = min(k, (int)pos[z].size());
      for (int i = 0; i+tk<= (int)pos[z].size(); i++) {
        string t = s;
        for (int j = i; j < i+tk; j++) t[pos[z][j]] = '0'+1-z;
        options.emplace_back(maxrun(t, '0'), maxrun(t, '1'));
      }
    }
    for (int j = 1; j <= n; j++) {
      int best = 0;
      for (auto& [c0, c1]: options) best = max(best, j*c0+c1);
      cout << best << " \n"[j==n];
    }
  }
}
