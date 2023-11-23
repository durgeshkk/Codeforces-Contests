#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll count_subsequences(vector<ll>& a, ll k) {
    ll n = a.size();
    ll m = 0;
    for (ll x : a) {
        m = max(m, (ll)log2(x) + 1);
    }

    vector<vector<ll>> dp(n+1, vector<ll> (1<<m,0));

    // Base case: empty subsequence has bitwise AND equal to 0
    dp[0][0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < (1<<m); j++) {
            dp[i][j] = dp[i-1][j];
            if ((j & a[i-1]) == j) {
                dp[i][j] += dp[i-1][j & a[i-1]];
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j < (1<<m); j++) {
        if (__builtin_popcount(j) == k) {
            ans += dp[n][j];
        }
    }
    return ans;
}

signed main() {
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> a(n);
        for(ll i = 0;i<n;++i){
            cin>>a[i];
        }

        cout << count_subsequences(a, k) << endl;  // Output: 5
    }
    return 0;
}
