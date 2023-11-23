//CELEBRATING SEMIANNIVERSARY OF DADDY_DYNAMO!!
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
ll m = (ll)(1e9+7);
 
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
void solve()
{
    ll l,r;cin>>l>>r;

    ll i = 1;
    ll o = 0,e = 0;
    ll f = 0;
    ll j = 0;
    --l;

    while((j+i)<l){
        if(f == 0){
            o += i;
            f = 1;
        }
        else{
            e += i;
            f = 0;
        }

        j += i;
        i *= 2;
    }
    if(f == 0){
        o += (l-j);
    }
    else{
        e += (l-j);
    }
    // cout<<o<<" "<<e<<endl;

// ---only r
    i = 1;
    ll o1 = 0,e1 = 0;
    f = 0;
    j = 0;
    while((j+i)<r){
        if(f == 0){
            o1 += i;
            f = 1;
        }
        else{
            e1 += i;
            f = 0;
        }

        j += i;
        i *= 2;
    }
    if(f == 0){
        o1 += (r-j);
    }
    else{
        e1 += (r-j);
    }

    // cout<<o<<" "<<e<<endl;
    // cout<<o1<<" "<<e1<<endl;

    ll ans = 0;
    ll ans1 = mod_mul(o,o,m);
    ll ans2 = mod_mul(o1,o1,m);
    ll ans3 = mod_sub(ans2,ans1,m);
    
    ll ans4 = mod_mul(e,e+1,m);
    ll ans5 = mod_mul(e1,e1+1,m);
    ll ans6 = mod_sub(ans5,ans4,m);

    // cout<<ans1<<" "<<ans4<<endl;
    // cout<<ans2<<" "<<ans5<<endl;
    // cout<<ans3<<" "<<ans6<<endl;

    ans = mod_add(ans3,ans6,m);
    cout<<ans<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
//    cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}