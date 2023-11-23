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
vector<vector<ll>> dp;
ll recur(ll idx,ll flag,vector<ll> &v) {
    if(idx == v.size()){return 0;}
    ll &sa = dp[idx][flag];
    if(sa != -1){return sa;}
    sa = 0;ll a = 0,b = 0;
    if(flag){
        // All odd idx are even and Vice-versa
        if(idx & 1){
            a = recur(idx+1,1,v);
            b = recur(idx+1,0,v);
        }else{
            a = v[idx]+recur(idx+1,0,v);
            b = recur(idx+1,1,v);
        }
    }else{
        // Idx are same so far
        if(idx & 1){
            a = v[idx]+recur(idx+1,1,v);
            b = recur(idx+1,0,v);
        }else{
            a = recur(idx+1,1,v);
            b = recur(idx+1,0,v);
        }
    }
    sa = max(a,b);
    return sa;
}

ll recur2(ll idx,ll flag,vector<ll> &v) {
    if(idx == 0){return 0;}
    ll &sa = dp[idx][flag];
    if(sa != -1){return sa;}
    sa = 0;ll a = 0,b = 0;
    if(flag){
        // All odd idx are even and Vice-versa
        if(idx & 1){
            a = recur2(idx-1,1,v);
            b = recur2(idx-1,0,v);
        }else{
            a = v[idx]+recur2(idx-1,0,v);
            b = recur2(idx-1,1,v);
        }
    }else{
        // Idx are same so far
        if(idx & 1){
            a = v[idx]+recur2(idx-1,1,v);
            b = recur2(idx-1,0,v);
        }else{
            a = recur2(idx-1,1,v);
            b = recur2(idx-1,0,v);
        }
    }
    sa = max(a,b);
    return sa;
}

// Odd idx pr 1 bhi + toh mein uske baad ke sab 
// ele pick kr lunga
void solve()
{
 
    ll n;cin>>n;vector<ll> v(n+1);
    ll sm = 0,idx = -1;
    for(ll i=1;i<=n;i++){
        cin>>v[i];
        if(i & 1){
            if(v[i] >= 0 and idx == -1){idx = i;}
        }
    }

    if(idx == -1){
        idx = n+1;
    }
    for(ll i=idx;i<=n;i++){
        if(v[i] > 0){sm += v[i];}
    }

    // cout<<idx<<" "<<sm<<endl;

    vector<ll> pref(n+4,0);
    ll evensm = 0;
    forj(idx){
        // cout<<"HI\n";
        if(j and j%2 == 0 and v[j] > 0){evensm += v[j];}
    }
    // cout<<evensm<<endl;
    forj(idx){
        if(j){
            if(j & 1){
            }else{
                if(v[j] > 0){
                    evensm -= v[j];
                }
            }
            pref[j] = evensm;
        }
    }
    // show(pref);
    
    ll sa = 0;
    forj(idx){
        if(j){
            ll ele = 0;
            if(j & 1){
                ele = pref[j]+v[j];
            }else{
                ele = pref[j];
            }
            sa = max(sa,ele);
        }
    }
    sm += sa;
    cout<<sm<<endl;return;

    dp.assign(n+5,vector<ll> (2,-1));
    ll ans = recur(1,0,v);
    dp.clear();
    dp.assign(n+5,vector<ll> (2,-1));
    ll ans2 = recur2(n,0,v);
    ans = max(ans,ans2);
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