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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
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
 
bool isPrime(int n){
   if (n <= 1)
       return false;
   for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    int low = 0;
    int high = str.length() - 1;

    while (low < high)
    {
        // if a mismatch happens
        if (str[low] != str[high]) {
            return false;
        }

        low++;
        high--;
    }

    return true;
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
 
 
ll fact[100005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=100005;++i){
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
 
vector<ll> adj[100004];
 
void bfs(){
    queue<pair<ll,ll>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        ll node = it.first;
        ll par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
ll height;
ll subtree[100005];
ll lev[100005];
ll parent[200005];
 
void dfs(ll node, ll par, ll level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    ll sm = 0;
 
    parent[node] = par;
    for(auto it:adj[node]){
        if(it != par){
            dfs(it,node,level+1);
            sm += subtree[it];
        }
    }
    subtree[node] = 1+sm;
}
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

ll dp[1001][1001][2];
ll recur(ll curr_mirror,ll decay,ll n,ll k,ll direxn){
    // direxn = 1 --> Clkwise
    if(k == 1){return 1;}
    if(n == 1){return 2;}
    if((decay == 0) || (curr_mirror > n) || (curr_mirror <= 0)){return 0;}

    if(dp[curr_mirror][decay][direxn] != -1){
        return dp[curr_mirror][decay][direxn];
    }

    ll ans = 2;
    if(direxn == 1){
        // Hit
        if(curr_mirror > 1){
            ll val = recur(curr_mirror-1,decay-1,n,k,direxn^1)-1;
            ans = mod_add(ans,val,mod);
        }
        // Not Hit
        if(curr_mirror<n){
            ll val = recur(curr_mirror+1,decay,n,k,direxn)-1;
            ans = mod_add(ans,val,mod);
        }
        dp[curr_mirror][decay][direxn] = ans;
    }else{
        // Hit
        if(curr_mirror < n){
            ll val = recur(curr_mirror+1,decay-1,n,k,direxn^1)-1;
            ans = mod_add(ans,val,mod);
        }
        // Not Hit
        if(curr_mirror>1){
            ll val = recur(curr_mirror-1,decay,n,k,direxn)-1;
            ans = mod_add(ans,val,mod);
        }
        dp[curr_mirror][decay][direxn] = ans;
    }
    return ans;
}
// My 3 D dp :
    /*
    ll a,b;
    if(direxn == 0){

        // Hit 
        // a = 1+dp[curr_mirror-1][decay-1][direxn^1]; 
        if(dp[curr_mirror-1][decay-1][direxn^1] != -1){
            a = dp[curr_mirror-1][decay-1][direxn^1];
        }else{
            a = 1+recur(curr_mirror-1,decay-1,n,k,direxn^1);
            dp[curr_mirror-1][decay-1][direxn^1] = a;
        }
        // Not Hit
        // b = recur(curr_mirror+1,decay,n,k,direxn);
        if(dp[curr_mirror+1][decay][direxn] != -1){
            b = dp[curr_mirror+1][decay][direxn];
        }else{
            b = recur(curr_mirror+1,decay,n,k,direxn);
            dp[curr_mirror+1][decay][direxn] = b;
        }
    }else{
        // Hit
        if(dp[curr_mirror+1][decay-1][direxn^1] != -1){
            a = dp[curr_mirror+1][decay-1][direxn^1];
        }else{
            a = 1+recur(curr_mirror+1,decay-1,n,k,direxn^1);
            dp[curr_mirror+1][decay-1][direxn^1] = a;
        }
        // Not Hit
        if(dp[curr_mirror-1][decay][direxn] != -1){
            b = dp[curr_mirror-1][decay][direxn];
        }else{
            b = recur(curr_mirror-1,decay,n,k,direxn);
            dp[curr_mirror-1][decay][direxn] = b;
        }
    }
    return dp[curr_mirror][decay][direxn] = mod_add(a,b,mod);*/

// DP to the Rescue !! 
void solve()
{
    ll n;ll k;cin>>n>>k;
    for(ll i = 0;i<1001;++i){
        for(ll j = 0;j<1001;++j){
            for(ll k = 0;k<2;++k){
                dp[i][j][k] = -1;
            }
        }
    }

    ll direxn = 1;//Clkwise
    ll ans = recur(1,k,n,k,direxn);
    cout<<ans<<endl;
    return;
}

// Tried maths but failed !!
/*
void solve()
{
    ll n,k;cin>>n>>k;
    if(k == 1){
        cout<<1<<endl;
        return;
    }
    if(n == 1){
        cout<<2<<endl;
        return;
    }
    
    ll ans = (n+1);
    ll sm = 0;
    k -= 2;--n;
    vector<ll> addup(n,0);
    for(ll j = 0;j<n;++j){
        addup[n-j-1] = (j+1);
        sm += (j+1);
    }
    // show(addup);

    if(k >= 1){
        ans = mod_add(sm,ans,mod);
        --k;
    }

    for(ll i = 0;i<k;++i){
        vector<ll> tmp(n,0);
        tmp[0] = sm;
        sm = 0;

        ll k = 1;
        for(ll j = n-1;j>0;--j,++k){
            tmp[k] = tmp[k-1] - addup[j];
        }

        for(ll j = 0;j<n;++j){
            addup[j] = tmp[j];
            sm = mod_add(sm,addup[j],mod);
            ans = mod_add(addup[j],ans,mod);
        }
        // show(addup);
    }
    cout<<ans<<endl;
    return;
}
 */

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