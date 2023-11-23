/*
      Author : ME
*/
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
vector<ll> adj[100004];
vector<ll> vis,dp,vis2,mp;
ll n;

ll dfs(ll i){
    vis[i] = 1;
    ll a = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            a += dfs(it);
        }
    }
    return dp[i] = (a+1);
} 

void dfs2(ll i,ll par){
    vis2[i] = 1;
    ll a = 0;
    for(auto it:adj[i]){
        if(!vis2[it]){
            dfs2(it,i);
            a = max(a,dp[it]);
        }
    }

    if(par == -1){
    }else{
        a = max(a,n-dp[i]);
    }
    mp[i] = a;
    return;
}

void solve()
{
 
    cin>>n;
    for(ll i=0;i<=n;i++){adj[i].clear();}
    vis.assign(n+1,0);dp.assign(n+1,0);
    vis2.assign(n+1,0);mp.assign(n+1,0);

    for(ll i=1;i<n;i++){ll u,v;cin>>u>>v;adj[u].push_back(v);adj[v].push_back(u);}
    dfs(1);
    dfs2(1,-1);
    
    ll mn = LLONG_MAX,ele1 = 0,ele2 = 0;
    for(ll i = 1;i<=n;++i){
        mn = min(mn,mp[i]);
    }

    for(ll i = 1;i<=n;++i){
        if(mp[i] == mn){
            if(ele1 == 0){ele1 = i;}
            else{ele2 = i;}
        }
    }

    if(ele2 == 0){
        ll ok = 0;
        for(auto it:adj[1]){
            ok = it;
        }
        cout<<1<<" "<<ok<<endl;
        cout<<1<<" "<<ok<<endl;
    }else{
        ll ok = 0;
        for(auto it:adj[ele1]){
            if(it != ele2){ok = it;}
        }

        if(ok != 0){
            cout<<ele1<<" "<<ok<<endl;
            cout<<ele2<<" "<<ok<<endl;
        }else{
            for(auto it:adj[ele2]){
                if(it != ele1){ok = it;}
            }
            cout<<ele2<<" "<<ok<<endl;
            cout<<ele1<<" "<<ok<<endl;
        }
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