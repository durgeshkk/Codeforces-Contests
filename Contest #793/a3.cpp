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

    ll mx = *max_element(v.begin(),v.end());
    ll mn = *min_element(v.begin(),v.end());

    if(n == 1){
        cout<<1<<endl;
        return;
    }


    map<ll,ll> mp;

    ll idx_mn = 0;
    for(ll i =0;i<n;i++){
        // if(v[i] == mx){
        //     mp[v[i]] = 1;
        // }
        // else{
            mp[v[i]]++;
        // }
    }

    // if(mp.size() == )

    ll dist=0,dupli=0;
    for(auto it:mp){
        // if(it.first == mx){
        //     continue;
        // }
        if(it.second == 1){
            dist++;
        }
        else if(it.second >= 2){
            dupli++;
        }
    }

    ll ans = 0;
    if(dist%2){
        ans = (dupli + (dist/2))+1;
    }
    else
    {
        ans = (dupli + (dist/2));
    }
    cout<<(ans)<<endl;
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