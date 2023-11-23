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
vector<ll> adj[100004];
vector<ll> dp,flag;
vector<ll> vis;

pair<ll,ll> dfs(ll i,ll par,ll f){
    vis[i] = 1;
    ll len = 0;
    for(auto x:adj[i]){
        if(x == par){continue;}
        if(!vis[x]){
            len = dfs(x,i,f).first;
            f = dfs(x,i,f).second;
        }else{
            if(flag[x] != -1){
                dp[i] = 1+dp[flag[x]];
                return {1+dp[i],-1};
            }else{
                f = x;
            }
            // if(flag[x] == -1){
            //     dp[i] = 1+dp[x];
            //     return {dp[i],-1};
            // }
        }
    }

    if(f == -1){
        flag[i] = f;
        dp[i] = 1+len;
        return {1+len,f};
    }

    flag[i] = f;
    if((f == i)){
        f = -1;
    }

    dp[i] = 1+len;
    return {1+len,f};
}

vector<ll> solve(ll n,vector<ll> arr) {
    dp.assign(n+1,-1);
    flag.assign(n+1,-1);
    vis.assign(n+1,0);
    for(ll i = 0;i<=n;++i){adj[i].clear();}

    for(ll i = 0;i<n;++i){
        if(i+1 == arr[i]){
            dp[i+1] = 1;continue;
        }
        adj[i+1].push_back(arr[i]);
    }

    for(ll i = 1;i<=n;++i){
        if(!vis[i]){
            dfs(i,-1,-1);
        }
    }

    for(ll i = 1;i<=n;++i){
        if((flag[i] != -1) and (i != flag[i])){
            dp[i] = dp[flag[i]];
        }
    }

    vector<ll> ans;
    for(ll i = 1;i<=n;++i){
        ans.push_back(dp[i]);
    }
    return ans;
}

void solver()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
    vector<ll> ans = solve(n,v);
    show(ans);
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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
       solver();
       ++i;
   }
   //solve();
   return 0;
}