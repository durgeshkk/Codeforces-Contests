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
 
void solve()
{
 
    ll n;cin>>n;
    // Greedy completely fails here & this is the time to think for BS!!
    /*
    map<ll,ll> mp;
    multiset<ll> ms;
    ll ak = 0;
    ll bada = 0;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        ll below = min(n-i-1,a);
        if(ms.size() < 1){
            // cout<<below<<endl;
            ak = max(ak,below);
            bada = max(bada,a);
            mp[a] = 0;continue;
        }
        
        ll val = bada;
        bada = max(bada,a);
        if(val <= below){
            if(mp.find(a) == mp.end()){mp[a] = 0;}
            ak = max(ak,below);
            continue;
        }

        ll mx = 0;  
        for(auto it:mp){
            if(it.first>=(below)){
                mx = max(mx,it.second);
            }
        }

        ll above = min(b,mx+1);
        mp[a] = max(above,mp[a]);
        ll ans = above+below;
        ak = max(ak,ans);
    }
    cout<<ak+1<<endl;*/
    
    // BS :
    /*
    Perform BS on no. of ppl's we can invite to the party
    -->check(x) returns T if I can invite >=x ppl's to the party
    check() can be written using greedy
    check(x) : We need to take x elements & satisfy both conditions for all x
    of them simultaneosly..
    Assume 3 ele can be picked , so 1st ele have :
    0 <= b1 , x-1 <= a1
    1 <= b2 , x-2 <= a2
    2 <= b3 , x-3 <= a3
    */
    vector<ll> a(n),b(n);
    for(ll i= 0;i<n;++i){
        cin>>a[i]>>b[i];
    }

    ll l = 1, r = n+1;
    // Always pssbl to select l ppl's & make them happy
    // it's nvr pssbl to do that for r
    while(l+1 < r){
        ll mid = (l+r)/2;
        ll ok = 0;
        ll take = 0;//abb tk kitne ele liye
        for(ll i = 0;i<n;++i){
            // b[i] >= take is prefix condition 
            // if b[i] = 5 that's ki pehle ke atmost 5 elements can only be selected
            // As of I take ith element no. of taken ele will be (take + 1).
            // So remaining ele I do need to take is mid-(take+1).
            // Thus, a[i] should be >= (mid-take-1)
            if(b[i] >= take and a[i] >= mid-take-1){
                ++take;
            }
        }

        if(take >= mid){ok = 1;}
        if(ok){l = mid;}
        else{r = mid;}
    }
    cout<<l<<endl;
    // 2nd way of BS :
    /*
    ll l = 0,r = n;
    ll ans = 1;
    while(l <= r){
        ll mid = ((l+r)/2);
        ll take = 0;
        for(ll i = 0;i<n;++i){
            if(b[i]>= take and a[i] >= (mid-take-1)){++take;}
            if(take == mid){break;}
        }

        if(take >= mid){
            l = mid+1;
            ans = mid;
        }else{r = mid-1;}
    }
    cout<<(l-1)<<endl;
    */
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