/*
Once in a LifeTime,
Will never let you Down!!
*/
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
const ll mod = 998244353;
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

ll power(ll base,ll n,ll mod){
    ll ans = 1;
    while( n!= 0){
    if(n%2){
        n-=1;
        ans = (ans*base)%mod;
    }
    else{
        n /= 2;
        base = (base*base)%mod;
    }
    }
    return ans;
}

ll fact[1000005];
ll powfact[1000005];
void precomputefact(){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=1000005;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

// YE DIL MAANGE MORE!!
/*
If there is a '?' at the idx = k, then at '?' its neither

Wrong Assumption : 
>??>?  => 5,2,3,6,4
>??>?  => 4,2,3,6,5 is also pssbl this doesn't mean that >(n-2) __ >(n-1) __ >(n) only

Now try to fill from back :
Ways to fill Last '?' = current set size(n) - (no max & min) = n-2
So for last '?' ans = 6-2=4

If last char is either max or min, then there is only 1 way to fix the last value
from set.

And so on for all other '?'
*/ 
void solve()
{
    ll n,q;
    cin>>n>>q;
    string s;cin>>s;
    ll ans = 1;
    for(ll i=1;i<s.size();i++){
        if(s[i] == '?'){
            ans *= i;
        }
        ans %= mod;
    }

    ll f = 1;
    if(s[0] == '?'){f = 0;}

    cout<<ans*f<<endl;
    
    forj(q){
        ll idx;char ch;cin>>idx>>ch;--idx;

        if(idx and (s[idx] != ch)){
            if(ch == '?'){
                ans *= idx;
            }else if(s[idx] == '?'){
                ans *= power(idx,mod-2,mod);
            }
        }
        ans %= mod;

        s[idx] = ch;
        f = 1;
        if(s[0] == '?'){f = 0;}
        cout<<ans*f<<endl;
    }
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
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