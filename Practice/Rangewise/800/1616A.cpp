#include <bits/stdc++.h>
#include <deque>
#define ll long long int
using namespace std;

void solve()
{
    // ll count_repeat=0;

    ll n;
    cin>>n;

    vector<ll> v;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++){
        ll ele;
        cin>>ele;
        v.push_back(abs(ele));
        if(ele == 0){
            mp[0] = 1;
            continue;
        }

        mp[v[i]]++;
    }

    ll ans=0;

    for(auto i=mp.begin();i != mp.end();i++){
        if((i->second) >= 2){
            ans += 2;
        }
        else if((i->second) == 1){
            ans+=1;
        }
    }
    cout<<ans<<endl;
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