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
 
vector<ll> cold,hot;
vector<vector<ll>> dp; 
ll recur2(ll idx,ll prev,vector<ll> &v){
    if(idx == v.size()){
        return 0;
    }

    if(dp[idx][prev] != -1){
        return dp[idx][prev];
    }

    ll a=0,b = 0;
    // Work on same CPU as of prev
    if(idx > 0 and v[idx-1] == v[idx]){
        a = hot[v[idx]-1]+recur2(idx+1,prev,v);
    }else{
        // Perform on different CPU & store the prev on a CPU
        a = cold[v[idx]-1]+recur2(idx+1,prev,v);
    }

    if(v[idx] == prev){
        b = hot[v[idx]-1]+recur2(idx+1,v[idx-1],v);
    }else{
        if(idx > 0){
            b = cold[v[idx]-1]+recur2(idx+1,v[idx-1],v);
        }else{
            b = cold[v[idx]-1]+recur2(idx+1,0,v);
        }
    }
    return dp[idx][prev] = min(a,b);
}

// 3d DP
map<vector<ll>,ll> mp;
ll recur(ll idx,ll p1,ll p2,vector<ll> &v){
    if(idx == v.size()){
        return 0;
    }

    if(mp.find({idx,p1,p2}) != mp.end()){
        return mp[{idx,p1,p2}];
    }

    // a : CPU 1
    ll a = 0,b = 0;
    if(p1 == v[idx]){
        a = hot[v[idx]-1]+recur(idx+1,p1,p2,v);
    }else{
        a = cold[v[idx]-1]+recur(idx+1,v[idx],p2,v);
    }

    if(p2 == v[idx]){
        b = hot[v[idx]-1]+recur(idx+1,p1,p2,v);
    }else{
        b = cold[v[idx]-1]+recur(idx+1,p1,v[idx],v);
    }

    return mp[{idx,p1,p2}] = min(a,b);
}

// Consider prev on CPU 1
ll dfs(ll idx,ll prev,vector<ll> &v){
    if(idx == v.size()){
        return 0;
    }

    if(dp[idx][prev] != -1){
        return dp[idx][prev];
    }

    // We can run it on last used CPU
    if(idx > 0 and v[idx] == v[idx-1]){
        return dp[idx][prev] = hot[v[idx]-1]+dfs(idx+1,prev,v);
    }

    // If it's running on some CPU then run it there only
    if(v[idx] == prev){
        return dp[idx][prev] = hot[v[idx]-1]+dfs(idx+1,v[idx-1],v);
    }

    // Can run on any of CPU : either on same or different
    // v[idx-1], since to run curr prgm at idx on CPU 1 we need to run the prev
    // prgm on CPU 2; v[idx-1] since it's previously executed process
    // ye process ko wahan run karao jahan se ans min ayenga,
    // ya toh on same CPU where prev was executed or on the CPU where v[idx-1] 
    // was executed
    return dp[idx][prev] = cold[v[idx]-1]+min(dfs(idx+1,prev,v),dfs(idx+1,v[idx-1],v));
}

void solve()
{
    mp.clear();
    ll n,p;cin>>n>>p;
    dp.assign(n+1,vector<ll> (p+1,-1));
    vector<ll>v(n);enter(v);
    cold.assign(p,0);enter(cold);
    hot.assign(p,0);enter(hot);
    // ll ans = recur(0,0,0,v);
    // ll ans = recur2(0,0,v);
    ll ans = cold[v[0]-1] + dfs(1,v[0],v);
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