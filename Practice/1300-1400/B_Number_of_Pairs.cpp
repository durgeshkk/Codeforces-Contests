#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);


void solve()
{
 
    ll n,l,r;
    cin>>n>>l>>r;

    vector<ll> v(n);
    enter(v);
    
    ordered_set os;
    map<ll,ll> mp;
    os.insert(v[0]);
    mp[v[0]]++;
    ll ans = 0;
    for(ll i=1;i<n;i++){
        
        ll low = l-v[i];
        // low--;
        ll high = r-v[i];
        high;

        ll val = v[i];
        
        
        ll lb = os.order_of_key(low);
        ll ub = os.order_of_key(high+1);
        // lb -= mp[v[i]];
        // ub += mp[v[i]];
        os.insert(v[i]);
        mp[v[i]]++;
        // cout<<v[i]<<" "<<lb<<" "<<ub<<endl;
        ans += (ub-lb);
    }
    cout<<ans<<endl;
    return;
}    
    

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}