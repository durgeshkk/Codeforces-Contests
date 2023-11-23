#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve()
{
    ll n;
    cin>>n;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<ll> vlk(n);
    for(ll i =0;i<n;i++){
        vlk[i] = v[i];
    }

    sort(vlk.begin(), vlk.end());

    vector<ll> vt;
    for (ll i = 0; i < n; i++)
    {
        if (vlk[i] != v[i])
        {
            vt.push_back(v[i]);
        }
    }

    if (vt.size()==0){
        cout << 0 << endl;
    }
    else{
        ll val = vt[0];

        for (ll i = 0; i < vt.size(); i++)
        {
            val = (val&vt[i]);
        }

        cout<<val<<endl;
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
    while (t != 0)
    {
        solve();
        t--;
    }
}