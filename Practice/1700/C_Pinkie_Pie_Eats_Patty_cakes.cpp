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
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
 
vector<ll> freq(100005,0);
bool check(ll dist,vector<pair<ll,ll>> v,ll n){
    for(ll j = 0;j<=n;++j){freq[j] = 0;}
    set<pair<ll,ll>> s;
    for(ll j = 0;j<v.size();++j){freq[v[j].first] = v[j].second;s.insert({v[j].second,v[j].first});}

    // Learning:
    vector<ll> tmp(n,0);
    for(ll j = 0;j<n;++j){
        if(j >= dist and (freq[tmp[j-dist]] > 0)){
            s.insert({freq[tmp[j-dist]],tmp[j-dist]});
        }

        if(s.empty()){return false;}
        auto p = *s.rbegin();
        s.erase(s.find(p));
        tmp[j] = p.second;
        freq[p.second]--;
    }
    return true;
}

void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    map<ll,ll> mp;ll mx = 0;
    for(ll i=0;i<n;i++){mp[v[i]]++;mx = max(mx,mp[v[i]]);}

    // Solution 1:
    /*
    multiset<pair<ll,ll>> ms;
    for(auto it:mp){ms.insert({it.second,it.first});}

    vector<pair<ll,ll>> tmp;
    while(!ms.empty()){
        auto p = *ms.rbegin();
        ms.erase(ms.find(p));
        tmp.push_back({p.second,p.first});
    }
 
    ll l=0,r = n-1,ans = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(mid == 0 || check(mid,tmp,n)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<(r-1)<<endl;*/
    
    // Maths in Action:
    /*
    // When we have only 1 element of mx_freq;
    Place the elements with maximum freq & then we will have sections as (mx_freq-1)
    So, ans = (n-mx)/(mx-1);
    e.g. 1 1 1 2 3 4 5
    Arrangement : 1 2 3 1 4 5 1 ==> mx = 3, remain ele = n-3, segments we have = mx-1

    // Multiple ele with Mx freq :
    e.g. 1 1 2 2 3 3 4 5 6
    Now lets try to shift this mx_freq ele 1 by the cnt of ele having same freq
    i.e. 1 b4 = n-1 but now 2 & 3 also have same freq, so 1 : n-1->(n-1-2),
    -2 due to 2 & 3
    In short, lets grp {1,2,3} together & then place 4 5 6
    So, ans = (n-mx-cnt)/(mx-1);
    */
   ll cnt = 0;
   for(auto it:mp){if(it.second==mx){++cnt;}}
   --cnt;// repeating rather than mx_freq ele
   ll ans = (n-mx-cnt)/(mx-1);cout<<ans<<endl;
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