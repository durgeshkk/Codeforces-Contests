#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

void solve()
{
 
    ll n;
    cin>>n;
    ll k;cin>>k;

    vector<ll> v(n);
    enter(v);
    
    vector<ll> pref(n);
    pref[0] = v[0];
    for(ll i=1;i<n;i++){
        pref[i] = v[i] + pref[i-1];
    }

    if(k >= n){
        ll val = pref[n-1];
        // ll dk = (((k-1)*(n-1))+val);
        ll dk = (((k-1)*(n))+val);
        ll ag = ((n)*(n-1)/2);
        ll ans = (dk-ag);
        cout<<ans<<endl;
    }
    // else if(k == n){
    //     cout<<pref[n-1]+(k-1)<<endl;
    // }
    else{
        ll mx = 0;
        ll l = 0;
        ll r = (k-1);
        ll sm = 0;
        for(ll i = l;i<=r;++i){
            sm += v[i];
        }
        mx = max(sm,mx);

        for(r;r<(n-1);){
            sm -= v[l];
            ++l;
            ++r;
            sm += v[r];
            mx = max(sm,mx);
        }
        ll ag = k*(k-1)/2;
        cout<<(mx+ag)<<endl;
    }

    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
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