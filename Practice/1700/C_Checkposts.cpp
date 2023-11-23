/*
      Author : ME
      Learning : KosaRaju's Algorithm
*/
#include<bits/stdc++.h>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

vector<ll> adj[100004];
vector<ll> rev_adj[100004];
vector<ll> vis,rev_vis;
stack<ll> rec_stack;
 
void dfs(ll i){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
    rec_stack.push(i);
}

void raju(ll i,vector<ll> &comp){
    rev_vis[i] = 1;
    comp.push_back(i);
    for(auto it:rev_adj[i]){
        if(!rev_vis[it]){
            raju(it,comp);
        }
    }
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    ll m;cin>>m;
    for(ll i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    vis.assign(n+1,0);rev_vis.assign(n+1,0);
 
    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    vector<vector<ll>> components;
    while(!rec_stack.empty()){
        ll ele = rec_stack.top();rec_stack.pop();
        if(!rev_vis[ele]){
            vector<ll> comp;// Components
            raju(ele,comp);
            components.push_back(comp);
        }
    }

    ll price = 0,posts = 1;
    for(auto it:components){
        ll mn = LLONG_MAX,cnt = 0;
        for(auto x:it){
            mn = min(mn,v[x-1]);
        }
        for(auto x:it){
            if(v[x-1] == mn){++cnt;}
        }
        price += mn;
        posts = mod_mul(posts,cnt,mod);
    }
    cout<<price<<" "<<posts<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
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