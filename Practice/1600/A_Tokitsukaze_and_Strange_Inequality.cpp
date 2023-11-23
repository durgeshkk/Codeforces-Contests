#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    map<ll,ll> small_front;// to check c>a (all small a's b4 c)
    map<ll,ll> small_back;// to check c>a (all small a's b4 c)
    ordered_set os;
    for(ll i = 0;i<n;++i){
        os.insert(v[i]);
        ll idx = os.order_of_key(v[i]);
        small_front[v[i]] = idx; 
    }
    os.clear();
    
    for(ll i = n-1;i>=0;--i){
        os.insert(v[i]);
        ll idx = os.order_of_key(v[i]);
        small_back[v[i]] = idx; 
    }
    os.clear();

    ll ans = 0;
    



    for(ll i=0;i<n-3;i++){
        ll val = 0;
        for(ll j = i+1;j<n-1;++j){
            os.insert(v[j]);
            if(v[j] > v[i] and j-i >= 2){
                // Getting ans is pssbl
                ll idx = os.order_of_key(v[j]);
                ll del = os.size()-idx-1;
                val -= del;
            }else{

            }
            val += mp[v[j]];
        }
        os.clear();
        ans += val;
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