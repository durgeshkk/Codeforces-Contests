#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
 
    // To get min. Inversions we will be requiring 
    // pos of element & thus there comes role of OSet
    ordered_set os; //use karte samay yaad rhe tree fxn remove karna h
    multiset<ll> ms;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        // We also need the frequencies of ele greater & small than v[i] 
        os.insert(v[i]);
        ms.insert(v[i]);

        auto it = ms.upper_bound(v[i]);
        ll ele_gr8ter = 0;
        ll idx = 0;
        if(it == ms.end()){
            idx = ms.size();
        }else{
            ele_gr8ter = *it;
            idx = os.order_of_key(ele_gr8ter);
        }

        ll lss = os.order_of_key(v[i]);
        ll gr8 =  ms.size()-idx;
        // Now jst get freq
        ans += min(lss,gr8);
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