#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll exch = n * (n - 1) / 2 - 1;
    ll req_exch = 0;

    int a[n];
    int b[n];
    set<ll> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
        s.insert(a[i]);
    }
    ll f = 0;
    sort(b, b + n, greater<int>());

    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            f = 1;
            // return;
        }
    }

    if (f == 0 && s.size() == n)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    return;
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
