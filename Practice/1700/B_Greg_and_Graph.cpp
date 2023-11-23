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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);

//  "A" : 65, "a" : 97  (-> |) (<- &(~))
set<pair<ll,ll>> adj[300005];
set<pair<ll,ll>> s;
vector<ll> vis,dist;
 
void dijkstra(ll src){
   dist[src] = 0;
   s.insert({0,src});
   while(!s.empty()){
       auto p = *s.begin();s.erase(s.find(p));vis[p.second] = 1;
 
       for(auto it:adj[p.second]){
           if(!vis[it.first]){
               // new_dist = dist till par + dist from par to child
               ll new_dist = (p.first+it.second);
               if(new_dist < dist[it.first]){
                   s.erase(s.find({dist[it.first],it.first}));
                   s.insert({new_dist,it.first});
                   dist[it.first] = new_dist;
               }
           }
       }
    }
}
 
void solver()
{
 
    ll n;cin>>n;
    vis.assign(n+1,0);
    dist.assign(n+1,1e12);
    
    ll edges;cin>>edges;
    for(ll i=0;i<edges;i++){
        s.insert({1e12,i});// Initially all at max. dist
        ll u,v,cst;cin>>u>>v>>cst;
        adj[u].push_back({v,cst});adj[v].push_back({u,cst});
    }
    
    ll node1,node2;cin>>node1>>node2;
    dijkstra(node1);
    if(dist[node2] >= 1e12){
        cout<<"-1\n";
    }else{
        cout<<dist[node2]<<endl;
    }
    return;
}

void solve()
{
 
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        forj(n){cin>>v[i][j];adj[i].insert({j,v[i][j]});}
    }
    
    vector<ll> remove(n,0);
    forj(n){ll ele;cin>>ele;--ele;remove[j] = ele;}

    vector<ll> ans;
    vector<ll> dead(n+1,0);
    for(ll i = 0;i<n;++i){

        for(ll j = 0;j<n;++j){
            if(dead[j]){continue;}
            for(ll k = 0;k<n;++k){
                if(dead[k]){continue;}
                ll node1 = j,node2 = k;
                ll dk = dist[node2];
                
                ans.push_back(dk);
            }
        }

        // Remove all edges from remove[i]
        ll ele = remove[i];
        forj(n){
            for(ll k = 0;k<n;++k){
                if(j == ele){
                    adj[j].erase(adj[j].find({k,v[j][k]}));
                    v[j][k] = 1e12;
                    adj[j].insert({k,v[j][k]});
                }

                if(k == ele){
                    adj[j].erase(adj[j].find({k,v[j][k]}));
                    v[j][k] = 1e12;
                    adj[j].insert({k,v[j][k]});
                }
            }
        }
        dead[ele] = 1;
    }
    show(ans);
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