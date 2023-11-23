#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;

unsigned countBits(unsigned int number)
{

    // log function in base 2
    // take only integer part
    return (int)log2(number) + 1;
}

void solve()
{
    ll n;
    cin >> n;
    ll i = 0;
    ll ans = 0;
    ll st = 0;
    while (n > 0)
    {
        st += pow(2, i);
        ll t = st * (st + 1) / 2;
        n -= t;
        if (n >= 0)
        {
            ans++;
        }
        else
        {
            break;
        }
        i++;
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