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

ll solve()
{
    ll val;
    cin>>val;

    ll n;
    cin>>n;
    
    vector<ll> v(n);
    enter(v);
 
    ll ans = 0;
    ans += (v[0]%10);
    ans = ans%1000000007;
    for(ll i = 1;i<n;++i){
        ans = ((ans*(v[i]%10))%1000000007);
    }
    return ans;
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
       ll ans = solve();
       cout<<ans<<endl;
   }
   //solve();
   return 0;
}