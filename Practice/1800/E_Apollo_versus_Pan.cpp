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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
/*
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
/*
(xi&xj).(xj | xk);
(xj | xk) : This part is a obs. part; 
-> We calculate "OR" of complete array & keep the no. of set bits & then at each 
idx we simply maximise all the bits set at particular v[i] & then perform adder 
from 0 to 60 bits
Like : OR = 0,0,5,2,3
fixing j at idx, where v[j] = 4 
*/ 

vector<ll> x(125,1);
void fun(){
    forj(125){
        x[j] = power(2,j,mod);
    }
}

ll n;
vector<ll> a;
void solve(int tc = 0) {
	cin >> n;
    a.assign(n,0);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	ll cnt[62] = {0};
	
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 62; j++) {
			if (a[i] & (1LL << j)) ++cnt[j];
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll av = 0;
		for (ll j = 0; j < 62; j++) {
			if (a[i] & (1LL << j)) {
				ll p = (1LL << j) % mod;
				av = (av + p * cnt[j]) % mod;
			}
		}
		
		ll ov = 0;
		
		for (ll j = 0; j < 62; j++) {
			ll p = (1LL << j) % mod;
			if (a[i] & (1LL << j)) {
				ov = (ov + p * n) % mod;
			} else {
				ov = (ov + p * cnt[j]) % mod;
			}
		}
		
		ans = (ans + av * ov) % mod;
	}
	
	cout << ans << '\n';
}

void solver()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    /*
    ll dk = 0;
    for(ll i = 0;i<n;++i){
        forj(n){
            for(ll k = 0;k<n;++k){
                ll sa = (v[i]&v[j]);
                ll sa2 = (v[j]|v[k]);
                ll sa3 = mod_mul(sa,sa2,mod);
                dk = mod_add(dk,sa3,mod);
            }
        }
    }
    cout<<dk<<endl;
    return;*/

    
    vector<ll> set(75,0);
    for(ll i=0;i<n;i++){
        bitset<75> b(v[i]);
        forj(75){
            if(b[j]){set[j]++;}
        }
    }

    // show(set);

    // map<ll,ll> mp;
    vector<ll> mp(n+1,0);

    // Go for final Ans & also "AND" op.
    ll ans = 0;
    for(ll i = 0;i<n;++i){
        bitset<75> b(v[i]);
        ll sa = 0;
        forj(75){
            if(b[j]){
                ll st = set[j];
                // ll ok = power(2,j,mod);
                ll ok = x[j];
                ok = mod_mul(ok,st,mod);
                sa = mod_add(sa,ok,mod);
            }
        }
        mp[i] = sa;
    }

    // show(mp);

    for(ll i=0;i<n;i++){
        vector<ll> tmp(set);
        bitset<75> b(v[i]);
        ll sa = 0,carry = 0;
        forj(75){
            if(b[j]){
                // tmp[j] = n;
                ll sa2 = mod_mul(n,x[j],mod);
                sa = mod_add(sa,sa2,mod);
            }else{
                ll sa2 = mod_mul(set[j],x[j],mod);
                sa = mod_add(sa,sa2,mod);
            }
        }
        /*
        for(ll j = 0;j<75;++j){
            ll ok = carry+tmp[j];
            if(ok & 1){
                tmp[j] = 1;
                // sa += power(2,j,mod);
                // sa %= mod;
            }else{
                tmp[j] = 0;
            }
            carry = (ok/2);
        }
        // cout<<i<<" "<<sa<<endl;*/
        sa = mod_mul(sa,mp[i],mod);
        ans = mod_add(ans,sa,mod);
        // mp[i] = sa;
    }
    // cout<<endl;
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
    fun();
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