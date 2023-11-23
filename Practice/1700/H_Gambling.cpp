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
 
void solve()
{
 
    ll n;cin>>n;
    vector<ll> v(n);enter(v);
    
    // Fails on TC :
    // 9
    // 1 1 2 2 2 2 1 1 2
    // Ans must be 3-7 gives 3-9
    /*
    map<ll,ll> freq;
    map<ll,pair<ll,ll>> mp;//to store starting as well as ending idx

    for(ll i=0;i<n;i++){
        if(freq.find(v[i]) == freq.end()){
            mp[v[i]] = {i,i};
        }else{
            auto p = mp[v[i]];
            mp[v[i]] = {p.first,i};
        }
        freq[v[i]]++;
    }

    // For each n every element calculate it's freq & len!! Jiska sabse jyada vo ans
    ll l = -1,r = -1,a = -1,mx = 0;
    for(auto it:freq){
        ll occur = it.second;
        auto p = mp[it.first];
        ll len = (p.second-p.first+1);
        ll remove = len-occur;
        if(mx < (occur-remove)){
            mx = (occur-remove);
            a = it.first;
            l = p.first+1;
            r = p.second+1;
        }
    }

    cout<<a<<" "<<l<<" "<<r<<endl;
    return;*/

    // Sol1 :

    vector<ll> dp(n,1);
    map<ll,ll> pos;
    ll profit = 0,idx = -1;
    for(ll i = 0;i<n;++i){
        if(pos.count(v[i])){
            // prev position - between ele
            dp[i] = max(dp[i],dp[pos[v[i]]] + 1 -(i-pos[v[i]]-1));
        }

        if(dp[i] > profit){
            profit = dp[i];
            idx = i;
        }

        pos[v[i]] = i;
    }

    ll r = idx,l = idx;
    ll p = v[l];
    while(profit){
        if(v[l] == p){
            --profit;
        }else{
            ++profit;
        }
        --l;
    }
    cout<<p<<" "<<l+2<<" "<<r+1<<endl;
    return;
    // Sol 2:
    /*
    map<ll,vector<ll>> mp;
    for(ll i = 0;i<n;++i){
        mp[v[i]].push_back(i);
    }

    ll l = -1,r = -1,a = -1,mx = -1;
    for(auto it:mp){
        vector<ll> z = it.second;
        if(z.size() == 1){
            if(mx == -1){
                l = z[0],r = z[0],a = it.first;
            }
            continue;
        }
        // cout<<it.first<<" -> ";
        // show(z);
        
        // cout<<"------\n";
        ll val = 1;
        ll start = z[0];

        for(ll i = 1;i<z.size();++i){
            ll gap = (z[i]-z[i-1]-1);
            if(val-gap > 0){
                val = val - gap + 1;
            }else{
                val = 1;
                start = z[i];
            }

            if(val > mx){
                mx = val;
                a = it.first;
                l = start;
                r = z[i];
            }*/
            // Optimise inner loop
            /*
            for(ll j = i+1;j<z.size();++j){

                ll o = (j-i+1);
                ll len = (z[j]-z[i]+1);
                ll rem = (len-o);

                // cout<<i<<" "<<j<<" "<<len<<" "<<o<<" "<<rem<<endl;
                if(mx < (o-rem)){
                    mx = (o-rem);
                    l = z[i];r = z[j];a = it.first;
                    // cout<<"--\n";
                    // cout<<mx<<" "<<l<<" "<<rem<<" "<<a<<endl;
                    // cout<<"--\n";
                }
            }*/
    /*
        }
        // cout<<"------\n";
    }

    if(a == -1){
        cout<<v[0]<<" "<<(1)<<" "<<(1)<<endl;return;
    }else if(mx == 0){
        cout<<a<<" "<<(l+1)<<" "<<(l+1)<<endl;return;
    }else{
        cout<<a<<" "<<(l+1)<<" "<<(r+1)<<endl;return;
    }*/
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

