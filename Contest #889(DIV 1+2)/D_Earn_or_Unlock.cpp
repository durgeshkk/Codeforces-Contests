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
vector<ll> v,pref,dp;
ll n;
ll recur(ll idx,ll open){
    if(idx > 0){
        pref[idx] += pref[idx-1];
    }

    if(idx == n || (pref[idx] == 0 and idx != 0)){return 0;}

    ll &sa = dp[idx];
    if(sa != -1){return sa;}

    // Unlock x cards
    ll a = 0;
    if(v[idx] > 0){
        pref[min(open+1,n)] += 1;
        pref[min(open+v[idx]+1,n)] -= 1;
        cout<<open<<" a : ";
        show(pref);
        a = recur(idx+1,min(open+v[idx],n));
        cout<<"a "<<a<<endl;
        pref[min(open+1,n)] -= 1;
        pref[min(open+v[idx]+1,n)] += 1;
        cout<<open;
        cout<<" a end : ";
        show(pref);
    }

    // Get x points
    pref[idx] -= pref[idx-1];
    ll b = v[idx]+recur(idx+1,open);
    cout<<"b : ";
    show(pref);
    return sa = max(a,b);
} 


void recur_solve()
{
 
    cin>>n;
    pref.assign(n+5,0);
    dp.assign(n+5,-1);
    vector<ll> tmp(n);enter(tmp);
    for(auto it:tmp){v.push_back(it);}
    
    ll ans=  v[0];
    if(v[0]){
        pref[1] += 1;
        pref[min(v[0]+1,n)] -= 1;
        show(pref);
        ans = max(ans,recur(1,min(v[0],n)));
    }
    cout<<ans<<endl;
    return;
}
 
const ll N = 2e5+5;  
bitset<N> b;
bitset<N> c;

/*
For each idx, sm is pref_sm so far & cost[idx] 
is the cost req to open/reach that idx...
So cost[idx] will be the first bitset so far...
Since it will be only the min. cost!!!
*/

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);enter(v);

    vector<ll> cost(n+1,1e16);
    b[0] = 1;
    c[0] = 1;
    for(ll i = 0;i<n;++i){
        // cost[i] = b._Find_first();
        cost[i] = c._Find_first();
        if(cost[i] >= N){
            cost[i] = 1e16;
            break;
        }
        /*
        Abb b mein harr '1' is representing cards unlocked so far..
        Aur agar mein ye bhi Card aage ke cards ko unlock krne ke liye use krna 
        chahta hu toh simply I'll need to send all of the ones ahead by v[i] aur 
        sath hi mujhe curr positions of 1 bhi lose nhi krni since they will be 
        contributing in cost..
        */
        b |= (b<<v[i]);
        /*
        2nd way ki i ke baad chotte elements[i-1,0] ko 0 krre is first Right & then
        left shift..
        Now just left shift it by v[i]; to get prev state
        */
        c |= (((c>>i)<<(i+v[i])));

        // Abb chotte bits vo bade cost[i] ko affect na karre isiliye unset them..
        b[i] = 0;
        c[i] = 0;
    }

    ll sm = 0,ans = 0;
    forj(n){
        sm += v[j];
        ans = max(ans,sm-cost[j]);
    }
    cout<<ans<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}