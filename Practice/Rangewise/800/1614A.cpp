#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll n;
    cin >> n;

    ll l, r, k;
    cin >> l >> r >> k;

    vector<ll> v;

    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        v.push_back(abs(ele));
    }

    sort(v.begin(), v.end());

    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        if ((l <= v[i]) && (v[i] <= r) && (k >= v[i]))
        {
            k -= v[i];
            count++;
        }
    }
    cout << count << endl;
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}