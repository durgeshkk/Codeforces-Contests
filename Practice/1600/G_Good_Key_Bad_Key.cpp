#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

ll asaka = LLONG_MIN;
ll dk(ll i,vector<ll> &v,ll p,ll k,ll n,ll sm){

    ll z = pow(2,p);
    if(z > 1e9){
        return LLONG_MIN;
    }

    if(i == n){
        return max(asaka,sm);
        // cout<<"HI ";
        // return LLONG_MIN;
    }

    ll aka= sm;

    ll a = LLONG_MIN;
    sm += ((v[i]/z) -k);
    a = dk(i+1,v,p,k,n,sm);

    ll b = LLONG_MIN;
    z = pow(2,p+1);
    aka += (v[i]/z);
    b = dk(i+1,v,p+1,k,n,aka);

    return max(a,b);
}


ll dkmemo(ll i,vector<ll> &v,ll p,ll k,ll n,ll sm,vector<vector<ll>> &dp){

    ll z = pow(2,p);
    if(z > 1e9){
        return LLONG_MIN;
    }

    if(i == n){
        return max(asaka,sm);
    }

    if(dp[i][p] != -1){
        return dp[i][p];
    }

    ll aka= sm;

    ll a = LLONG_MIN;
    sm += ((v[i]/z) -k);
    a = dk(i+1,v,p,k,n,sm);

    ll b = LLONG_MIN;
    z = pow(2,p+1);
    aka += (v[i]/z);
    b = dk(i+1,v,p+1,k,n,aka);

    return dp[i][p] = max(a,b);
}


void solve()
{
 
    ll n;
    cin>>n;

    ll k;
    cin>>k;

    vector<ll> v(n);
    enter(v);
 
 /*
    ll p = 0;
    vector<vector<ll>> dp(n,vector<ll> (n,-1));
    // ll ag = dk(0,v,p,k,n,0);
    ll ag = dkmemo(0,v,p,k,n,0,dp);
    cout<<ag<<endl;
*/

    // Optimal to have GK first then BK : 
    ll sm = 0;
    ll ans = LLONG_MIN;
    for(ll i = 0;i<n;++i){
        ll dk = sm - (i*k);
        ll j = i;

        ll c = 1;
        ll ag = 0;
        while(j<n and c<30){
            ag += (v[j]/(1<<c));
            ++c;
            ++j;
        }
        sm += v[i];
        ans = max(dk+ag,ans);
    }
    ans = max(ans,sm-(n*k));
    cout<<ans<<endl;
    return;
}
 
int main()
{
    fastio;
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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