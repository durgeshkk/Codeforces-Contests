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

vector<vector<ll>> dp;
/*
ll recur(ll j,vector<ll> a,vector<ll> b){
    if(j >= a.size()){
        return LLONG_MAX;
    }

    // if(dp[j] != -1){
    //     return dp[j];
    // }

    ll sma = 0,smb = 0;
    for(ll i = 0;i<a.size();++i){
        sma += a[i];
        smb += b[i];
    }

    ll tmpa = sma,tmpb = smb;
    ll vala = 0,valb = 0,val2 = 0;

    // Not Swap
    for(ll i = 0;i<a.size();++i){
        sma -= a[i];
        vala += (sma*a[i]);
        smb -= b[i];
        vala += (smb*b[i]);
    }
    ll y = min(vala,(recur(j+1,a,b)));

    // Swap
    sma = tmpa,smb = tmpb;
    sma -= a[j];sma += b[j];
    smb -= b[j];smb += a[j];
    swap(a[j],b[j]);
    for(ll i = 0;i<a.size();++i){
        sma -= a[i];
        val2 += (sma*a[i]);
        smb -= b[i];
        val2 += (smb*b[i]);
    }
    ll x = min(val2,(recur(j+1,a,b)));

    return dp[j] = min(x,y);
}
*/
ll dfs(ll j,ll pref_sma,ll pref_smb,vector<ll> a,vector<ll> b){
    if(j >= a.size()){
        return 0;
    }

    if(dp[j][pref_sma] != -1){
        return dp[j][pref_sma];
    }

    // No swap
    ll x = a[j]*pref_sma+b[j]*pref_smb+dfs(j+1,pref_sma+a[j],pref_smb+b[j],a,b);
    // Swap
    ll y = a[j]*pref_smb+b[j]*pref_sma+dfs(j+1,pref_sma+b[j],pref_smb+a[j],a,b);

    return dp[j][pref_sma] = min(x,y);
}

void solve()
{
 
    ll n;cin>>n;
    dp.assign(n+1,vector<ll> (n*101,-1));
    vector<ll> a(n);enter(a);
    vector<ll> b(n);enter(b);
    ll sma = 0,smb = 0,dynamo = 0;
    for(ll i=0;i<n;i++){
        sma += a[i];
        smb += b[i];
        dynamo += (a[i]*a[i] + b[i]*b[i]);
    }
    dynamo *= (n-1);

    ll ans = dfs(0,0,0,a,b);
    ans *= 2;
    dynamo += ans;
    cout<<dynamo<<endl;
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