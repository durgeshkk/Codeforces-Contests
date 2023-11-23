/*
      Author : ME
*/
#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

vector<ll> adj[200004];
vector<ll> vis;
set<ll> s;
ll dk,st;

pair<ll,pair<ll,ll>> recur(ll i){
    vis[i] = 1;

    // pair<ll,pair<ll,ll>> : {ans , {mila,f}}
    ll f = 0;
    ll ans = 0,mila = 0;
    if(s.find(i) != s.end()){mila = 1;}
    for(auto it:adj[i]){
        if(!vis[it]){
            auto small_ans = recur(it);
            ans += (small_ans.first);
            mila |= (small_ans.second.first);
            f |= (small_ans.second.second);
        }
    }

    if(i == st){f = 1;}
    if(i == dk){return {ans,{mila,f}};}
    if(mila & 1){
        if(f & 1){
            ans += 1;
        }else{
            ans += 2;
        }
    }else{
        if(f & 1){
            ans += 1;
        }
    }
    // cout<<i<<" "<<ans<<" "<<mila<<" "<<f<<endl;
    return {ans,{mila,f}};
}

void solve()
{
 
    ll n,k;cin>>n>>k;
    cin>>dk>>st;

    // Precompute stage:
    for(ll i = 1;i<=n;++i){
        adj[i].clear();
    }
    vis.assign(n+1,0);
    s.clear();
    
    // Indices to visit 1st to complete the work
    vector<ll> v(k);enter(v);
    for(ll i=0;i<k;i++){
        s.insert(v[i]);
    }
    // Tree Creation 
    for(ll i=1;i<n;i++){
        ll a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    auto ans = recur(dk);
    ll dynamo = ans.first;
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