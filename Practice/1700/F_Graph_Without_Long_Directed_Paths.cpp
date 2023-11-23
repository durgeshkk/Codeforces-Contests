/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
vector<ll> adj[200004];
vector<ll> vis,dp; 
map<pair<ll,ll>,ll> mp;

bool dfs(ll i,ll f){
    vis[i] = 1;
    dp[i] = f;
    ll a = true;
    for(auto it:adj[i]){
        if(!vis[it]){
            a &= dfs(it,f^1);
            if(mp.find({i,it}) != mp.end()){
                mp[{i,it}] = 0;
            }else{
                mp[{it,i}] = 1;
            }
        }else{
            // if i have color 0, then child must have color 1
            // As child is already visited so check dp[it] if it have opposite color
            // to par or not
            if(dp[it]^f){
            }else{
                a = false;
            }
        }
    }
    return a;
}

void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}
 
void solve()
{
 
    ll n,ed;cin>>n>>ed;
    vis.assign(n+1,0);dp.assign(n+1,-1);
    vector<pair<ll,ll>> tmp;
    for(ll i=0;i<ed;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
        mp[{u,v}] = 0;
        tmp.push_back({u,v});
    }
    
    if(dfs(1,0)){
        yno(1);
        // return;
        string ans;
        for(auto &it:tmp){
            if(dp[it.first] == 0){
                ans += '0';
            }else{
                ans += '1';
            }
        }
        cout<<ans<<endl;
    }else{
        yno(0);
    }
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