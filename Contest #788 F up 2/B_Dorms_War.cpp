#include <bits/stdc++.h>
#define ll long long int
#include <iomanip>
using namespace std;
 
void solve()
{
    ll n;
    cin >> n;
 
    string s;
    cin >> s;

    ll t;
    cin >> t;
    map<char, ll> mp;
    ll idx = -1;
    for (ll i = 0; i < t; i++)
    {
        char r;
        cin >> r;
        mp[r]++;
    }

    ll z = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            ans = max(ans,i-z);
            z = i;
        }
    }

    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
 
    while (t--)
    {
        solve();
    }
}