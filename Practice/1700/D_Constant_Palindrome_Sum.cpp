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
 
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
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
 
/*
We can anytime replace array by sm = (k+1), since
a[i]<=k, so we can always keep same left half & just
change right half...

Operations pssbl are [0,n/2]
But sm of pair : [2,2*k] and so for each sm pssbl,
operations will first decrease & come to min. pt.
then again will increase!!

If both ele >= sm then op += 2
ele op += 1
*/

// Tut :
void solve(){
    ll k,n;cin>>n>>k;
    vector<ll> v(n);enter(v);
    vector<ll> pref(2*k+2,0);
    map<ll,ll> mp;
    for(ll i = 0;i<n/2;++i){
        ll mn_get = min(v[i],v[n-i-1])+1;
        ll mx_get = max(v[i],v[n-i-1])+k;
        mp[v[i]+v[n-i-1]]++;
        pref[mn_get]++;
        pref[mx_get+1]--;
    }

    for(ll i = 1;i<=2*k+1;++i){
        pref[i] += pref[i-1];
    }

    ll ans = n/2;
    for(ll i = 2;i<=2*k;++i){
        ll cnt1 = (pref[i]-mp[i]);
        ll cnt2 = (n/2-pref[i]);
        ll cnt = cnt1+(cnt2*2);
        ans = min(cnt,ans);
    }
    cout<<ans<<endl;return;
}

// My Sol :
void solver()
{
 
    ll n,k;cin>>n>>k;
    vector<ll> v(n);enter(v);
    
    ll ans = n/2;
    // Every pair can be made as sum to (k+1) by n/2 operations 
    map<ll,ll> mp;
    for(ll i=2;i<=2*k;i++){mp[i] = 0;}

    vector<ll> mini,maxi;
    for(ll i = 0;i<n/2;++i){
        mini.push_back(min(v[i],v[n-i-1]));
        maxi.push_back(max(v[i],v[n-i-1]));
        mp[v[i]+v[n-i-1]]++;
    }

    vector<ll> mini_sor(mini),maxi_sor(maxi);
    sort(mini_sor.begin(),mini_sor.end());sort(maxi_sor.begin(),maxi_sor.end());

    for(ll i=2;i<=2*k;i++){
        ll op = n/2; // min. req operations
        // Now check how many operations can be reduced or added for getting 
        // particular k
        if(i <= k){
            // Update maxi for sure & check mini.
            // Update maxi takes op operations
            // To Update mini : find ele>=i
            ll idx = lower_bound(mini_sor.begin(),mini_sor.end(),i)-mini_sor.begin();
            if(idx != (n/2)){
                op += (n/2-idx);
            }
            op -= mp[i];
        }else{
            // Update mini for sure & check maxi if need for updating it too..
            // Update mini = n/2 operations
            // To Update maxi : find ele s.t. any ele in maxi is less than (i-k)... 
            ll idx = upper_bound(maxi_sor.begin(),maxi_sor.end(),i-k-1)-maxi_sor.begin();
            op += idx;
            op -= mp[i];
        }
        ans = min(ans,op);
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