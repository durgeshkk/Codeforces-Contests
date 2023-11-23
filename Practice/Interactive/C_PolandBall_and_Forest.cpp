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

vector<ll> adj[100004];
vector<ll> vis;

void dfs(ll i){
    vis[i] = 1;

    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it);
        }
    }
    return;
}

void solve(){
    ll n;cin>>n;vector<ll> v(n);enter(v);
    vis.assign(n+1,0);

    for(ll i = 0;i<n;++i){
        adj[i+1].push_back(v[i]);
        adj[v[i]].push_back(i+1);
    }

    ll dynamo = 0;
    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            ++dynamo;
            dfs(i);
        }
    }
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}