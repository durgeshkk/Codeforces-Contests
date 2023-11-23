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
 
void recur(vector<ll> &v,ll i,ll n){
    if(i >= n){return;}

    // show(v);
    if(v[i] > 1){
        recur(v,v[i]+i,n);
        --v[i];
    }
    return;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    ll ans = 0;
    vector<ll> dp(n+1,0);
    for(ll i=0;i<n;i++){
        if((v[i]) <= 1){continue;}
        else{
            ll z = min(n,v[i]+i+1);
            for(ll j = i+2;j<z;++j){
                dp[j] += 1;
            }
        }
    }

    for(ll i = 0;i<n;++i){
        if((v[i]-dp[i]) > 1){
            ans += (v[i]-dp[i]-1);
        }else{
            // If it already became 1 then it will move to next trampoline by default
            ll extra = ((dp[i])-(v[i]-1));
            dp[i+1] += (extra);
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