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
map<char,ll> mp;
void pre(){
    ll ok = 1;
    for(char i = 'A';i<='E';++i){
        mp[i] = ok;ok *= 10;
    }
} 

void solve()
{
    string s;cin>>s;
    ll n = s.size();
    multiset<char> ms(all(s));

    ll sm = 0;
    vector<ll> suff;
    for(ll i=0;i<n-1;i++){
        char ch = s[i];
        ms.erase(ms.find(ch));
        if(*ms.rbegin() > ch){
            sm -= mp[ch];
        }else{
            sm += mp[ch];
        }
        suff.push_back(sm);
    }
    sm += mp[s[n-1]];
    suff.push_back(sm);

    for(ll i=0;i<n-1;i++){
        ms.insert(s[i]);
    }

    ll ans = sm;
    map<char,ll> ayya;
    for(ll i = 0;i<n;++i){
        ll badme = (sm - suff[i]);
        ms.erase(ms.find(s[i]));
        char big = *ms.rbegin();
        for(char ch = 'A';ch<='E';++ch){
            ll udda = 0;
            for(auto it:ayya){
                if(it.first < big){continue;}
                if(it.first < ch){
                    udda += mp[it.first];
                }
            }
            udda *= 2;
            ll sa = 0;
            if(i>0){sa = suff[i-1];}
            sa -= udda;
            sa += badme;
            // Now check if curr char is +/-
            if(ch < big){
                sa -= mp[ch];
            }else{
                sa += mp[ch];
            }
            ans = max(ans,sa);
        }
        ayya[s[i]]++;
    }

    ll sa = 0;
    for(char ch = 'A';ch<='E';++ch){
        ll udda = 0;
        for(auto it:ayya){
            if(it.first < ch){
                udda += mp[it.first];
            }
        }
        udda *= 2;
        ll sa = 0;
        sa = suff[n-1];
        sa -= udda;
        sa += badme;
        // Now check if curr char is +/-
        if(ch < big){
            sa -= mp[ch];
        }else{
            sa += mp[ch];
        }
        ans = max(ans,sa);
    }
    cout<<ans<<endl;














    map<char,ll> till_now;
    ll ans = sm;
    for(ll i=0;i<n-1;i++){
        // Try to change the curr char & get 
        // the max ans
        ms.erase(ms.find(s[i]));
        ll sa = sm;
        if(*ms.rbegin() > s[i]){
            sa += mp[s[i]];
        }else{
            sa -= mp[s[i]];
        }

        char bada = *ms.rbegin();
        for(char ch = 'A';ch <= 'E';++ch){
            ll ag = sa;
            if(bada > ch){
                ag -= mp[ch];
            }else{
                ag += mp[ch];
            }
        
            for(auto it:till_now){

            }

            ans = max(ans,ag);
            if(ag == 12098){
                cout<<i<<" "<<ch<<endl;
            }
        }

        till_now[s[i]]++;
    }

    // Check for the last char update
    ll sa = sm;
    sa -= mp[s[n-1]];
    for(char ch = 'A';ch <= 'E';++ch){
        ll ag = sa;
        ag += mp[ch];
        ans = max(ans,ag);
    }
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   pre();
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