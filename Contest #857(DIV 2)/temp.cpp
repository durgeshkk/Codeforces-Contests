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
vector<pair<ll,ll>> v;
vector<vector<ll>> dp;
ll recur(ll idx,ll mx,ll mx2){
    if(idx == v.size()){
        return (mx-mx2);
    }

    // Pick 1st element
    ll a = 0,b = 0;
    if(v[idx].first > mx){
        a = recur(idx+1,v[idx].first,mx);
    }else if(v[idx].first > mx2){
        a = recur(idx+1,mx,v[idx].first);
    }else{
        a = recur(idx+1,mx,mx2);
    }

    // Pick 2nd element
    if(v[idx].second > mx){
        b = recur(idx+1,v[idx].second,mx);
    }else if(v[idx].first > mx2){
        b = recur(idx+1,mx,v[idx].second);
    }else{
        b = recur(idx+1,mx,mx2);
    }
    return min(a,b);
}

void solve(){
    v.clear();
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        v.push_back({a,b});
    }

    // dp.assign(n+1,vector<ll> (3,-1));
    pair<ll,ll> dk[n+1][2];
    for(ll i = 0;i<=n;++i){
        dk[i][0] = {0,0};dk[i][1] = {0,0};
    }

    for(ll i = 1;i<=n;++i){
        auto p = dk[i-1][0];auto p1 = dk[i-1][0];
        auto p2 = dk[i-1][1];auto p3 = dk[i-1][1];

        // Dont consider 1st element
        if(v[i-1].second >= p.first){
            p.second = p.first;
            p.first = v[i-1].second;
        }else{
            p.second = max(p.second,v[i-1].second);
        }

        if(v[i-1].second >= p2.first){
            p2.second = p2.first;
            p2.first = v[i-1].second;
        }else{
            p2.second = max(p2.second,v[i-1].second);
        }

        if((p.first-p.second) > (p2.first-p2.second)){
            dk[i][0] = p2; 
        }else if((p.first-p.second) == (p2.first-p2.second)){
            if(p.first > p2.first){
                dk[i][0] = p; 
            }else{
                dk[i][0] = p2; 
            }
        }else{
            dk[i][0] = p; 
        }

        // Consider this 1st element
        p = p1,p2 = p3;
        if(v[i-1].first >= p.first){
            p.second = p.first;
            p.first = v[i-1].first;
        }else{
            p.second = max(p.second,v[i-1].first);
        }

        if(v[i-1].first >= p2.first){
            p2.second = p2.first;
            p2.first = v[i-1].first;
        }else{
            p2.second = max(p2.second,v[i-1].first);
        }

        if((p.first-p.second) > (p2.first-p2.second)){
            dk[i][1] = p2; 
        }else if((p.first-p.second) == (p2.first-p2.second)){
            if(p.first > p2.first){
                dk[i][1] = p; 
            }else{
                dk[i][1] = p2; 
            }
        }else{
            dk[i][1] = p; 
        }
    }

    auto p = dk[n][0];
    auto p2 = dk[n][1];
    ll ans = min(p.first-p.second,p2.first-p2.second);
    // ll ans = recur(0,0,0);
    cout<<ans<<endl;
    return;
} 

void solver()
{
 
    ll n;cin>>n;
    vector<pair<ll,ll>> v;
    multiset<ll> ms,frnt;
    for(ll i=0;i<n;i++){
        ll a,b;cin>>a>>b;
        ms.insert(b);
        v.push_back({a,b});
    }
 
    sort(all(v));
    ll ans = LLONG_MAX; 
    for(ll i=0;i<n;i++){
        ms.erase(ms.find(v[i-1].second));
        // Consider v[i-1].first is max for friend 1
        // Pssbl max for frnd 2
        // 1. bring max from below : (i+1,n)
        ll mx = LLONG_MAX,b = 0,c = 0;
        if(i < n-1){
            mx = *ms.rbegin();
            // ans = min(ans,abs(mx-v[i-1].first));
        }

        // 2. Take lb & ub from above
        if(i != 0){
            auto it = frnt.lower_bound(v[i-1].first);
            if(it != frnt.begin()){
                --it;
            }
            auto it2 = frnt.upper_bound(v[i-1].first);
            if(it2 == frnt.end()){
                --it2;
            }
            b = *it,c = *it2;
        }

        if(mx == LLONG_MAX){
            ans = min(ans,min(abs(b-v[i-1].first),abs(c-v[i-1].first)));
        }else{
            if(i == 0){
                ans = min(ans,abs(mx-v[i-1].first));
            }else{
                ll ak = min(abs(b-v[i-1].first),abs(c-v[i-1].first));
                ll dk = abs(mx-v[i-1].first);
                ans = min(ans,max(ak,dk));
            }
        }
        frnt.insert(v[i-1].second);
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