#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

map<pair<ll,ll>,ll> mp;
// 2 D Dp : TLE !!
ll recur(ll remain,ll cuts,ll n,ll a,ll b,ll c){
    if(remain <= 0){return cuts;}

    if(mp.find({remain,cuts}) != mp.end()){
        return mp[{remain,cuts}];
    }

    ll e = 0,f = 0,g = 0;
    if(remain-a >= 0){
        if(mp.find({remain-a,cuts+1}) != mp.end()){
            e = mp[{remain-a,cuts+1}];
        }else{
            e = recur(remain-a,cuts+1,n,a,b,c);
        }
    }

    if(remain-b >= 0){
        if(mp.find({remain-b,cuts+1}) != mp.end()){
            f = mp[{remain-b,cuts+1}];
        }else{
            f = recur(remain-b,cuts+1,n,a,b,c);
        }
    }

    if(remain-c >= 0){

        if(mp.find({remain-c,cuts+1}) != mp.end()){
            g = mp[{remain-c,cuts+1}];
        }else{
            g = recur(remain-c,cuts+1,n,a,b,c);
        }
    }

    return mp[{remain,cuts}] = max({e,f,g});
}

ll dp[4005];
ll tabulation(ll a,ll b,ll c,ll n){
    for(ll i = 1;i<=n;++i){
        dp[i] = LLONG_MIN;
        if(i >= a){
            dp[i] = max(dp[i],dp[i-a]+1);
        }
        if(i >= b){
            dp[i] = max(dp[i],dp[i-b]+1);
        }
        if(i >= c){
            dp[i] = max(dp[i],dp[i-c]+1);
        }
    }
    return dp[n];
}

void solve()
{
    mp.clear();
    ll n;cin>>n;
    ll a,b,c;cin>>a>>b>>c;
    // ll ans = recur(n,0,n,a,b,c);
    ll ans = tabulation(a,b,c,n);
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