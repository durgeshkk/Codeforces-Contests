#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll myceil(ll a, ll b)
{
    if (a % b == 0)
    {
        return a / b;
    }
 
    return a / b + 1;
}

void solve()
{
    ll n, d;
    cin >> n >> d;
    vector<vector<ll>> dk;
    vector<ll> ans(d);
    for(ll i = 0; i < d; i++){
        ll e;cin >> e;
        vector<ll> r;
        for(ll j = 0; j < e; j++){
           ll a;cin >> a;
           r.push_back(a);
        }
        dk.push_back(r);
    }

    ll len = 0;
    map<ll, ll> mp;
    ll t = myceil(d, 2);
    for(ll i = 0; i < d; i++){
        vector<ll> g = dk[i];
        if(g.size() == 1){
            mp[g[0]]++;
            ans[i] = g[0];
        }
        if(mp[g[0]] > t){
            cout<<"NO\n";
            return;
        }
    }

    for(ll i = 0; i < d; i++){
        vector<ll> k = dk[i];
        ll sz = k.size();
        if (sz == 1){
            continue;
        }
        for(ll j = 0; j < sz; j++){
            if(mp[k[j]] < t){
                ans[i] = k[j];
                mp[k[j]]++;
                break;
            }
        }
    }
    
    cout<<"YES\n";
    show(ans);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}