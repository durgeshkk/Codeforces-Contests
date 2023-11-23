#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> v(m);
    ll sum = 0;
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());
    ll ans = 0;
    for (ll i = 0; i <m;i++)
    {
        ll av = (sum) / (n - i);
        if (sum % (n - i))
        {
            av++;
        }
        if (av <= v[i])
        {
            ans = av;
            break;
        }
        sum-=v[i];
    }

    cout << ans << endl;
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