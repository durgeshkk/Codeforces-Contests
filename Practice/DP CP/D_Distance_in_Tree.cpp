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

vector<ll> adj[100004];
 
/*
DP on Trees :
My Obs :
-> All nodes will be at dist 'k' from node i ,iff,
    node & i in same subtree -> node must be at lvl => k-lvl[i]
    node & i in different subtree -> node must be at lvl => k+lvl[i]

TC expected = O(nk)

dp[x][y] stores path starting from x & having length y
x <= n and y<= k so nk states total

dp[par][k] = summation(dp[child][k-1]), k-1 since 1 edge from par to child
*/

vector<ll> vis,lvl,chottu_vis;
map<ll,set<ll>> mp;
void bfs(){
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    ll level = 0;
    while(!q.empty()){
        ll sz = q.size();
        while(sz > 0){
            ll ele = q.front();q.pop();lvl[ele] = level;mp[level].insert(ele);
            for(auto it:adj[ele]) {if(!vis[it]){q.push(it);vis[it] = 1;}}
            --sz;
        }
        ++level;
    }
    return;
}

ll k;
/*
void dfs(ll i){
    vis[i] = 1;
    chottu_vis[i] = 1;

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }

    if(lvl[i] >= k){
        // Same Subtree Test :
        ll l = (lvl[i]-k);
        for(auto it:mp[l]){
            if(chottu_vis[it] and vis[it]){
                dp[it] += 1;
            }
        }
    }

    if(lvl[i]+1 >= k){
        // Different Subtree Test :
        ll l = (lvl[i]-k+1);
        for(auto it:mp[l]){
            if((!chottu_vis[it]) and (!vis[it])){
                dp[it] += 1;
            }
        }
    }

    

    chottu_vis[i] = 0;
    return;
}
*/
ll dp[50005][505];
ll ans = 0;
void dfs(ll i,ll par){
    dp[i][0] = 1;// 1 self edge of len = 0,i.e., 1 path of len = 0

    for(auto it:adj[i]){
        if(it == par){continue;}
        dfs(it,i);

        for(ll j = 0;j<k;++j){
            // dp[it][j] child se at dist j
            // dp[i][k-j-1] par se at dist k-j
            // par to child at dist 1
            ans += dp[it][j]*dp[i][k-j-1];//k-j-1,-1 for par to child edge   
        }

        for(ll j = 0;j<k;++j){
            // dp[par][k] = summation(dp[child][k-1]), k-1 since 1 edge from par to child
            dp[i][j+1] += dp[it][j];
        }
    }
    return;
}

void solve()
{
    vis.clear();mp.clear();lvl.clear();chottu_vis.clear();
    // dp.clear();
    
    ll n;cin>>n;cin>>k;
    for(ll i=1;i<=n;i++){adj[i].clear();}
    for(ll i=1;i<n;i++){ll u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
    vis.assign(n+1,0);lvl.assign(n+1,0);
    chottu_vis.assign(n+1,0);
    // dp.assign(n+1,0);
    bfs();
    vis.clear();vis.assign(n+1,0);
    dfs(1,-1);
    // show(lvl);
    // ll ans = accumulate(dp.begin(),dp.end(),0ll);
    cout<<ans<<endl;
    // show(dp);
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