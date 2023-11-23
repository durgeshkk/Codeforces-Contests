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
 
int solve()
{
 /*
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int ak = 0;
    if(a < 0){
        ak += a;
    }
    if(b < 0){
        ak += b;
    }
    if(c < 0){
        ak += c;
    }
    if(d < 0){
        ak += d;
    }
    return ak;*/
    /*
    int l,r;
    cin>>l>>r;

    if(l > r){
        return (-1);
    }
    else if(l == r){
        return 0;
    }
    else{
        int ak = l^r;
        int dk = 1;
        while(ak != 0){
            dk = dk<<1;
            ak = ak>>1;
        }
        return (dk - 1);
    }*/
    /*
    int x = 1;
    if(x--){
        cout<<"HI\n";
    }
    else{
        cout<<"HFUOSBf\n";
    }*/
 /*   
    string s1,s2;
    int k;
    cin>>s1>>s2>>k;

    if(s1 == s2){
        return 1;
    }
    else{

        // --->
        int z = 0;
        for(int i = 0;i<s1.size();++i){
            if(s1[i] != s2[i]){
                ++z;
            }
        }

        if(z == 0){
            return 1;
        }
        if(z > k){
            return 4;
        }
        else if(z == k){
            return 3;
        }
        else{
            return 2;
        }
        */
        // -->
    // }
    /*
    int a = 2,b = 14,c= 5;
    if(a && b > c){
        cout<<"HI\n";x
    }
    else{
        return 0;
    }*/
    /*
    int b,h;
    cin>>b>>h;
    // int a = 6,b = 4;
    // cout<<(a>b)<<endl;

    float ans = 0;
    if(n == 1 || n == 4){
        ans = b*h;
    }
    else if(n == 2){
        ans = b*h*0.5;
    }
    else{
        ans = 22*b*h/7;
    }
    return ans;*/

    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // int m = sizeof(arr2)/sizeof(arr2[0]);
    /*
    int c1 = 0,c2 = 0;
    for(int i = 0;i<len1;++i){
        if(arr1[i] > k){
            ++c1;
        }
    }
    
    for(int i = 0;i<len2;++i){
        if(arr2[i] < k){
            ++c2;
        }
    }

    if(c1 < c2){
        c1 = c2;
    }
    return c1;*/
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
   while (t--)
   {
       int ans = solve();
       cout<<ans<<endl;
   }
   //solve();
   return 0;
}