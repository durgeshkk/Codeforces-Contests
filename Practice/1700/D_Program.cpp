/*
      Author : ME
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
 
/*
+,- will be continous over any range i.e. -3 to 
0 jane ke liye ek range of op se hi gujarna padenga so we can perform 
prefix op
*/

void solve()
{
 
    ll n,q;cin>>n>>q;
    string s;cin>>s;

    vector<ll> mx(n+1,-1e8);vector<ll> mn(n+1,1e8);
    vector<ll> mx2(n+1,-1e8);vector<ll> mn2(n+1,1e8);
    ll ele = 0;
    vector<ll> sm;sm.push_back(0);

    for(ll i=1;i<=n;i++){
        char ch = s[i-1];
        if(ch == '-'){
            --ele;
            mx[i] = max(mx[i-1],ele);
            mn[i] = min(mn[i-1],ele);
        }else{
            ++ele;
            mx[i] = max(mx[i-1],ele);
            mn[i] = min(mn[i-1],ele);
        }
        sm.push_back(ele);
    }
    // show(sm);show(mx);show(mn);return;

    for(ll i = n-1;i>=0;--i){
        if(i == n-1){
            mn2[i] = sm[n];
            mx2[i] = sm[n];
        }else{
            mn2[i] = min(mn2[i+1],sm[i+1]);
            mx2[i] = max(mx2[i+1],sm[i+1]);
        }
    }
    // show(mx2);show(mn2);return;

    for(ll i=0;i<q;i++){
        ll l,r;cin>>l>>r;
        // Range 1 : 
        ll mn_b4 = mn[l-1],mx_b4 = mx[l-1];
        if(l == 1){
            mn_b4 = 0,mx_b4 = 0;
        }

        ll diff = sm[r]-sm[l-1];
        // cout<<diff<<" ";
        if(r == n){
            ll ans = abs(mx_b4-mn_b4)+1;
            if(mx_b4 < 0 || mn_b4 > 0){
                ++ans;
            }
            cout<<ans<<endl;
        }else{
            ll mx_now = mx2[r];ll mn_now = mn2[r];
            mx_now -= diff;mn_now -= diff;
            mn_now = min(mn_now,mn_b4);
            mx_now = max(mx_now,mx_b4);
            ll ans = abs(mx_now-mn_now)+1;
            // cout<<mx_now<<" "<<mn_now<<" ";
            if(mx_now < 0 || mn_now > 0){
                ++ans;
            }
            cout<<ans<<endl;
        }
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