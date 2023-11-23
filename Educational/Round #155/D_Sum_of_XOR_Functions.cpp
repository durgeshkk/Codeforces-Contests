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
ll mod = (ll)(998244353);
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(ll i=0;i<n;i++){cin>>v[i+1];}
 
    ll ans= 0;
    forj(31){
        vector<ll> pref(n+1,0);
        for(ll i = 1;i<=n;++i){
            pref[i] = pref[i-1];
            if(v[i]&(1<<j)){pref[i] ^= 1;}
        }

        ll sm = 0;
        map<ll,ll> cnt,val;
        cnt[0]=1;
        for(ll i = 1;i<=n;++i){
            sm = mod_add(sm,i*cnt[pref[i]^1],mod);
            sm -= val[pref[i]^1];sm += mod;sm %= mod;

            val[pref[i]] = mod_add(i,val[pref[i]],mod);
            cnt[pref[i]]++;
        }
        sm = mod_mul(sm,(1<<j),mod);
        ans += sm;ans %= mod;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}