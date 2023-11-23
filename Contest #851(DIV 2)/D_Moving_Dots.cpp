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
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

vector<ll> v;
ll dp[3001][3001][6];
// vector<vector<vector<ll>>> dp;
ll recur(ll idx,ll prev,ll dist){
    if(idx == v.size()){
        return 0;
    }

    if(dp[idx][prev][dist] != -1){
        return dp[idx][prev][dist];
    }

    ll b = recur(idx+1,prev,dist);

    // idx will check where prev was moving
    ll a = 0;
    if(dist < (v[idx]-v[prev])){
        a = 1+recur(idx+1,idx,v[idx]-v[prev]);
        a %= mod;
    }

    ll sm = mod_add(a,b,mod);
    return (sm);
}

/*
Everytime consider 2 dots i & j
This will produce ans for it's all subsequences only when i & j are moving 
near each other..
Dist. between i & j ; x = (v[j]-v[i])
This is pssbl only when, we select elements from left of i, whose distance from i
is greater than dist x
Assume the point to be k : v[i]-v[k] > v[j]-v[i]
So, left ans = 2*v[i]-v[j] > v[k]  
==> We know v[i] & v[j] and need to find v[k], this can be found by getting lower
bound from left vector.. As we need all ele less than this inequality
==> No != since equality will ask i to move right

Similarly on right we will select elements having dist greater than x
v[k]-v[j] >= v[j]-v[i] 
==> v[k] >= 2*v[j]-v[i]  ==> Lower_Bound
So, dots in right will be n-lower_bound
Ans = 2^(la+ra);
*/

vector<ll> pow2(6001);
// Precompute power of 2
void precompute(){
    pow2[0] = 1;
    for(ll i = 1;i<=6000;++i){
        pow2[i] = 2*pow2[i-1];
        pow2[i] %= mod;
    }
}

void solve()
{
 
    ll n;cin>>n;
    v.assign(n,0);enter(v);

    ll ans = 0;
    for(ll i = 0;i<n;++i){
        for(ll j = i+1;j<n;++j){
            // i & j are the dots resulting in the ans
            ll la = lower_bound(v.begin(),v.end(),2*v[i]-v[j]) - v.begin();
            ll ra = lower_bound(v.begin(),v.end(),2*v[j]-v[i]) - v.begin();
            ra = n-ra;
            ll sa = pow2[la+ra];
            ans = mod_add(ans,sa,mod);
        }
    }
    cout<<ans<<endl;
    /*
    ll mx=  *max_element(v.begin(),v.end());
    // dp.assign(n+1,vector<ll> (n+1, vector<ll> (mx+1,-1)));
    for(ll i=0;i<n;i++){
        forj(n){
            for(ll k = 0;k<mx;++k){dp[i][j][k] = -1;}
        }
    }

    ll ans = recur(0,0,LLONG_MAX);
    cout<<ans<<endl;*/
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   precompute();
 
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