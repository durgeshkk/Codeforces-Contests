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
 
    ll n;
    cin>>n;

    string s;
    cin>>s;
    
    set<ll> zero,one;
    ll mx = 0;
    string ans;

    for(ll i=0;i<n;++i){
        if(s[i] == '0'){
            if(!one.empty()){
                ll val = *one.begin();
                one.erase(one.find(val));
                zero.insert(val);
                ans += to_string(val);
                ans += ' ';
            }
            else{
                mx++;
                zero.insert(mx);
                ans += to_string(mx);
                ans += ' ';
            }
        }
        else{
            if(!zero.empty()){
                ll val = *zero.begin();
                zero.erase(zero.find(val));
                one.insert(val);
                ans += to_string(val);
                ans += ' ';
            }
            else{
                mx++;
                one.insert(mx);
                ans += to_string(mx);
                ans += ' ';
            }
        }
    }
    cout<<mx<<endl;
    cout<<ans<<endl;
    /*
    vector<ll> v;
    ll f = 0;
    ll z = 0, o = 0;
    for(ll i=0;i<n;i++){
        if(s[i] == '0'){
            if(o != 0){
                v.push_back(o);
                o = 0;
            }
            ++z;
        }
        else{
            if(z != 0){
                v.push_back(z);
                z = 0;
            }
            ++o;
        }
    }
    if(z != 0){
        v.push_back(z);
    }
    else if(o != 0){
        v.push_back(o);
    }
    // show(v);

    string ans;
    vector<ll> ag;
    ll mxo = 0,mxe = 0;
    
    for(ll i = 1;i<=v[0];++i){
        ans += to_string(i);
        ans += ' ';
        ag.push_back(i);
        mxo = v[0];
    }
    
    for(ll i= 1;i<v.size();++i){
        if(v[i] > v[i-1]){
            ll val = v[i-1];
            ll j = 1;
            string st;
            for(j;j<=val;++j){
                st += to_string(j);
                ag.push_back(j);
                st += ' ';
            }
            ans += st;
            // cout<<st<<endl;
            
            if(i & 1){
                if(mxe == 0){
                    for(j;j<=v[i];++j){
                        ans += to_string(j);
                        ans += ' ';
                        ag.push_back(j);
                    }
                    mxe = v[i];
                }
                else{
                    mxe = max(mxe+1,j);
                    ll diff = ((v[i]-v[i-1])+mxe-1);
                    // cout<<" MXE : "<<mxe<<endl;
                    // mxe++;
                    for(mxe;mxe<=diff;++mxe){
                        ans += to_string(mxe);
                        ans += ' ';
                        ag.push_back(mxe);
                    }
                }
                mxe = max(mxe,v[i]);
                // cout<<ans<<endl;
            }
            else{
                // cout<<"MXO : "<<mxo<<endl;
                if(mxo == 0){
                    for(j;j<=v[i];++j){
                        ans += to_string(j);
                        ans += ' ';
                        ag.push_back(j);
                    }
                    mxo = v[i];
                }
                else{
                    mxo = max(mxo+1,j);
                    ll diff = ((v[i]-v[i-1])+mxo-1);
                    // mxo++;
                    // cout<<"DIFF : "<<diff<<" ";
                    // cout<<"MXO : "<<mxo<<endl;
                    for(mxo;mxo<=diff;++mxo){
                        ans += to_string(mxo);
                        ans += ' ';
                        ag.push_back(mxo);
                    }
                }
                mxo = max(mxo,v[i]);
                // cout<<ans<<endl;
            }
        }
        else{
            ll j = 1;
            for(j;j<=v[i];++j){
                ans += to_string(j);
                ans += ' ';
                ag.push_back(j);
            }
            // cout<<ans<<endl;
        }
    }
    
    ll dk = *max_element(ag.begin(),ag.end());
    cout<<dk<<endl;
    cout<<ans<<endl;
    // for(ll i = 0;i<ans.size();++i){
    //     cout<<ans[i];
    // }
    // cout<<endl;
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 */
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20)// also use precision with ans now
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