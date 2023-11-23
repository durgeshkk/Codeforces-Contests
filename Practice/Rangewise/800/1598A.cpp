#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{

    ll n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    /*
        for (ll i = 0; i < n; i++)
        {
            ll ele;
            cin >> ele;
            v.push_back(abs(ele));
        }
    */
    /*
     ll i = 0;
     while (i < n - 1)
     {
         if ((s1[i + 1] == '1') && (s2[i] == '1') && (s2[i + 1] == '1'))
         {
             cout << "NO\n";
             return;
         }
         else if ((s2[i + 1] == '1') && (s1[i] == '1') && (s1[i + 1] == '1'))
         {
             cout << "NO\n";
             return;
         }
         i++;
     }*/

    ll i = 0;
    while (i < n - 1)
    {
        if ((s2[i + 1] == '1') && (s1[i + 1] == '1'))
        {
            cout << "NO\n";
            return;
        }
        else if ((s1[i + 1] == '1') && (s2[i + 1] == '1'))
        {
            cout << "NO\n";
            return;
        }
        i++;
    }
    cout << "YES\n";
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