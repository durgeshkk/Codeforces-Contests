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
 
vector<ll> dp(10001);
void update(){
    for (ll i = 0; i < dp.size(); i++){
        dp[i] = 1e9;
    }
    dp[1] = 0;

    // No. of operations req to get n
    for (ll i = 1; i <= 1000; i++){
        for (ll j = 1; j <= i; j++){
            if (i + i/j <= 1000){
                dp[i + i/j] = min(dp[i + i/j], dp[i] + 1);
            }
        }
    }
}

void solve()
{
 
    ll n,x;cin>>n>>x;
    vector<ll> b(n);enter(b);
    vector<ll> c(n);enter(c);
    vector<ll> opp(n);
    
    for(ll i=0;i<n;i++){
        opp[i] = dp[b[i]];
    }

    ll sm = accumulate(c.begin(),c.end(),0ll);
    ll val = accumulate(opp.begin(),opp.end(),0ll);
    if (val <= x){
        cout<<sm<<endl;
        return;
    }

    // Do by Tabulation as of in Max-Profit!!
    // 0-1 Knapsack type or simple memo DP

    // Fail 1:
    // thinking of memo DP will make it 3-D & will give TLE
    // ll ans = recur(v,n);

    // So go with Tabulation :
    vector<ll> memo(x+1,0);
    for(ll i = 1;i<n+1;++i){
        for(ll j = x;j>=0;--j){
            if(opp[i-1] <= j){
                memo[j] = max(memo[j],memo[j-opp[i-1]]+c[i-1]);
            }
        }
    }


    ll ans = 0;
    for(auto it:memo){
        ans = max(ans,it);
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
 
    update();
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}