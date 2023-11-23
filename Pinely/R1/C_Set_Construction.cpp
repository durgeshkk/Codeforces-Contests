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
 
vector<ll> adj[1001];
 
ll k = 1;

void mydfs(ll it,map<ll,set<ll>> &mp,vector<ll> &vis){
    vis[it] = 1;

    if(adj[it].size() == 0){
        mp[it].insert(k);++k;return;
    }else{
        set<ll> ak;
        for(auto alpha:adj[it]){
            if(!vis[alpha]){
                mydfs(alpha,mp,vis);
            // }else{
            }
            set<ll> tmp = mp[alpha];
            for(auto j:tmp){
                ak.insert(j);
            }
        }

        for(auto alpha:ak){
            mp[it].insert(alpha);
        }
        mp[it].insert(k);++k;
    }
    return;
}

void solve()
{
 
    for(ll i = 0;i<1001;++i){
        adj[i].clear();
    }

    ll n;cin>>n;
    vector<string> v;
    for(ll i=0;i<n;++i){
        string st;cin>>st;
        v.push_back(st);
        for(ll j=0;j<n;++j){
            if(st[j] == '1'){
                // cout<<i+1<<" "<<j+1<<endl;
                adj[j+1].push_back(i+1);
            }
        }
    }

    if(n == 1){
        cout<<1<<" "<<1<<endl;return;
    }

    map<ll,set<ll>> mp;
    map<ll,set<ll>> sz_v;
    multiset<ll> sz;
    
    for(ll i = 1;i<=n;++i){
        if(adj[i].size() == 0){continue;}

        sz.insert(adj[i].size());
        sz_v[adj[i].size()].insert(i);
        // for(auto it:adj[i]){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
    }

    // cout<<"---\n";

    vector<ll> vis(n+1,0);
    while(!sz.empty()){
        ll size = *sz.rbegin();
        ll val = *sz_v[size].rbegin();
        sz_v[size].erase(sz_v[size].find(val));

        if(vis[val] == 1){
            sz.erase(sz.find(*sz.rbegin()));
        }else{
            // cout<<"Val : "<<val<<endl;
            set<ll> sat;
            for(auto it:adj[val]){
                if(!vis[it]){
                    mydfs(it,mp,vis);
                }
                set<ll> tmp = mp[it];
                for(auto j:tmp){
                    sat.insert(j);
                }
            }

            for(auto it:sat){
                mp[val].insert(it);
            }
            mp[val].insert(k);++k;
            sz.erase(sz.find(*sz.rbegin()));
        }
    }

    for(ll z=1;z<=n;++z){
        cout<<mp[z].size()<<" ";
        for(auto j:mp[z]){
            cout<<j<<" ";
        }cout<<endl;
    }
    k = 1;
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
    // cout<<"HI\n";
       solve();
       ++i;
   }
   return 0;
}