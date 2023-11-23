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
/*
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
// Fxn call(for ((b/a)%mod)) :
// ll c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
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
 
ll fact[2000005];
ll powfact[2000005];
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
    if(n < r){return 0;}
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

/*
Cases : 
1. 1 2 3 4 5 1
   1 2 3 5 4 1
   1 2 5 4 3 1
   1 5 4 3 2 1

2. 2 3 4 5 2 1
   2 3 5 4 2 1
   2 5 4 3 2 1
   2 3 4 5 6 2
   2 3 4 5 2 1
   2 3 4 6 2 1
   2 3 4 6 5 2
   2 3 5 6 2 1, etc.

This all says that 
(chottu) 4 (big num's) 4 (chottu)

1 big num is confirm to be picked
2 4's we are picking
left is (n-3) of which we will pick x chottu's & y big num's
x + y = (n-3)

Let m = 10
Chottu's avail : (4-1) = 3
Big's avail : (m-4) = 6
So, I'll pick ((3)Cx)*((6)C(n-3-x)) ; where x changes from [0,z], where 
z = min(n-3,chottu avail,Big avail);
But this approach will lead to TLE!!

Smart Approach :
If n = 5 and m = 7
For n = 5 we need to select (n-1) distinct elements of m ==> (m)C(n-1)
Now for this (n-1) distinct elements :Each time any 1 of this elements can be 
repeated except larger since then it will not satisfy condition 4
Repeatation with distinct = (n-2)
e.g. 
1 2 3 4 seleted fot n = 5
duplicating 1 : 1 2 3 4 1,1 3 4 2 1,1 4 3 2 1 
duplicating 2 : 1 2 3 4 2,2 3 4 2 1,2 4 3 2 1 same for 3 too!!

The *Below* statement is incorrect : 
This implies duplicating any element results in (distinct-1) ans..
We can't select larger element for duplicacy so elements we can select = (distinct-1)
And each of this results in other (distinct-1) pssbilities..

Correct Statement : We have (n-1) different elements!!!
Now let the mx_ele = y & repeat ele = x
...(x)...(y)...(x).... ==> 2 distinct removed, ele left = n-1-2=n-3
So now other pending (n-3) ele can be either placed on right of n-3 or on left.
So pssbl = 2^(n-3)
Thus ans = mC(n-1)*(distinct)*(permutation) = mC(n-1)*(n-2)*(2^(n-3))
*/
void solve()
{
 
    ll n,m;cin>>n>>m;
    ll ans = 0;
    if(n == 2){cout<<ans<<endl;return;}
    ans = nCr(m,n-1);
    ll distinct = (n-2);
    ans = mod_mul(distinct,ans,mod);
    ll sa = power(2,n-3,mod);
    ans = mod_mul(sa,ans,mod);
    // ll small_ans2 = mod_mul(distinct,distinct,mod);
    // ans = mod_mul(small_ans2,small_ans,mod);
    /*
    for(ll i=1;i<=m;i++){
        ll chottu = (i-1);
        // Selecting 1 big is confirm from avail
        ans = mod_add(ans,nCr(m-i,1),mod);
        ll big = (m-i-1);
        ll sa = 0;
        ll z = min({n-3,chottu,big});
        for(ll k = 0;k<=z;++k){
            ll ele = mod_mul(nCr(chottu,k),nCr(big,n-3-k),mod);
            ans = mod_add(ans,ele,mod);
        }
    }*/
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
   precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin>>t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}