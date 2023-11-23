#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    // ll n;
    // cin >> n;

    ll sum;
    cin >> sum;

    ll l = -(sum - 1);
    ll r = sum;

    cout << l << " " << r << endl;
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