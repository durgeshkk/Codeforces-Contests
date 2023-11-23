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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

// Iterate on man & Bitmask on women
vector<vector<ll>> v;
ll dp[21][1<<21];//[2][2^21]
ll recur(ll p,ll m,ll n){//p : man_id, m : bitmask
    ll &ans = dp[p][m];
    if(ans != -1){return ans;}

    // Iterate on all women & check if it compatible with pth men
    ans = 0;
    for(ll i = 0;i<n;++i){
        if(v[p][i]){//compatiblity check
            if((m & (1<<i)) == 0){//unpaired check, shifting women to the left,to check
                if(p == n-1){ans = 1;break;}
                // m^(1<<i) ==> pairing the women
                ans = ((ans+recur(p+1,m^(1<<i),n))%mod);
            }
        }
    }
    return ans;
}

void solve()
{
 
    ll n;cin>>n;
    v.assign(n,vector<ll> (n,0));
    for(ll i=0;i<n;i++){
        forj(n){
            cin>>v[i][j];
        }
    }

    for(ll i=0;i<21;i++){
        for(ll j = 0;j<(1<<21);++j){
            dp[i][j] = -1;
        }
    } 

    ll ans = recur(0,0,n);
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