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
 
vector<ll> adj[300001];
void tree(){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
vector<pair<ll,ll>> v(300001,{0,0});
vector<ll> vis(300001,0);
vector<ll> pre(300001,0);
vector<ll> tot(300001,0);

pair<ll,ll> dfs(ll i){
    vis[i] = 1;
    // Short-Cut:
    /*
    ll childs = 0;
    for(auto it:adj[i]){
        if(!vis[it]){
            ll mn = dfs(it);
            childs += mn;
        }
    }

    pre[i] = childs;
    return childs+1;
    */
    // /*
    for(auto it:adj[i]){
        if(!vis[it]){
            if(adj[it].size() == 0){
                v[it] = {0,0};
                if(v[i].first == 0){
                    v[i].first = 1;
                }else{
                    v[i].second = 1;
                }
            }else{
                pair<ll,ll> p = dfs(it);
                ll sm = p.first+p.second+1;
                if(v[i].first == 0){
                    v[i].first = sm;
                }else{
                    v[i].second = sm;
                }
            }
        }
    }
    return {v[i].first,v[i].second};
    // */
}


ll dfs2(ll i,ll p){
    for (auto it : adj[i]){
        if(it == p){

        }else{
            dfs2(it,i);
        }
    }

    vector<ll> v;
    for (auto it : adj[i]){
        if(it == p){

        }else{
            v.push_back(it);
        }
    }

    if(v.size() == 2){
        tot[i] = max(tot[v[0]]+pre[v[1]],tot[v[1]]+pre[v[0]]);
    }else if(v.size() == 1){
        tot[i] = pre[v[0]];
    }

    return tot[i];
}


void solve()
{
 
    ll n;cin>>n;
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        adj[i].clear();
        vis[i] = 0;
        v[i] = {0,0};
        pre[i] = 0,tot[i] = 0;
    }

    for(ll i=1;i<n;i++){
        tree();
    }

    dfs(1);
    for (ll i = 1; i <= n; i++){
        pre[i] = v[i].first+v[i].second;
    }

    for (ll i = 1; i <= n; i++){
        vis[i] = 0;
    }

    cout<< dfs2(1,-1) <<endl;
    return;
}
 
/*
ll ans = 0;
void ansdfs(ll i){
    if(adj[i].size() == 0){return;}
    ll a,b;    
    ll f = 0;
    for(auto it:adj[i]){
        if(f == 0){
            f = !f;a = it;
        }else{
            b = it;
        }
    }

    pair<ll,ll> p = v[i];
    if(p.first > p.second){
        ans += (p.first-1);
        ansdfs(b);
    }else if(p.second > p.first){
        ans += (p.second-1);
        ansdfs(a);
    }else{
        // Take the balanced child & call on more diff
        pair<ll,ll> x = v[a];
        pair<ll,ll> y = v[b];
        ll diff1 = abs(x.first-x.second);
        ll diff2 = abs(y.first-y.second);

        if(diff1 > diff2){
            ans += (y.first+y.second);
            ansdfs(a);
        }else{
            ans += (x.first+x.second);
            ansdfs(b);
        }
    }
}
*/


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
       ++i;
   }
   return 0;
}

/*

void tree(){
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

vector<ll> h(8,0);
vector<pair<ll,ll>> vph(8,{0,0});
vector<ll> vis(200005,0);

void cnt(ll k){
    vis[k] = true;
    h[k] = 1;

    if(adj[k].size() == 0){
        return;
    }
    
    ll val = 0;
    for(auto i:adj[k]){
        if(!vis[i]){
            cnt(i);
            // h[k] += h[i]; 
            val += h[i];
            // ++val;
        }
    }
    h[k] = 1+val;
    return;
}

void hei(ll k){
    vis[k] = true;
    h[k] = 1;
    vph[k] = {0,0};

    if(adj[k].size() == 0){
        vph[k].first = 1;
        return;
    }

    ll val = 0;
    ll counter = 0;
    for(auto i:adj[k]){
        if(!vis[i]){
            hei(i);
            if(counter & 1){
                vph[k].first += (vph[i].first+vph[i].second);
            }
            else{
                vph[k].second += (vph[i].first+vph[i].second);
            }
            counter^=1;
            // h[k] += h[i]; 
            // val += h[i];
            // ++val;
        }
    }
    // h[k] = 1+val;
    return;
}
 
void solve()
{
 
    ll n;
    cin>>n;
    
    for(ll i=1;i<n;i++){
        tree();
    }

    cnt(1);
    for(ll i=1;i<=n;i++){
        vis[i] = false;
    }
    hei(1);
    show(h);

    for(auto it:vph){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return;
}
 */