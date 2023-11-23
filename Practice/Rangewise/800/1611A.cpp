#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    string s;
    cin >> s;

    int f = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            f = 1;
            break;
        }
    }

    if (f == 1)
    {
        if ((s[s.size() - 1] - '0') % 2 == 0)
        {
            cout << 0 << endl;
        }
        else if ((s[0] - '0') % 2 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    return;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}