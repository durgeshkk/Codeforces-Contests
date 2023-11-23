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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll adj[20][20];
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
ll n,m,k;
vector<ll> v,vis;
// map<pair<ll,ll>,ll> mp;
vector<vector<ll>> tmp,dp;

ll recur(ll lst,ll msk){
    if(__builtin_popcount(msk) == m){
        return 0;
    }

    ll &ans = dp[lst][msk];
    if(ans != -1){return ans;}
    ans = LLONG_MIN;

    forj(n){
        if(!((1<<j) & msk)){
            ll sa = recur(j,msk|(1<<j)) + v[j];
            // Check if already it's partner is done
            sa += adj[lst][j];
            ans = max(ans,sa);
        }
    }
    return ans;
}

void solve()
{
 
    cin>>n>>m>>k;
    v.assign(n,0);enter(v);
    vis.assign(n+1,0);
    
    for(ll i=0;i<k;i++){
        ll a,b,c;cin>>a>>b>>c;
        adj[--a][--b] = c;
    }

    dp.assign(20,vector<ll> (1<<n,-1));
    // show(tmp[0]);
    ll ans = recur(19,0);
    cout<<ans<<endl;
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