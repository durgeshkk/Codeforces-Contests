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
ll mod = (ll)(1e9+7);
 
/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
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
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll sieve[1000005];
void createsieve(){
    ll ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(ll i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(ll i = 2;i*i<=ntlen;++i){
 
        // Set all multiples to 0
        if(sieve[i] == 1){
 
            for(ll j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
vector<ll> adj[100004];
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
 
//  Both (0,0) and (px,py) must be covered
double oa,ob,ap,bp,dist;
bool check(double mid){
    ll f = 0,f1 = 0;
    if(oa <= mid){++f;}
    if(ob <= mid){++f1;}

    if(ap <= mid){++f;}
    if(bp <= mid){++f1;}

    if(f == 2 || f1 == 2){return 1;}
    if(((oa<=mid)||(ob<=mid)) and ((ap<=mid)||(bp<=mid)) and (dist<=(2.0*mid))){
        return 1;
    }
    return 0;
}

void solve()
{
    cout<<fixed;
 
    ll px,py;cin>>px>>py;
    ll ax,ay;cin>>ax>>ay;
    ll bx,by;cin>>bx>>by;

    oa = sqrt(1.0*ax*ax+1.0*ay*ay);
    ob = sqrt(1.0*bx*bx+1.0*by*by);
    ap = sqrt(1.0*((ax-px)*(ax-px))+1.0*((ay-py)*(ay-py)));
    bp = sqrt(1.0*((bx-px)*(bx-px))+1.0*((by-py)*(by-py)));
    dist = sqrt(1.0*((bx-ax)*(bx-ax))+1.0*((by-ay)*(by-ay)));


    double ans = max(min(oa,ob),min(ap,bp));
    // cout<<ans<<endl;
    double l_real = 0.0, r_real = 1e12;
    uint64_t l = reinterpret_cast<uint64_t&>(l_real), r = reinterpret_cast<uint64_t&>(r_real);
    while (l < r){
        // cout<<l<<" "<<r<<endl;
        uint64_t mid = l + (r - l) / 2;
        if (check(reinterpret_cast<double&>(mid))){
            ans = mid;
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    
    cout<<reinterpret_cast<double&>(l)<<endl;
    /*
    cout<<oa<<" "<<ob<<" "<<ap<<" "<<bp<<endl;
    double l = 0.0,h = 2.0*1e9;
    double lim = 1.0*1e6;
    lim = (double)1.0/lim;
    // double ans = 0.0;
    while((h-l) >= lim){
        // cout<<l<<" "<<h<<endl;
        double mid = l+(h-l)/2;
        if(((oa<=mid)||(ob<=mid)) and ((ap<=mid)||(bp<=mid)) and (dist <= (2.0*mid))){
            ans = mid;
            h = mid;
        }else{
            l = mid+1;
        }
    }
    // */
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   setprecision(10);// also use precision with ans now
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