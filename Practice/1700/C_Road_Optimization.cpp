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

// 3-d DP :
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
    
}*/

// /*
ll recur(ll i,ll k,vector<vector<ll>> &dp,vector<ll> &sl,vector<ll> &dist,ll n){
    // prev : to store last idx included
    // So Q is of type 3-d DP now [remove][prev][idx]
    // But this will give MLE (500*500*500) :
    // Thus, try to convert into 2d..
    // k & remove r must required so try to remove prev wala part

    // So at each idx we have k options to delete..
    // e.g. at idx = 0, I can't delete any & reach idx=1
    // e.g. at idx = 0, I can delete idx=1 & reach idx=2
    // e.g. at idx = 0, I can delete idx=1,2 & reach idx=3
    // e.g. at idx = 0, I can delete idx=1,2,..,k & reach idx=k+1
    if(i == n){return 0;}

    if(dp[i][k] != -1){return dp[i][k];}

    ll ans = LLONG_MAX; 
    ll remove = 0,val = 0;
    for(ll j = i+1;j<=n;++j){
        if(j-i-1 > k){break;}//Elements in between them more than k
        val = (((dist[j]-dist[i])*sl[i])+recur(j,k-(j-i-1),dp,sl,dist,n));
        ans = min(ans,val);
    }

    return dp[i][k] = ans;
}
// */

void solve()
{
    ll n,l,k;
    cin>>n>>l>>k;
    vector<ll> v;
    for(ll i=0;i<n;i++){
        ll z;cin>>z;v.push_back(z);
    }v.push_back(l);

    vector<ll> speed_limit;
    for(ll i=0;i<n;i++){
        ll z;cin>>z;speed_limit.push_back(z);
    }speed_limit.push_back(0);

    /*
    // 3-d Dp :
    for(ll i = 0;i<501;++i){
        for(ll j = 0;j<501;++j){
            for(ll k = 0;k<501;++k){
                dp[i][j][k] = -1;
            }
        }
    }
    if(n == 1){
        cout<<l*speed_limit[0]<<endl;return;
    }

    // 3-d : 
    ll ans = dfs(0,k,0,0,speed_limit,v,n);
    cout<< ans <<endl;*/


    vector<vector<ll>> dp(n+5,vector<ll> (n+5,-1));

    if(n == 1){
        cout<<l*speed_limit[0]<<endl;return;
    }

    // ----> Recursion :
    ll ans = recur(0,k,dp,speed_limit,v,n);
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