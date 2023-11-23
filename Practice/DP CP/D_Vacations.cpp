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

/*
1. No same task on consecutive day
2.
i.   on this day the gym is closed and the contest is not carried out;
ii.  on this day the gym is closed and the contest is carried out;
iii. on this day the gym is open and the contest is not carried out;
iv.  on this day the gym is open and the contest is carried out.

n is too small go with dp
4-D DP also good to go
*/
 
// i => 1-n ; prev => 0-2   ----> n*3 
map<pair<ll,ll>,ll> dp; 
ll recur(ll i,vector<ll> &v,ll prev){
    if(i == v.size()){
        return 0;
    }

    if(dp.find({i,prev}) != dp.end()){
        return dp[{i,prev}];
    }

    ll a = LLONG_MAX,b = LLONG_MAX,c = LLONG_MAX;
    ll d = LLONG_MAX,e = LLONG_MAX,f = LLONG_MAX;
    ll g = LLONG_MAX,h = LLONG_MAX;

    if(prev == 0){//All pssbl
        if(v[i] == 0){//Rest
            a = 1 + recur(i+1,v,0);
        }else if(v[i] == 1){
            // Contest or Rest
            b = recur(i+1,v,2);
            c = 1 + recur(i+1,v,0);
        }else if(v[i] == 2){
            // Gym or Rest
            d = recur(i+1,v,1);
            e = 1 + recur(i+1,v,0);
        }else{
            f = recur(i+1,v,2);
            g = recur(i+1,v,1);
            h = 1 + recur(i+1,v,0);
        }
    }
    else if(prev == 1){
        // Can't do Gym
        if(v[i] == 0 || v[i] == 2){//Rest
            a = 1 + recur(i+1,v,0);
        }else if(v[i] == 1){
            // Contest or Rest
            b = recur(i+1,v,2);
            c = 1 + recur(i+1,v,0);
        }else{
            // Gym,Contest,Rest all pssbl
            d = recur(i+1,v,2);
            e = 1 + recur(i+1,v,0);
        }   
    }
    else if(prev == 2){
        // No Contest 
        if(v[i] == 0 || v[i] == 1){//Rest
            a = 1 + recur(i+1,v,0);
        }else if(v[i] == 2){
            // Gym or Rest
            b = recur(i+1,v,1);
            c = 1 + recur(i+1,v,0);
        }else{
            // Gym,Contest,Rest all pssbl
            d = recur(i+1,v,1);//Gym
            e = 1 + recur(i+1,v,0);//Rest
        }   
    }

    return dp[{i,prev}] = min({a,b,c,d,e,f,g,h});
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    // Memoization:
    // ll ans = recur(0,v,0);
    // cout<<ans<<endl;

    // Tabulation/Iterative DP :
    /*
    0-> Rest    1-> Contest     2-> Sport
    */
    vector<vector<ll>> mp(n+1,vector<ll>(3,0));//{pos,last day}
    mp[0][0] = 0;//No Rest till 0th day
    mp[0][1] = 0;
    mp[0][2] = 0;

    for(ll i = 1;i<=n;++i){
        // rest today
        mp[i][0] = 1+min({mp[i-1][0],mp[i-1][1],mp[i-1][2]});
        // Contest today when v[i] is odd
        if(v[i-1] & 1){
            mp[i][1] = min({mp[i-1][0],mp[i-1][2]});
        }else{
            mp[i][1] = LLONG_MAX;
        }

        // Sport today
        if(v[i-1]/2 == 1){
            mp[i][2] = min({mp[i-1][0],mp[i-1][1]});
        }else{
            mp[i][2] = LLONG_MAX;
        }
    }
    ll ans = min({mp[n][0],mp[n][1],mp[n][2]});
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