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

// ll dp[501][501][501];
map<pair<ll,ll>,ll> dp;
vector<ll> v;
ll n,k;

ll recur(ll i,ll skipped){

    if(i == n){
        return 0;
    }

    if(dp.find({i,skipped}) != dp.end()){
        return dp[{i,skipped}];
    }

    if(skipped == k){
        return dp[{i,skipped}] = (v[i] + skipped + recur(i+1,skipped));
    }else{
        // Agar skip kiya toh damage uska 0!!
        return dp[{i,skipped}] = min(v[i] + skipped + recur(i+1,skipped),recur(i+1,skipped+1));
    }
}
/*
ll dp[501][501][501];
ll dfs(ll i,ll k,ll prev,ll remove,vector<ll> &sl,vector<ll> &dist,ll n){
 
    if(i == n){
        return ((dist[n]-dist[prev])*sl[prev]);
    }
 
    if(dp[i][remove][prev] != -1){
        return dp[i][remove][prev];
    }
 
    if(remove == k){
        // Go with Keep
        return dp[i][remove][prev] = ((dist[i]-dist[prev])*sl[prev]) + (dfs(i+1,k,i,remove,sl,dist,n));
    }else{
        // min(Keep,Remove) 
        return dp[i][remove][prev] = min(((dist[i]-dist[prev])*sl[prev]) + (dfs(i+1,k,i,remove,sl,dist,n)),(dfs(i+1,k,prev,remove+1,sl,dist,n)));
    }   
 
}
*/
void solve()
{
    dp.clear();
    cin>>n>>k;
    v.assign(n,0);
    enter(v);
    // TLE : Dp solution as n = 1e5 & k = 1e5
    // So TC = 1e10 > 1e8!! Thus, TLE!!!
    // ll ans = recur(0,0);
    // cout<<ans<<endl;

    // Greedy :
    // Each skip at i, increases pending no. of ele by 1
    // If a3 is skipped from 9 ele : 1 increment in (a4 to a9) : 6 ==> (n-i)!!
    // Yane at each position if we r skipping any element, then upcoming cost is
    // increased by (n-i)...
    // Implies, we removed a[i] but added (n-i)!!
    // expression : a[i]-(n-i) //1 based idx
    // If, they have (k-j) pending traps ahead,so
    // Expr : a[i]-(n-i)+(k-j)
    // And this, (k-j) ranging j from [1,k], will make ans as of (k*(k-1))/2;
    // (k*(k-1))/2; fixed value to be removed & simply I need to maximise,
    // a[i]-(n-i) part!!! This is the removal part, and I'll choose the max. elements
    // to get the damage min. as this is removal part!!


    multiset<ll> ms;
    for(ll i = 0;i<n;++i){
        ms.insert(v[i]-n+i+1);
    }

    // Removal Part {Fixed}
    ll ans = k*(k-1)/2;

    // Removal Part {Remove Max.}
    while(k--){
        auto p = *ms.rbegin();
        ms.erase(ms.find(p));
        ans += p;
    }

    ll sm = accumulate(v.begin(),v.end(),0ll);// total part
    sm -= ans;
    cout<<sm<<endl;
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