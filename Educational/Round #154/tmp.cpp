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
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
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

long long maxSum(vector<int>& v, int m, int k) {
    map<ll,ll> mp;set<ll> s;
    ll sm = 0;
    for(ll i =0;i<k;++i){
        s.insert(v[i]);mp[v[i]]++;
        sm += v[i];
    }

    ll ans = 0,n = v.size();
    ll j = 0;
    for(ll i = k;i<n;++i,++j){
        mp[v[j]]--;sm -= v[j];
        if(mp[v[j]] == 0){
            s.erase(s.find(v[j]));
        }

        mp[v[i]]++;s.insert(v[i]);sm += v[i];
        if(s.size() >= m){
            ans = max(ans,sm);
        }
    }
    return ans;
}

ll n,k;
string tmp;    
vector<ll> freq;
vector<vector<ll>> dp; 
ll recur(ll idx,ll cntr){
    if(cntr == k){return 0;}
    if(idx == n){return LLONG_MIN;}

    if(dp[idx][cntr] != -1){
        return dp[idx][cntr];
    }

    ll np = recur(idx+1,cntr);
    ll p = LLONG_MIN;
    ll sa = recur(idx+1,cntr+1); 
    if(sa != LLONG_MIN){
        ll val = freq[tmp[idx]-'a'];
        p = mod_add(sa,val,mod);
    }
    return dp[idx][cntr] = max(np,p);
}

ll ans,mx;
ll recur2(ll idx,ll cntr,ll dk){
    if(cntr == k){
        if(dk == mx){++ans;}
        return 0;
    }
    if(idx == n){return LLONG_MIN;}

    if(dp[idx][cntr] != -1){
        return dp[idx][cntr];
    }

    ll np = recur2(idx+1,cntr,dk);
    ll p = LLONG_MIN;
    ll sa = recur2(idx+1,cntr+1,dk+freq[tmp[idx]-'a']); 
    if(sa != LLONG_MIN){
        ll val = freq[tmp[idx]-'a'];
        p = mod_add(sa,val,mod);
    }
    return dp[idx][cntr] = max(np,p);
}


ll dfs(ll idx,ll cntr){

}

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

ll fact[200005];
ll powfact[200005];
void precomputefact(ll n){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=n;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}

int countKSubsequencesWithMaxBeauty(string s, int m) {
    precomputefact(s.size()+5);
    vector<ll> mp(27,0);
    for(auto it:s){
        mp[it-'a']++;
    }

    ll sm = 0;
    sort(all(mp));
    reverse(all(mp));
    for(ll i = 0;i<k;++i){
        sm += mp[i];
    }
    map<ll,ll> freq;
    for(auto it:mp){freq[it]++;}

    ll mn_f = mp[k-1];
    ll ans = 1,picked = 0;
    for(ll i = 0;i<k;++i){
        if(mp[i] == mn_f){break;}
        else{ans = mod_mul(ans,mp[i],mod);++picked;}
    }

    ll hve = freq[mn_f];
    ll sa = nCr(hve,k-picked);
    ans = mod_mul(ans,sa,mod);
    return ans;
}

/*
"bcca"
2
"abbcd"
4
"lelxul"
1
"ffcsdqcnkr"
2
*/

int countKSubsequencesWithMaxBeauty(string s, int m) {
    tmp.clear();
    freq.assign(27,0);
    dp.assign(n+5,vector<ll> (k+5,-1));
    ans = 0,mx = 0;
    set<ll> st;
    for(auto it:s){
        st.insert(it);
        freq[it-'a']++;
    }   

    for(auto it:st){
        tmp += it;
    }
    n = tmp.size();k = 1ll*m;
    mx = recur(0,0); 
    recur2(0,0,0);
    return ans;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);
 
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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