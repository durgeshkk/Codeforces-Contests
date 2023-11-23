#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#define ll long long int
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

const ll MAXN = 200005;
vector<pair<ll, ll>> adj[MAXN];
ll dp[MAXN][2], sz[MAXN][2], weight[MAXN];
ll n;

void dfs(ll u, ll p) {
    sz[u][0] = sz[u][1] = 1;
    for (auto v : adj[u]) {
        if (v.first != p) {
            dfs(v.first, u);
            sz[u][0] = mod_add(sz[u][0],sz[v.first][0],mod);
            sz[u][0] = mod_add(sz[u][0],(v.first % 2 == 0),mod);

            sz[u][1] = mod_add(sz[u][1],sz[v.first][1],mod);
            sz[u][1] = mod_add(sz[u][1],(v.first % 2 == 1),mod);

            dp[u][0] = mod_add(dp[u][0],dp[v.first][0],mod);
            ll sa = mod_mul(sz[v.first][0] , v.second,mod);
            dp[u][0] = mod_add(dp[u][0],sa,mod);
            ll sa2 = mod_mul(sz[v.first][1] , v.second,mod);
            dp[u][0] = mod_add(dp[u][0],(v.first % 2 == 0 ? sa2 : sa),mod);

            ll sa3 = mod_mul(sz[v.first][1] , v.second,mod);
            ll sa4 = mod_mul(sz[v.first][0] , v.second,mod);

            dp[u][1] = mod_add(dp[u][1],dp[v.first][1],mod);
            dp[u][1] = mod_add(dp[u][1],sa3,mod);
            dp[u][1] = mod_add(dp[u][1],(v.first % 2 == 1 ? sa4 : sa3),mod);
        }
    }
}

void dfs2(ll u, ll p, ll dist, ll &ans) {
    ll sa = (dist * sz[u][u % 2]) %mod;
    sa = mod_mul(sa,weight[u],mod);
    ans = mod_add(ans,sa,mod);
    ans = mod_add(ans,dp[u][u % 2],mod);
    for (auto v : adj[u]) {
        if (v.first != p) {
            ll sa = mod_sub(sz[1][u % 2] , sz[v.first][u % 2],mod);
            ll new_dist = 0;
            if(v.first % 2 == u % 2){
                new_dist = mod_add(dist,sa,mod);
            }else{
                sa = sz[v.first][u % 2];
                new_dist = mod_sub(dist,sa,mod);
            }

            dfs2(v.first, u,new_dist, ans);
        }
    }
}

ll sumDistancesSameParity() {
    memset(dp, 0, sizeof(dp));
    memset(sz, 0, sizeof(sz));
    // for (ll i = 1; i <= n; i++) {
    //     weight[i] = 1; // If weights are not given, set all to 1
    // }
    dfs(1, -1);
    ll ans = 0;
    dfs2(1, -1, 0, ans);
    return ans;
}
 
void solve()
{
    ll n;cin>>n;
    for(ll i = 1;i<n;++i){
        ll u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    ll ans = sumDistancesSameParity();
    cout<<ans<<endl;
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