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
ll mod = (ll)(1e9+7);
 
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
// ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

void solve()
{
 
    ll n;cin>>n;
    
    ll ans = 0;
    ans = mod_mul(n,n+1,mod);
    ll ag = mod_mul(n,4,mod);
    ag = mod_sub(ag,1,mod);
    ans = mod_mul(ans,ag,mod);
    ans = mod_mul(ans,337,mod);
    cout<<ans<<endl;
    return;

    ll sm = 0;
    // Sum of 2*n*n
    ll val = mod_mul(n,n+1,mod);
    ll z = mod_mul(n,2,mod);
    z = mod_add(z,1,mod);

    val = mod_mul(val,z,mod);
    // val /= 6;



    ll sn = mod_mul(n-1,n,mod);
    sn = mod_mul(sn,n+1,mod);
    sn = mod_mul(sn,2,mod);
    // sn /= 3;

    
    // cout<<val<<" "<<sn<<endl;
    sm = mod_add(val,sn,mod);
    sm = mod_mul(sm,2022,mod);
    sm /= 6;
    cout<<sm<<endl;
    // cout<<sm/2022<<endl;
    // cout<<85*2022<<endl;
    return;

    for(ll i=1;i<=n;i++){
        ll val = mod_mul(i,i,mod);
        sm = mod_add(sm,val,mod);
    }
 
    for(ll i=1;i<n;i++){
        ll val = mod_mul(i,i+1,mod);
        sm = mod_add(sm,val,mod);
    }
    sm = mod_mul(sm,2022,mod);
    cout<<sm<<endl;
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