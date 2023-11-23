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
ll mod = (ll)(998244353);
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
/*
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
ll printNcR(ll n, ll r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    ll p = 1, k = 1;
    ll z = n;
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p = mod_mul(p,n,mod);
            k = mod_mul(k,r,mod);
 
            // gcd of p, k
            ll m = __gcd(p,k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    // if(z == 37){
    //     cout<<p<<endl;
    // }
    return p;
    // cout << p << endl;
}


ll power(ll base,ll n,ll mod){
   ll ans = 1;
   while(n!= 0){
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

ll fact[61];
ll powfact[61];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=60;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
ll nCr(ll n,ll r){
     ll at = powfact[r];
     ll at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}


vector<ll> alex(31,0);
vector<ll> boris(31,0);

void precomp(){

    alex[1] = 1;
    boris[1] = 0;
    for(ll i = 2;i<=30;++i){
        ll val = (2*i);
        ll games = nCr(val,val/2);

        // --val;
        ll ans = nCr(val-1,(val-1)/2);
        ll ag = mod_add(ans,boris[i-1],mod);

        alex[i] = ag;
        boris[i] = mod_sub(games,alex[i],mod);
        boris[i] = mod_sub(boris[i],1,mod);

        // if(i == 19){
        //     cout<<games<<" "<<35345263800%mod<<endl;
        //     cout<<ans<<" "<<17672631900%mod<<endl;
        //     cout<<ag<<" "<<9075135300%mod<<endl;
        //     cout<<alex[i]<<" "<<boris[i]<<endl;
        // }

        // if(ans == 474237047){
        //     cout<<i<<endl;
        // }

        
    }
}


void solve()
{
 
    ll n;
    cin>>n;

    // show(alex);
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // show(boris);


    cout<<alex[n/2]<<" "<<boris[n/2]<<" ";
    cout<<1<<endl;
/*
    if(n == 2){
        cout<<1<<" "<<0<<" ";
    }
    if(n == 4){
        cout<<3<<" "<<2<<" ";
    }
    if(n == 6){
        cout<<12<<" "<<7<<" ";
    }
    if(n == 8){
        cout<<42<<" "<<27<<" ";
    }
    if(n == 60){
        cout<<341102826<<" "<<248150916<<" ";
    }
    */
    // for(ll i=2;i<=56;i+=2){
    //     cout<<i<<endl;
    // }
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
    precomp();
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