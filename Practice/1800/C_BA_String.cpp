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
#define fori(n) for (ll i = 0; i < n; i++)
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
/*
let the array of b's be 
4k,3k,1k,3k
So for 1st suff : 3k+1
2nd suff = (k+1)(3k+1)
3rd suff = (3k+1)(k+1)(3k+1)
4th suff = (4k+1)(3k+1)(k+1)(3k+1) >= x
So at any given suffix find the smallest p such that (p+1)(suff) >= x
i.e. p = ceil(x/suff) - 1
*/ 
string s;
ll n,k,x;
vector<ll> a,ans,productt;

ll solver(ll curx)
{
	ll prod = 1;
	ll i, j;
	if (curx == 1)return n;
	for (i = a.size() - 1; i >= 0; i--)
	{
		ll it;
        for(ll it = 1;it<a[i]+1;++it){
			if (prod * (it) >= curx)
			{
				ans[i] = curx % prod == 0 ? curx / prod - 1 : curx / prod;
				x -= prod * ans[i];
				return i;
			}
		}
		prod *= (a[i] + 1);
		productt[i] = prod;
	}
	return -1LL;
}

void solve()
{
 
    cin>>n>>k>>x;
    cin>>s;
    a.clear();
    vector<ll> v;
    forj(n){
        if(s[j] == '*'){
            ll cntr = 0;
            while(j < n and s[j] == '*'){
                ++cntr;++j;
            }
            v.push_back(cntr*k);
            --j;
        }
    }
    a.assign(v.size(),0);
    a = v;
    productt.assign(v.size()+1,1);
    ans.assign(v.size(),0);
    ll idx = solver(x),prdt = 1;
    /*
    This will give overflow!!
    for(ll i = v.size()-1;i>=0;--i){
        prdt *= (v[i]+1);
        idx = i;
        if(prdt >= x){break;}
    }
    */
   ll sz = v.size();
    for(ll i=idx+1;i<(sz-1);++i){
        if(x == 1)break;
        ll curx = x;
        ll prod = productt[i + 1];
        ans[i] = curx % prod == 0 ? curx / prod - 1 : curx / prod;
        x -= ans[i] * productt[i + 1];
    }

    ll j = 0;
    string dk = "";
    fori(n-1)
    {
        if (s[i] == '*'){
            string str = "";
            ll it;
            for(it=1;it<ans[j];++it){str += 'b';}
            j++;
            dk += str;
            it = i + 1;
            while (it < n and s[it] == '*')it++;
            i = it - 1;
        }
        else{
            dk += 'a';
        }
    }
    cout << dk << "\n";
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