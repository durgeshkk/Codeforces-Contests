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
 
/*
Can't visit any cell twice :
So, optimal paths are :
1. Covering all the corners starting from right,then lastly down & left to visit
(2,m)
2. Covering all the corners starting from down,covering all right,then up & then 
all left to reach (1,2)
*/
vector<vector<ll>> vis,v;
ll n;

bool safe(ll i,ll j){
    if(i >= 2 || i < 0 || j>=n || j<0){return 0;}
    return 1;
}

ll recur(ll i,ll j){



    ll x = 0,y = 0,z = 0,a = 0;
    // D
    if(safe(i+1,j) and !vis[i+1][j]){
        vis[i+1][j] = 1;
        x = recur(i+1,j);
    }

    // U
    if(safe(i-1,j) and !vis[i-1][j]){
        y = recur(i-1,j);
    }

    // L
    if(safe(i,j-1) and !vis[i][j-1]){
        z = recur(i,j-1);
    }

    // R
    if(safe(i,j+1) and !vis[i][j+1]){
        a = recur(i,j+1);
    }
    return min({x,y,z,a});
}

ll dfs(ll i,ll j,ll zig_zag,ll tym){
    if(!safe(i,j)){return 0;}
    if(vis[i][j]){return 0;}
    vis[i][j] = 1;

    tym = max(tym,v[i][j]);

    ll a= LLONG_MAX,b = LLONG_MAX;
    if((i+j) & 1){
        if(i & 1){
            // Call Up
            if(zig_zag != 0){
                a = dfs(i-1,j,zig_zag,tym+1);
            }

            // Call Right & end zigzag
            b = dfs(i,j+1,0,tym+1);
        }else{
            a = dfs(i+1,j,zig_zag,tym+1);
        }
    }else{
        if(i & 1){
            b = dfs(i,j+1,zig_zag,tym+1);
        }else{
            // Call Down
            if(zig_zag != 0){
                a = dfs(i+1,j,1,tym+1);
            }

            // Call Right
            b = dfs(i,j+1,0,tym+1);
        }
    }
    return min({a,b});
}

void solve()
{
 
    cin>>n;
    v.assign(2,vector<ll> (n,0));
    vector<vector<ll>> dp(2,vector<ll> (n,0));
    vector<vector<ll>> dp2(2,vector<ll> (n,0));
    vis.assign(2,vector<ll> (n,0));
 
    for(ll i=0;i<2;i++){forj(n){cin>>v[i][j];}}
    
    // Cover path 1
    ll tym = 1;
    for(ll i = 1;i<n;++i){
        if(v[0][i] > tym){
            tym = v[0][i];
        }else{
            ++tym;
        }
    }
    // cout<<tym<<" ";

    for(ll i = n-1;i>=0;--i){
        if(v[1][i] > tym){
            tym = v[1][i];
        }else{
            ++tym;
        }
    }
    // cout<<tym<<endl;
    ll t = tym;
    for(ll i = 0;i<n;++i,--t){
        dp[0][i] = t;
    }

    for(ll i = n-1;i>=0;--i,--t){
        dp[1][i] = t;
    }

    for(ll i = 0;i<n;++i){
        cout<<dp[0][i]<<" ";
    }cout<<endl;
    for(ll i = 0;i<n;++i){
        cout<<dp[1][i]<<" ";
    }cout<<endl;

    // Path 2
    ll tym2 = 1;
    for(ll i = 0;i<n;++i){
        if(v[1][i] > tym2){
            tym2 = v[1][i];
        }else{
            ++tym2;
        }
    }
    // cout<<tym2<<" ";

    for(ll i = n-1;i>0;--i){
        if(v[0][i] > tym){
            tym2 = v[0][i];
        }else{
            ++tym2;
        }
    }

    t = tym2-1;
    for(ll i = 0;i<n;++i,--t){
        dp2[1][i] = t;
    }

    for(ll i = n-1;i>0;--i,--t){
        dp2[0][i] = t;
    }


    for(ll i = 0;i<n;++i){
        cout<<dp2[0][i]<<" ";
    }cout<<endl;
    for(ll i = 0;i<n;++i){
        cout<<dp2[1][i]<<" ";
    }cout<<endl;

    // Path 3 : |_|``|_| and so on..

    ll ans = min(tym,tym2);
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