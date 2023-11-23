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

ll n;
vector<ll> v;
vector<ll> dp;
 
 /*
ll recur(ll idx,ll f,ll num){
    if(idx == n){
        if(f){return LLONG_MIN;}
        return 0;
    }

    ll &sa = dp[idx][f];
    if(sa != -1){return sa;}
    sa = LLONG_MIN;
    if(f){
        ll ok = 0;
        if(v[idx] == num){
            // continue
            ll a = recur(idx+1,f,num);
            if(a != LLONG_MIN){++a;}

            // End 
            ll b = recur(idx+1,0,0);
            if(b != LLONG_MIN){++b;}
            ok = max(a,b);
        }else{
            // continue
            ll a = recur(idx+1,f,num);
            if(a != LLONG_MIN){++a;}
            ok = a;
        }
        sa = max(sa,ok);
    }else{
        // Try to Start
        ll ok = recur(idx+1,1,v[idx]);
        if(ok != LLONG_MIN){++ok;}
        cout<<idx<<" "<<ok<<endl;

        ll ok2 = recur(idx+1,0,0);
        cout<<idx<<" "<<ok2<<endl;
        sa = max({sa,ok,ok2});
    }
    return sa;
}   
*/

ll recur(ll idx){
    if(idx == n){return 0;}
    ll &sa = dp[idx];
    if(sa != -1){return sa;}
    sa = 0;
    sa = recur(idx+1);
    for(ll i = idx+1;i<n;++i){
        if(v[i] == v[idx]){
            sa = max(sa,(i-idx+1)+recur(i+1));
        }
    }
    return sa;
}

void solve()
{
    cin>>n;
    // forj(n){
    //     cout<<2<<" ";
    // }cout<<endl;
    // show(v);
    // return;
    v.assign(n,0);enter(v);
    for(auto &it:v){--it;}
    dp.assign(n+5,0);

    priority_queue<pair<ll,ll>> pq;
    vector<priority_queue<pair<ll,ll>>> dk(n+5);
    forj(n){
        ll sa = 0;
        if(!dk[v[j]].empty()){
            ll idx = dk[v[j]].top().second; 
            sa = (j-idx+1)+dp[idx];
        }
        dp[j+1] = max(sa,dp[j]);
        dk[v[j]].push({dp[j]-j,j});
    }   
    ll ans = dp[n];
    cout<<ans<<endl;
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