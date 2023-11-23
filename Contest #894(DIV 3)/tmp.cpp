#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _prll(x)
#else
#define debug(x...)
#endif
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()
#define endl '\n'
ll MOD = 1e9 + 7;

typedef vector<ll> vi;
typedef vector<long long> vl;
typedef vector<pair<ll, ll>> vpi;
typedef pair<ll, ll> pi;
typedef pair<long long, long long> pll;

void solve(ll tt)
{
    ll n, m, d;
    cin >> n >> m >> d;
    vi a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll s = 0;
    multiset<ll> mst;
    for (ll i = 0; i < n; i++)
    {
        if (mst.size() < m)
        {
            if (a[i] > 0)
            {
                mst.insert(a[i]);
                s += a[i];
                ans = max(ans, s - ((i + 1) * d));
            }
        }
        else
        {
            auto bgn = mst.begin();
            if(a[i] >= *bgn)
            {
                s += a[i];
                mst.insert(a[i]);
                s -= *bgn;
                mst.erase(mst.find(*bgn));
            }
            ans = max(ans, s - ((i + 1) * d));
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve(tt);
    }
}