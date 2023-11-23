#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);
void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<char>> v(n + 1, vector<char>(m + 1));

    ll tot = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == '1')
            {
                tot += v[i][j] == '1';
            }
        }
    }

    ll ans = 0;
    ll mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i + 1 < n && j + 1 < m)
            {
                ll c1 = 0;
                c1 += v[i][j] == '1';
                c1 += v[i + 1][j] == '1';
                c1 += v[i + 1][j + 1] == '1';

                ll c2 = 0;
                c2 += v[i][j + 1] == '1';
                c2 += v[i][j] == '1';
                c2 += v[i + 1][j + 1] == '1';

                mn = min(mn, min(c1, c2));
            }
        }
    }
    
    if (mn <= 1)
    {
        cout << tot << endl;
        return;
    }

    ans = tot - (mn - 1);
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