#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int q;
    cin >> q;
    int f = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]] = i + 1;
    }

    for (int i = 0; i < q; i++)
    {
        int r,a,b;
        cin >> r >> a >> b;

        if (r == 1)
        {
            f = !f;
        }
        else if (r == 2)
        {
            
            if (f){
                int a1 = n - a + 1;
                int b1 = n - b + 1;
                mp[v[a1 - 1]] = b1;
                mp[v[b1 - 1]] = a1;
                swap(v[a1 - 1], v[b1 - 1]);
            }
            else
            {
                mp[v[a - 1]] = b;
                mp[v[b - 1]] = a;
                swap(v[a - 1], v[b - 1]);
            }
        }
        else
        {
            if (f)
            {
                cout << n - mp[a] + 1 << endl;
            }
            else
            {
                cout << mp[a] << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while (t--)
    {
        solve();
    }

    return 0;
}