/*
Once in a LifeTime,
Will never let you Down!!
*/
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
// YE DIL MAANGE MORE!!
 
// The below impl fails since it will not update if we are updating same substring for 
// Changes. e.g. 0110 & j = 2 with changes = 1 
// So for this subSegLen needs to be a updated by keeping track for consective 0 in
// [0,i-1],[j+1,n), if we are updating a substring from [i,j]

vector<vector<pair<ll,ll>>> func(string s,ll n,ll k){
    // cout<<s<<endl;
    vector<ll> prefConsZero(n+2,0),prefConsOne(n+2,0);
    vector<ll> suffConsZero(n+2,0),suffConsOne(n+2,0);
    ll cntrZero=0,cntrOne=0;
    for(ll i=1;i<=n;i++){
        if(s[i]-'0'){
            ++cntrOne;cntrZero=0;
        }else{
            ++cntrZero;cntrOne=0;
        }
        prefConsZero[i] = max(prefConsZero[i-1],cntrZero);
        prefConsOne[i] = max(prefConsOne[i-1],cntrOne);
    }

    cntrZero=0,cntrOne=0;
    for(ll i=n;i>0;i--){
        if(s[i]-'0'){
            ++cntrOne;cntrZero=0;
        }else{
            ++cntrZero;cntrOne=0;
        }
        suffConsZero[i] = max(suffConsZero[i-1],cntrZero);
        suffConsOne[i] = max(suffConsOne[i-1],cntrOne);
    }

    vector<ll> prefZero(n+1,0),prefOne(n+1,0);
    for(ll i=1;i<=n;i++){
        prefZero[i] += prefZero[i-1];
        prefOne[i] += prefOne[i-1];
        if(s[i]-'0'){
            prefOne[i]++;
        }else{
            prefZero[i]++;
        }
    }
 
    vector<vector<pair<ll,ll>>> dpMaxLength(2,vector<pair<ll,ll>>(k+1,{-1,-1}));

    for(ll subsegLen=1;subsegLen<=n;++subsegLen){
        ll cntOne = 0,cntZero = 0;
        ll l = 0,r = subsegLen;
        while(r<=n){
            cntOne = prefOne[r]-prefOne[l];
            cntZero = prefZero[r]-prefZero[l];
            // Get the seg from [1,l] and from [r+1,n]

            // subsegLen-cntZero = min. changes to made to get the len equal to subseg len
            if((subsegLen-cntZero) <= k){
                ll maxLenConsOnes = max(prefConsOne[l],suffConsOne[r+1]);
                pair<ll,ll> &p = dpMaxLength[0][subsegLen-cntZero];
                if(p.first < subsegLen){
                    p = {subsegLen,maxLenConsOnes};
                }else if(p.first == subsegLen){
                    p = {subsegLen,max(p.second,maxLenConsOnes)};
                }
            }

            if((subsegLen-cntOne) <= k){
                ll maxLenConsZeros = max(prefConsZero[l],suffConsZero[r+1]);
                pair<ll,ll> &p = dpMaxLength[1][subsegLen-cntOne];
                if(p.first < subsegLen){
                    p = {subsegLen,maxLenConsZeros};
                }else if(p.first == subsegLen){
                    p = {subsegLen,max(p.second,maxLenConsZeros)};
                }
            }
            ++l,++r;
        }
    }
    return dpMaxLength;
}

void solve()
{
 
    ll n,k;cin>>n>>k;
    string s,t;cin>>t;
    s += '2';s+=t;

    
    // for(ll i = 0;i<=1;++i){
    //     cout<<i<<"\n";
    //     forj(k+1){
    //         cout<<dpMaxLength[i][j].first<<" "<<dpMaxLength[i][j].second<<endl;
    //     }
    //     cout<<endl;
    //     cout<<endl;
    //     cout<<endl;
    //     cout<<endl;
    //     cout<<endl;
    // }

    vector<vector<pair<ll,ll>>> dpMaxLength = func(s,n,k);
    reverse(all(t));s.clear();s+='2';s+=t;
    vector<vector<pair<ll,ll>>> dpMaxLength2 = func(s,n,k);
    reverse(dpMaxLength2.begin(),dpMaxLength2.end());

    for(ll j = 0;j<=1;++j){
        for(ll i = 0;i<=k;++i){
            dpMaxLength[j][i] = max(dpMaxLength[j][i],dpMaxLength[j][k-i]);
        }
    }

    for(ll j = 1;j<=n;++j){
        ll ans = 0;
        for(ll changes = 0;changes<=k;++changes){
            ll l0 = dpMaxLength[0][changes].first,l1 = dpMaxLength[0][changes].second;
            ll sa = j*max(0ll,l0)+max(0ll,l1);
            ans = max(ans,sa);
        }
        for(ll changes = 0;changes<=k;++changes){
            ll l0 = dpMaxLength[1][changes].second,l1 = dpMaxLength[1][changes].first;
            ll sa = j*max(0ll,l0)+max(0ll,l1);
            ans = max(ans,sa);
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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