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

map<pair<ll,ll>,ll> mp;
ll recur(ll i,vector<ll> &a,vector<ll> &b,ll f){
    if(i == a.size()){
        return 0;
    }

    if(mp.find({i,f}) != mp.end()){return mp[{i,f}];}

    ll d = LLONG_MIN,e = LLONG_MIN,c = LLONG_MIN,fl = LLONG_MIN;
    if(f & 1){
        // Pick from team A or ignore
        d = a[i] + recur(i+1,a,b,0);
        e = recur(i+1,a,b,1);
    }else{
        // Pick from team B or ignore
        fl = b[i] + recur(i+1,a,b,1);
        c = recur(i+1,a,b,0);
    }

    return mp[{i,f}] = max({c,d,e,fl});
}

void solve()
{
    mp.clear();
    ll n;cin>>n;
    vector<ll> a(n);enter(a);
    vector<ll> b(n);enter(b);
    
    // Recursive DP :
    // ll ans = recur(0,a,b,0);
    // ans = max(ans,recur(0,a,b,1));
    // cout<<ans<<endl;

    // Iterative DP :
    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
    for(ll i = 1;i<=n;++i){
        dp[i][0] = max(a[i-1] + dp[i-1][1],dp[i-1][0]);
        dp[i][1] = max(b[i-1] + dp[i-1][0],dp[i-1][1]);
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
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