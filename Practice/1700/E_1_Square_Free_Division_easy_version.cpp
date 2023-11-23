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
#define MAXN   (ll)(1e7+5)
ll spf[MAXN];
void sieve(){
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
vector<ll> getFactorization(ll x)
{
    set<ll> ret;
    while (x != 1){
        if(ret.find(spf[x]) != ret.end()){
            ret.erase(ret.find(spf[x]));
        }else{
            ret.insert(spf[x]);
        }
        x = x / spf[x];
    }

    vector<ll> tmp(all(ret));
    return tmp;
}
 
vector<ll> printDivisors(ll n)
{
    vector<ll> tmp;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if (n / i == i){
                tmp.push_back(i);
            }
            else {
                tmp.push_back(i);
                tmp.push_back(n/i);
            }
        }
    }
    return tmp;
}

unordered_map<ll,ll> sq;
void perfect_sq(){
    for(ll i = 1;i*i<=(1e7);++i){
        sq[i*i]++;
    }
    return;
}

void solve(){
 
    ll n,k;cin>>n>>k;
    vector<ll> v(n);enter(v);
    
    ll ans = 0;
    vector<map<ll,ll>> fac(n);
    for(ll i = 0;i<n;++i){
        ll ele = v[i];
        while(spf[ele] != 1){
            fac[i][spf[ele]]++;
            ele /= spf[ele];
        }
    }

    map<ll,ll> has;
    for(ll i = 0;i<n;++i){
        ll odd_freq = 1;// 2nd no. requirement
        for(auto x: fac[i]){
            if(x.second & 1){
                odd_freq *= x.first;
            }
        }
        if(has.find(odd_freq) != has.end()){
            ++ans;has.clear();
        }
        has[odd_freq]++;
    }
    /*
    map<ll,ll> mp;
    unordered_set<ll> s;
    for(auto it:v){
        vector<ll> tmp = printDivisors(it);
        ll f = 0;
        for(auto &x:tmp){
            double a = sqrt(1.0*x);
            ll b = sqrt(1.0*x);
            if(a == b){
                if(s.find(it/x) != s.end()){
                    s.clear();
                    f = 1;
                    ++ans;
                    break;
                }else{
                    s.insert(it/x);
                }
            }
        }
        
        if(f & 1){
            // Traverse again
            for(auto &x:tmp){
                double a = sqrt(1.0*x);
                ll b = sqrt(1.0*x);
                if(a == b){
                    s.insert(it/x);
                }
            }
        }
    }*/
    /*    
    for(ll i=0;i<n;i++){
        if(v[i] == 1){mp.clear();++ans;continue;}
        vector<ll> tmp = getFactorization(v[i]);
        ll f = 0;
        for(auto it:tmp){
            mp[it]++;
            if(mp[it] == 2){
                f = 1;
                ++ans;mp.clear();
            }
        }
        if(f & 1){
            for(auto it:tmp){
                mp[it]++;
            }
        }
    }*/
    cout<<(ans+1)<<endl;
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
   sieve();
//    perfect_sq();
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