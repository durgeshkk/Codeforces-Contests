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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
ll n,h,l,r;
vector<ll> v;
vector<vector<ll>> dp;
ll recur(ll idx,ll tym){
    if(idx == n){
        return 0;
    }

    if(dp[idx][tym] != -1){
        return dp[idx][tym];
    }

    ll a = 0,b = 0;

    // Sleep after Ai hours
    ll y = tym+v[idx];
    y%=h;
    if(y >= l and y <= r){
        a += 1;
    }
    a += recur(idx+1,y);

    // Sleep after Ai-1 hours
    y += (h-1); 
    y %= h;
    if(y >= l and y <= r){
        b += 1;
    }
    b += recur(idx+1,y);
    return dp[idx][tym] = max(a,b);
} 

void solve()
{
 
    cin>>n>>h>>l>>r;
    v.assign(n,0);
    enter(v);
    dp.assign(n+1,vector<ll> (h+1,-1));
    cout<<recur(0,0)<<endl;
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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