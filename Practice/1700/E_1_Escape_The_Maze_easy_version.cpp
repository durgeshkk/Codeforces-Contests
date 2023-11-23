/*
    --> Author : daddy_dynamo
*/
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
 
vector<ll> adj[200004];
vector<ll> vis,dp,leaf;

ll dfs(ll i){
    ll flag = 0;
    vis[i] = 1;
    ll mn = dp[i];
    for(auto it:adj[i]){
        if(!vis[it]){
            ll val = dfs(it);
            if(val == LLONG_MAX){
                val = LLONG_MAX-1;
            }
            mn = min(mn,val+1);
            flag = 1;
        }
    }

    if(flag == 0){
        leaf[i] = 1;
    }

    return dp[i] = (mn);
}

bool check_dfs(ll i,ll move){
    vis[i] = 1;

    if(move >= dp[i]){
        return false;
    }

    if((move < dp[i]) and (leaf[i] == 1)){
        return true;
    }

    bool b = false;
    for(auto it:adj[i]){
        if(!vis[it]){
            b |= check_dfs(it,move+1);
        }
    }
    return b;
}

void solve()
{
 
    ll n,frnd;cin>>n>>frnd;
    for(ll i = 1;i<=n;++i){
        adj[i].clear();
    }

    vis.assign(n+1,0);
    dp.assign(n+1,LLONG_MAX);
    leaf.assign(n+1,0);

    for(ll i=0;i<frnd;i++){
        ll x;cin>>x;
        dp[x] = 0;
    }

    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(ll i = 1;i<=n;++i){
        // cout<<adj[i].size()<<endl;
        // if(adj[i].size() == 1){leaf[i] = 1;}
    // }

    /*
    for(ll i = 1;i<=n;++i){
        cout<<i<<" -> ";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }cout<<endl;
    }
    cout<<endl;*/
    dfs(1);
    // show(dp);
    // show(leaf);
    // return;

    vis.assign(n+1,0);
    ll flag = check_dfs(1,0);// checking if he can reach correct to any leaf
    if(flag & 1){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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