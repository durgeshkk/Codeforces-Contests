#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{

    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    vector<pair<ll, ll>> vp;
    vector<bool> vis(n + 1);
    vector<ll> v(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> t;
    vector<pair<ll, ll>> e;
    vector<pair<ll, ll>> o;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        vp.push_back({a, b});
        if (mp.find(a) == mp.end())
        {
            sum += v[a - 1];
        }
        if (mp.find(b) == mp.end())
        {
            sum += v[b - 1];
        }
        mp[a]++;
        mp[b]++;
    }

    if (m % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        ll ans = sum;
        for (ll i = 0; i < m; i++)
        {
            ll fi = vp[i].first;
            ll se = vp[i].second;
            ll t = m;
            t -= mp[fi];
            if (t % 2 == 0)
            {
                ans = min(ans, v[fi - 1]);
            }
            t = m;
            t -= mp[se];
            if (t % 2 == 0)
            {
                ans = min(ans, v[se - 1]);
            }
            t = m;
            t -= mp[fi] + mp[se] - 1;
            if (t % 2 == 0)
            {
                ans = min(ans, v[se - 1] + v[fi - 1]);
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}