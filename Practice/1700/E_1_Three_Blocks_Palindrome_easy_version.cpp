/*
      Author : ME
*/
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
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(ll i=0;i<n;i++){
        cin>>v[i+1];
    }

    vector<vector<ll>> dp(27,vector<ll> (n+1,0));
    
    for(ll i=1;i<=n;i++){
        dp[v[i]][i]++;
    }

    ll ans = 0;
    for(ll i=1;i<=26;i++){
        for(ll j = 1;j<=n;++j){
            dp[i][j] += dp[i][j-1];
            ans = max(ans,dp[i][j]);
        }
    }

    for(ll i = 1;i<=n;++i){
        for(ll j = i;j<=n;++j){
            ll center = 0,side = 0;
            for(ll k = 1;k<=26;++k){
                center = max(center,dp[k][j]-dp[k][i-1]);
                side = max(side,2*min(dp[k][i-1],dp[k][n]-dp[k][j]));
            }
            ans = max(ans,center+side);
        }
    }
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