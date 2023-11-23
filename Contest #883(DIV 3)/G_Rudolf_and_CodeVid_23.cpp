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
/*
Overall Aim is to make all the bits to 0
*/ 

ll n,m;
/*
ll recur(ll idx,ll msk){
    if(idx == m){
        if(!msk){return 0;}
        return INT_MAX;
    }

    if(dp[idx][msk] != -1){return dp[idx][msk];}

    ll a = INT_MAX,b = INT_MAX;
    // Pick
    a = recur(idx+1,(msk-(msk&cure[idx]))|bana[idx]);
    if(a != INT_MAX){
        a += days[idx];
    }

    // Not Pick
    b = recur(idx+1,msk);
    return dp[idx][msk] = min(a,b);
}
*/

ll fxn(string &a){
    ll cntr = a.size()-1,ok = 0;
    for(ll j = 0;j<a.size();++j,--cntr){
        if(a[j]-'0'){
            ok += (pow(2,cntr));
        }
    }
    return ok;
}

/*
DEBUG this :
*/

void solve()
{
    cin>>n>>m;
    set<pair<ll,ll>> s;
    vector<ll> dist;
    dist.assign((1<<n)+5,INT_MAX);
    s.clear();

    vector<vector<ll>> adj;
    string st;cin>>st;ll msk = fxn(st);
 
    for(ll i=0;i<m;i++){
        ll d;cin>>d;
        string a,b;cin>>a>>b;
        ll x = fxn(a), y = fxn(b);
        x = ((1<<n)-1)^x;
        adj.push_back({x,y,d});
    }
    // cout<<"HI\n";return;

    ll src = msk;
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto p = *s.begin();s.erase(s.find(p));
        ll d = p.first,dista = p.second;
        forj(m){
            ll to = (dista & adj[j][0])|adj[j][1];
            if(dist[to] > (d+adj[j][2])){
                s.erase(s.find({dist[to],to}));
                dist[to] = (d+adj[j][2]);
                s.insert({dist[to],to});
            }
        }
    }

    if(dist[0] == INT_MAX){
        dist[0] = -1;
    }
    cout<<dist[0]<<endl;
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