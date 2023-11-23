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
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n,m;cin>>n>>m;
    vector<ll> v(n);enter(v);
    vector<ll> table(m);enter(table);

    map<ll,ll> mp;
    multiset<pair<ll,ll>> ms;
    for(ll i=0;i<n;i++){
        mp[v[i]]++;
    }   
    
    for(auto it:mp){
        ms.insert({it.second,it.first});
    }

    sort(table.begin(),table.end());
    reverse(table.begin(),table.end());

    ll ans = 0;
    for(ll i = 0;i<m;++i){
        ll capacity = table[i];
        
        if(ms.empty()){break;}

        auto p = *ms.rbegin();
        ms.erase(ms.find(p));

        if(capacity >= p.first){
            ans += p.first;
        }else{
            ll diff = (p.first-capacity);
            ans += capacity;
            ms.insert({diff,p.second});
        }
    }
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