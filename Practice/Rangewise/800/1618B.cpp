#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    ll size;
    cin >> size;

    vector<string> v;
    for (ll i = 0; i < size - 2; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int f = 0;
    string s;
    s += v[0][0];
    for (ll i = 0; i < v.size() - 1; i++)
    {
        if (v[i][1] != v[i + 1][0])
        {
            f = 1;
            s += v[i][1];
            s += v[i + 1][0];
        }
        else
        {
            s += v[i][1];
        }
    }
    s += v[v.size() - 1][1];
    if (f == 0)
    {
        s += v[v.size() - 1][1];
    }
    cout << s << endl;
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