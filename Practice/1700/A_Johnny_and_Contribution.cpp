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
#define show(a) for(ll e: a) cout<<e<<" "; 
using namespace std;
ll mod = (ll)(1e9+7);

map<ll,set<ll>> adj,dk;

void solve(){
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;adj[u].insert(v);adj[v].insert(u);}

    vector<ll> topic(n);enter(topic);
    multiset<pair<ll,ll>> ms;
    
    map<ll,set<ll>> top_blog; 
    for(ll i = 0;i<n;++i){
        ms.insert({topic[i],i+1});
    }

    map<ll,set<ll>> mp;
    vector<ll> ans;
    for(auto it:ms){
        auto p = it;
        if(mp[p.second].size()+1 == p.first){
            if(mp[p.second].size() >= 1){
                if(*mp[p.second].rbegin() >= p.first){
                    cout<<"-1\n";return;
                }
            }
        }else{
            cout<<"-1\n";return;
        }

        for(auto x:adj[it.second]){
            mp[x].insert(it.first);
        }
        ans.push_back(it.second);
    }
    show(ans);
    return;
}


void solverr(){
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;adj[u].insert(v);adj[v].insert(u);}

    vector<ll> topic(n);enter(topic);
    vector<pair<ll,ll>> ms;
    
    map<ll,set<ll>> top_blog; 
    for(ll i = 0;i<n;++i){
        ms.push_back({topic[i],i+1});
        // top_blog[topic[i]].insert(i+1);
    }

    sort(ms.begin(),ms.end());
    map<ll,set<ll>> mp;vector<ll> ans;

    ll cnt = 1;
    for(ll i = 0;i<ms.size();){
        if(cnt == ms[i].first){
            while(cnt == ms[i].first and i<ms.size()){
                auto p = ms[i];
                auto it = ms[i];

                if(mp[p.second].size()+1 == p.first){
                    if(mp[p.second].size() >= 1){
                        if(*mp[p.second].rbegin() >= p.first){
                            cout<<"-1\n";return;
                        }
                    }
                }else{
                    cout<<"-1\n";return;
                }

                for(auto x:adj[it.second]){
                    mp[x].insert(it.first);
                }

                // cout<<it.first<<" ";
                ans.push_back(it.second);
                ++i;
            }
            --i;
        }
        ++cnt;
        ++i;
    }
    cout<<endl;
    /*    
    for(auto it:ms){
        auto p = it;
        if(mp[p.second].size()+1 == p.first){

        }else{
            cout<<"-1\n";return;
        }

        for(auto x:adj[it.second]){
            mp[x].insert(it.first);
        }
        cout<<it.first<<" ";
        ans.push_back(it.second);
    }
    cout<<endl;*/
    show(ans);
    return;
}

void solver(){
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;adj[u].insert(v);adj[v].insert(u);}

    vector<ll> topic(n);enter(topic);
    multiset<ll> ms;

    map<ll,set<ll>> top_blog; 
    for(ll i = 0;i<n;++i){
        top_blog[topic[i]].insert(i+1);
    }

    // If they are in each other's adj list,then ret -1
    // Else Travel lvl by lvl & ans matches the given topic vector then return ans 
    // vector by dp
    ll mx = *max_element(topic.begin(),topic.end());
    for(ll i = 1;i<=mx;++i){
        set<ll> curr = top_blog[i];
        // Must for all !!!
        // Only check if the given ele in curr are !adj
        for(auto it:curr){
            for(auto x:adj[it]){
                if(curr.find(x) != curr.end()){
                    cout<<"-1\n";return;
                }
                dk[x].insert(i);
            }
        }

        if(i == 1){
            // No need to keep track of prev
        }else{
            for(auto it:curr){
                if(dk[it].size()+1 == i){
                }else{
                    cout<<"-1\n";return;
                }
            }
            /*
            set<ll> prev = top_blog[i-1];
            // Ele in curr must be adj ele of prev
            for(auto it:curr){
                ll f = 0;
                for(auto x:adj[it]){
                    if(prev.find(x) != prev.end()){
                        f = 1;break;
                    }
                }if(f == 0){
                    cout<<"-1\n";return;
                }
            }*/
        }
    }

    for(auto it:top_blog){
        show(it.second);
    }cout<<endl;
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