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
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
#define MAX (ll)(2e5+4)
ll capacity[MAX];
ll curr_store[MAX];
ll next_ptr[MAX];
ll n;

ll recur(ll idx,ll wt){
    if(idx > n){
        return idx;
    }

    ll mn = min(wt,capacity[idx]-curr_store[idx]);
    wt -= mn;
    curr_store[idx] += mn;

    if(wt == 0){return idx;}
    return next_ptr[idx] = recur(next_ptr[idx],wt);
}

void solve()
{
 
    cin>>n;
    vector<ll> v(n+1,0);
    for(ll i = 1;i<=n;++i){
        cin>>capacity[i];}

    for(ll i = 1;i<=(n+1);++i){
        next_ptr[i] = (i+1);
        curr_store[i] = 0;
    }

    // vector<ll> pref(n+1,0);
    // pref[1] = v[0];
    // for(ll i=2;i<n;i++){pref[i] = pref[i-1] + v[i-1];}

    ll q;cin>>q;
    ll vol = 0;
    while(q--){
        ll a;cin>>a;
        if(a == 1){
            ll idx,x;cin>>idx>>x; 
            recur(idx,x);
            // vol += x;
        }else{
            ll idx;cin>>idx;
            // ll lb = lower_bound(pref.begin(),pref.end(),vol)-v.begin();
            cout<<curr_store[idx]<<endl;
        }
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}