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
 
vector<vector<pair<ll,ll>>> adj;
 
bool flag = 1; 
void ai_dfs(vector<ll> &vis,ll i,ll state,ll &c0,ll &c1){
    vis[i] = state;
    if(state == 0){++c0;}
    else{++c1;}

    for(auto it:adj[i]){
        if(vis[it.first] == -1){
            ai_dfs(vis,it.first,(state^it.second),c0,c1);
        }else{
            // Checking Stage
            if((it.second^vis[i]) != vis[it.first]){
                flag = 0;return;
            } 
        }
    }
    return;
}

void solve()
{
 
    ll n,c;cin>>n>>c;
    adj.assign(n+3,vector<pair<ll,ll>> ());

    // Pre-Updation for each TC :
    ll f = 0,crew=0,imp=0;
    for(ll i = 0;i<=n;++i){
        adj[i].clear();
    }

    map<pair<ll,ll>,string> mp;
    for(ll i=0;i<c;i++){
        ll l,r;cin>>l>>r;
        string st;cin>>st;

        if(st == "imposter"){
            // Different team
            adj[l].push_back({r,1});
            adj[r].push_back({l,1});
        }else{
            // Same team
            adj[l].push_back({r,0});
            adj[r].push_back({l,0});
        }
    }
    if(f&1){cout<<"-1\n";return;}

    vector<ll> vis(n+1,0);
    vector<ll> col(n+1,0);
 
    for(ll i = 1;i<=n;++i){
        vis[i] = -1;
    }

    ll ak = 0;
    flag = 1;
    for(ll i = 1;i<=n;++i){
        if(vis[i] == -1){
            // Call DFS
            ll cnt_0 = 0,cnt_1 = 0;
            ll state = 0;
            ai_dfs(vis,i,state,cnt_0,cnt_1);
            if(flag){
                ak += max(cnt_0,cnt_1);
            }else{
                cout<<"-1\n";return;
            }
        }
    }
    cout<<ak<<endl;
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
/*
 
vector<ll> adj[100004];
ll imp = 0,crew = 0,f = 0;

// Error :
1 3
2 3 //ending at the same position must give the same ans


void dfs(vector<ll> &ans,vector<ll> &vis,ll i,map<pair<ll,ll>,string> &mp){
    // 1 --> Imposter , 2 --> Crewmate
    vis[i] = 1;
    for(auto it:adj[i]){
        if(vis[it]){
            if(adj[it].size() == 0){continue;}
            // Check if he is speaking correct / validate
            string tmp = mp[{i,it}];
            if(ans[i] == 1){
                // i is Imposter
                if(tmp == "imposter"){
                    if(ans[it] == 2){

                    }else{
                        f = 1;// For wrong ans
                    }
                }else{
                    if(ans[it] == 1){

                    }else{
                        f = 1;// For wrong ans
                    }
                    
                }
            }else if(ans[i] == 2){
                // i is Crewmate
                
                if(tmp == "imposter"){
                    if(ans[it] == 1){

                    }else{
                        f = 1;// For wrong ans
                    }
                }else{
                    if(ans[it] == 2){

                    }else{
                        f = 1;// For wrong ans
                    }
                }
            }

        }else{
            // Check what does i tells abt it
            string tmp = mp[{i,it}];
            if(tmp == "imposter"){
                if(ans[i] == 1){ans[it] = 2;++crew;}
                else{ans[it] = 1;++imp;}
            }else{
                if(ans[i] == 1){ans[it] = 1;++imp;}
                else{ans[it] = 2;++crew;}
            }

            // call DFS after updating ans;
            dfs(ans,vis,it,mp);
        }
    }
}
 
void solve()
{
 
    ll n,c;cin>>n>>c;
    
    // Pre-Updation for each TC :
    f = 0,crew=0,imp=0;
    for(ll i = 0;i<=n;++i){
        adj[i].clear();
    }

    map<pair<ll,ll>,string> mp;
    for(ll i=0;i<c;i++){
        ll l,r;cin>>l>>r;
        string st;cin>>st;
        adj[l].push_back(r);
        if(mp.find({l,r}) != mp.end()){
            if(mp[{l,r}] != st){
                f = 1;
            }
            continue;
        }
        mp[{l,r}] = st;
    }
    if(f&1){cout<<"-1\n";return;}
 
    vector<ll> vis(n+1,0);
    vector<ll> ans(n+1,0);
    ll ak = 0;
    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            // Call DFS
            ans[i] = 1;
            dfs(ans,vis,i,mp);
            if(f & 1){cout<<"-1\n";return;}
            ll mx = max(imp+1,crew);
            ak += mx;
            imp = 0,crew = 0;
        }
    }
    cout<<ak<<endl;
    return;
}

*/