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
 void yno(ll f){
    if(f & 1) cout<<"YES\n";
    else cout<<"NO\n";
    return;
 }
  
void solve()
{
 
    ll n;cin>>n;
    vector<vector<ll>> v(2,vector<ll>(n,0));
    vector<vector<ll>> dp(2,vector<ll>(n,0));
    
    for(ll i=0;i<2;i++){
        forj(n){
            char ch;cin>>ch;
            if(ch == 'B'){v[i][j] = 1;}
            else{v[i][j] = 0;}
        }
    }
    
    if(v[0][n-1]){dp[0][n-1] = 1;}
    if(v[1][n-1]){dp[1][n-1] = 1;}

    for(ll j = n-2;j>=0;--j){
        for(ll i = 0;i<2;++i){
            // Standing on 'W',can't do anything
            // So ans is nt pssbl
            if(!v[i][j]){dp[i][j] = 0;}
            else{
                // Curr cell is 'B', move 
                // So 2 pssbl either move down or right
                if(v[i^1][j]){
                    dp[i][j] = dp[i^1][j+1];
                }else{
                    dp[i][j] = dp[i][j+1];
                }
            }
        }
    }

    if(dp[0][0] || dp[1][0]){yno(1);}
    else{yno(0);}
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

/*
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
 
vector<vector<ll>> v,pref;
vector<vector<ll>> vis,dp;

void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}
 
ll n;
bool issafe(ll i,ll j){
    if(i < 0 || j< 0 || i>=2 || j>=n){return 0;}
    return 1;
}

ll recur(ll i,ll j){
    vis[i][j] = 1;
    if(j == n-1){
        if(v[i][j]){
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[i][j] != -1){return dp[i][j];}
    
    ll a = 0;
    if(issafe(i+1,j) and !vis[i+1][j] and v[i+1][j]){
        a |= recur(i+1,j);
    }
    if(issafe(i,j+1) and !vis[i][j+1] and v[i][j+1]){
        a |= recur(i,j+1);
    }
    if(a & 1){
        cout<<i<<" "<<j<<endl;
    }
    vis[i][j] = 0;
    return dp[i][j] = a;
}

void solve()
{
 
    cin>>n;
    v.assign(2,vector<ll>(n,0));
    dp.assign(2,vector<ll>(n,-1));
    vis.assign(2,vector<ll>(n,0));
    pref.assign(2,vector<ll>(n,0));
    for(ll i=0;i<2;i++){
        forj(n){
            char ch;cin>>ch;
            if(ch == 'B'){v[i][j] = 1;}
            else{v[i][j] = 0;}
        }
    }
    
    for(ll i=0;i<2;i++){
        ll cnt = 0;
        forj(n){
            if(v[i][j]){++cnt;}
            pref[i][j] = cnt;
            // cout<<pref[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<endl;

    ll ans = 0;
    if(v[0][0]){
        ans |= recur(0,0);
    }
    // cout<<ans<<endl;
    vis.clear();dp.clear();

    dp.assign(2,vector<ll>(n,-1));
    vis.assign(2,vector<ll>(n,0));
    if(v[1][0]){
        ans |= recur(1,0);
    }
    if(ans){yno(1);}
    else{yno(0);}
    return;

    // ll tot = pref[0][n-1]+pref[1][n-1];
    // cout<<tot<<endl;
    // 'W' 'W' in a col
    // forj(n){
    //     if(!v[0][j] and !v[1][j]){
    //         ll cntr = pref[0][j]+pref[1][j];
    //         if(cntr != tot){yno(0);return;}
    //     }
    // }
    
    // Col with BW
    ll o = 0,e = 0,oo = 0,ee = 0;
    forj(n){
        if(v[0][j] and !v[1][j]){
            if(j & 1){o = 1;++oo;}
            else{e = 1;++ee;}
        }
    }

    // Col with WB
    ll o2 = 0,e2 = 0,oo2 = 0,ee2 = 0;
    forj(n){
        if(!v[0][j] and v[1][j]){
            if(j & 1){o2 = 1;++oo2;}
            else{e2 = 1;++ee2;}
        }
    }

    if(((e+o2) > 1) || ((e2+o) > 1)){
        yno(0);return;
    }

    if(oo2 >= 2 || ee2 >= 2 || oo >=2 || ee >=2){
        yno(0);return;
    }

    yno(1);

    // for(ll j = 1;j<n-1;++j){
    //     if(v[0][j] and v[1][j]){
    //         if((v[0][j-1] == v[0][j+1]) and (v[1][j-1] == v[1][j+1]) and (v[0][j-1] != v[1][j-1])){
    //             yno(0);return;
    //         }
    //     }
    // }

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
}*/