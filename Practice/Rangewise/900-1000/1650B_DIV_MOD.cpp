#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll l, r, a;
    cin >> l >> r >> a;

    ll ans = 0;

    ll ans_ind = r % a;

    if (l == r)
    {
        ans = (r / a) + (r % a);
        cout << ans << endl;
        return;
    }

    if ((r % a) == (a - 1))
    {
        ans = (r / a) + (r % a);
        cout << ans << endl;
    }
    else
    {
        // ans_ind++;
        if ((r - (ans_ind + 1)) >= l)
        {
            ans_ind++;
            ans = ((r - ans_ind) / a) + ((r - ans_ind) % a);
            cout << ans << endl;
        }
        else
        {
            ans = ((r) / a) + ((r) % a);
            cout << ans << endl;
        }
    }
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