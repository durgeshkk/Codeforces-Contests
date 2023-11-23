#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
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
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
 
void solve()
{
 
    ll n;
    cin>>n;
    ll m;cin>>m;

    vector<ll> v(n);
    enter(v);

    ll idx = n;
    ll i = n-1;
    for(i;i>=0;i--){
        if(v[i] != (i+1)){
            break;
        }
        else{
            idx--;
        }
    }

    long double ans = 1.0;
    long double presval = 1.0;
    idx--;

    for(ll j = 0;j<m;++j){
        int a;
        long double b;
        cin>>a>>b;
        --a;

        if(a >= i){
            presval *= (1-b);
            // if(mp.find(a) != mp.end()){
            //     double z = mp[a];
            //     mp[a] = max(z,b);
            // }
            // else{
            //     mp[a] = b;
            // }
        }
    }

    if(idx == -1){
        cout<<1<<endl;
        return;
    }

    long double ag = (ans)-presval;
    cout<<ag<<endl;
    return;
/*
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    ll k = 0;
    vector<double> prob;

    ans = 1;
    double prev = 1;

    for(auto it=mp.rbegin();it != mp.rend();++it){
        prob.push_back(it->second);
    }
    show(prob);

    for(auto it:mp){

        double z = (it.second);
        ans += (prev*(z));

        // cout<<z<<endl;
        prob.push_back(z);
        prev = (1.0-it.second);
        // prob[k] = (z);
        // ++k;
    }

    reverse(prob.begin(),prob.end());
    show(prob);
    cout<<ans<<endl;
     ans = 0;
    
    for(ll j = 0;j<k-1;++j){
        ans += (prob[j])*(1-prob[j+1]);
    }
    ans += prob[prob.size()-1];
    cout<<ans<<endl;
 */   
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
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
