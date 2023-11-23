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
    ll q;cin>>q;
    string s;cin>>s;
    vector<pair<ll,pair<ll,ll>>> plus_even(n+1,{0,{0,0}});
    vector<pair<ll,pair<ll,ll>>> plus_odd(n+1,{0,{0,0}});
    vector<pair<ll,pair<ll,ll>>> subs_e(n+1,{0,{0,0}});
    vector<pair<ll,pair<ll,ll>>> subs_o(n+1,{0,{0,0}});

    ll p_e = 0,p_o = 0,s_e = 0,s_o = 0;
    ll p_e_idx = 0,p_o_idx = 0,s_e_idx = 0,s_o_idx = 0;

    for(ll i=0;i<n;i++){
        if((s[i] == '+') and (i%2 == 0)){++p_o;p_o_idx = i+1;}
        else if((s[i] == '+') and (i%2 == 1)){++p_e;p_e_idx = i+1;}
        else if((s[i] == '-') and (i%2 == 0)){++s_o;s_o_idx = i+1;}
        else if((s[i] == '-') and (i%2 == 1)){++s_e;s_e_idx = i+1;}

        if(plus_even[i+1].second.first != 0){
            pair<ll,ll> p = plus_even[i+1].second;
            plus_even[i+1] = {p_e,{p_e_idx,p.first}};
        }else{
            plus_even[i+1] = {p_e,{p_e_idx,0}};
        }

        if(plus_odd[i+1].second.first != 0){
            pair<ll,ll> p = plus_odd[i+1].second;
            plus_odd[i+1] = {p_o,{p_o_idx,p.first}};
        }else{
            plus_odd[i+1] = {p_o,{p_o_idx,0}};
        }

        if(subs_e[i+1].second.first != 0){
            pair<ll,ll> p = subs_e[i+1].second;
            subs_e[i+1] = {s_e,{s_e_idx,p.first}};
        }else{
            subs_e[i+1] = {s_e,{s_e_idx,0}};
        }

        if(subs_o[i+1].second.first != 0){
            pair<ll,ll> p = subs_o[i+1].second;
            subs_o[i+1] = {s_o,{s_o_idx,p.first}};
        }else{
            subs_o[i+1] = {s_o,{s_o_idx,0}};
        }
    }

    // 04-12-22
    // Some minor changes req. to print output
    for(ll i=0;i<q;i++){
        ll l,r;cin>>l>>r;
        // l is odd then start is proper
        p_e = plus_even[r].first - plus_even[l-1].first;
        p_o = plus_odd[r].first - plus_odd[l-1].first;
        s_e = subs_e[r].first - subs_e[l-1].first;
        s_o = subs_o[r].first - subs_o[l-1].first;

        // cout<<p_e<<" "<<p_o<<endl;
        // cout<<s_e<<" "<<s_o<<endl;
        ll a,b;
        if(l & 1){
            // Start by odd idx
            a = (s_e-p_e);
            b = (p_o-s_o);
        }else{
            // l is even then start is sign change
            // Start by even idx
            a = (p_e-s_e);
            b = (s_o-p_o);
        }
        // cout<<a<<" "<<b<<endl;
        a += b;
        // a = abs(a);
        if(a == 0){cout<<a<<endl;continue;}
        
        ll len = (r-l+1);
        if(len&1){
            if(a<0){
                // Remove -e or +o if net is -ve
                if(s_e > 0){
                    l = subs_e[r].second.first;
                }
                else if(p_o > 0){
                    l = plus_odd[r].second.first;
                }
            }else{
                // Remove +e or -o if net is +ve 
                if(s_o > 0){
                    l = subs_o[r].second.first;
                }
                else if(p_e > 0){
                    l = plus_even[r].second.first;
                }
            }
            a = 1;
            cout<<a<<endl;
            cout<<l<<endl;
        }else{
            if(a<0){
                // Remove -e or +o if net is -ve
                if(s_e > 0 and p_o > 0){
                    l = subs_e[r].second.first;
                    r = plus_odd[r].second.first;
                }else if(p_o > 0){
                    l = plus_odd[r].second.first;
                    r = plus_odd[r].second.second;
                }else if(s_e > 0){
                    l = subs_e[r].second.first;
                    r = subs_e[r].second.second;
                }
            }else{
                // Remove +e or -o if net is +ve 
                if(s_o > 0 and p_e > 0){
                    l = subs_o[r].second.first;
                    r = plus_even[r].second.first;
                }
                else if(p_e > 0){
                    l = plus_even[r].second.first;
                    r = plus_even[r].second.second;
                }
                else if(s_o > 0){
                    l = subs_o[r].second.first;
                    r = subs_o[r].second.second;
                }
            }
            a = 2;
            cout<<a<<endl;
            cout<<l<<" "<<r<<endl;
        }
    }
 
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