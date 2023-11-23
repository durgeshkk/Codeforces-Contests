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
 
void yno(ll f){
   if(f & 1) cout<<"YES\n";
   else cout<<"NO\n";
   return;
}

vector<ll> v;
void solve(){
    string s;cin>>s;
    ll n = s.size();

    // At last prefix nikalo w/o '?'
    // e.g. ?(?)()?) : -1
    // For it to be an RBS, we need at last value to be 0;
    // ==> '?' contribute to +1!!
    // (open-closing)'?' = 1
    // (open+closing)'?' = no. of '?' = 3
    // Opening = 2 & closing = 1
    // For it to be an RBS, Prefix sum >= 0 & optimal approach for it is replace
    // all starting '?' -> '('
    // Ye hume original RBS nhi denga bt surely RBS toh denga hi,
    // e.g. ?(?)()?) -> ((()()))
    // This implies we can always generate an RBS bt how to check if more than 1 RBS
    // Exist?

    // So check if 2nd optimal approach will also work:
    // 2nd optimal approach: replace (x-1)'?'->'(' then 1 ;(1)'?'->')'
    // then 1 ;(1)'?'->'(' and then finally (y-1)'?'->')'
    // If this also gives ans then return no!!

    ll cnt = 0,ques = 0,f = 1;
    for(ll i = 0;i<n;++i){
        if(s[i] == '('){--cnt;}
        else if(s[i] == ')'){++cnt;}
        else{++ques;}
    }

    ll open = 0,close = 0;
    // cnt  = open-close
    // ques = open+close
    open = (cnt+ques)/2;
    close = (ques-cnt)/2;
    if(open == 0 || close == 0){
        yno(f);return;
    }

    string s2 = s;
    string s3 = s;
    // 1st optimal:
    ll o = open,c = close;
    for(ll i = 0;i<n;++i){
        if(s2[i] == '?' and o > 0){
            s2[i] = '(';
            --o;
        }else if(s2[i] == '?' and c > 0){
            s2[i] = ')';
            --c;
        }
    }

    string check = string(open-1,'(') + string(1,')') + string(1,'(') + string(close-1,')');
    ll j = 0;
    for(auto &it:s3){
        if(it == '?'){
            it = check[j];++j;
        }
    }

    // Check if 2nd optimal gives correct ans!!
    cnt = 0;
    for(ll i = 0;i<n;++i){
        if(s3[i] == '('){++cnt;}
        else{--cnt;}
        if(cnt < 0){yno(f);return;}
    }

    f = 0;
    yno(f);
}

// Sol 2:
void solver()
{
    string s;cin>>s;
    ll n = s.size();
    v.assign(n,0);
    for(ll i=0;i<n;i++){
        if(s[i] == '('){
            v[i] = 1;
        }else if(s[i] == ')'){
            v[i] = -1;
        }else{
            v[i] = 0;
        }
    }
 
    ll f = 1;
    ll cnt = 0,ques = 0;
    for(ll i=0;i<n;i++){
        if(v[i] == 0){
            ++ques;
        }else{
            cnt += v[i];
        }

        if(cnt + ques == 1){cnt = 1;ques = 0;}
    }

    if(abs(cnt) != ques){f = 0;}
    yno(f);
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