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
Obs :
No Cycle ==> Source to dest only 1 path !!

1. Assume src -> dest, we get XOR = y
But We need XOR = 0 to enter b,
So traverse all vertices from src & store in some DS
Similarly traverse all vertices from dest & store in some DS
If there is anything common in both,then ans is YES
*/

void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

vector<ll> adj[100004]; 
map<pair<ll,ll>,ll> wt;
vector<ll> dist_src,dist_dest;
vector<ll> vis;

void dfs(ll i,ll xr,ll f){
    vis[i] = 1;
    if(f & 1){
        dist_src[i] = xr;
    }else{
        dist_dest[i] = xr;
    }

    for(auto it:adj[i]){
        if(!vis[it]){
            xr = dist_src[i]^wt[{i,it}];
            dfs(it,xr,f);
        }
    }
    return;
}

void solve()
{
    // Preprocessing
    wt.clear();vis.clear();dist_dest.clear();dist_src.clear();

    ll n,a,b;cin>>n>>a>>b;
    for(ll i=1;i<=n;i++){
        adj[i].clear();
    }

    for(ll i=1;i<n;i++){
        ll u,v,w;cin>>u>>v>>w;
        wt[{u,v}] = w;wt[{v,u}] = w;
        adj[u].push_back(v);adj[v].push_back(u);
    }

    dist_dest.assign(n+1,0);dist_src.assign(n+1,0);

    vis.assign(n+1,0);
    dfs(a,0,1);

    vis.clear();
    vis.assign(n+1,0);
    dfs(b,0,0);
    
    ll f = 0;
    set<ll> st1,st2;
    for(ll i = 1;i<=n;++i){
        if(i == a || i == b){
        }else{
            st1.insert(dist_src[i]);
            st2.insert(dist_dest[i]);
        }
    }

    for(auto x:st1){
        for(auto y:st2){
            if(x == y){f = 1;}
        }
    }

    yno(f);
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
   }
   return 0;
}