#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, nuint_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long int
#define enter(a) for(int i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(int e: a) cout<<e<<" "; cout<<endl;
using namespace std;
int mod = (int)(1e9+7);
 
/*
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
int ceil_div(int a, int b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(int a, int b) {return a > b;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
int LCM(int a,int b){
   int ans = (a*b)/__gcd(a,b);
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
// Fxn caint(for ((b/a)%mod)) :
// int c = (b*power(a,mod-2(prime num in power of a),mod))%mod;
// Also for formula like nCr..
int power(int base,int n,int mod){
   int ans = 1;
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
 
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
int sieve[1000005];
void createsieve(){
    int ntlen = 1000000;
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2;i<=ntlen;++i){
        sieve[i] = 1;
    }
 
    for(int i = 2;i*i<=ntlen;++i){
 
        // Set aint multiples to 0
        if(sieve[i] == 1){
 
            for(int j = i*i;j<=ntlen;j+=i){
                 sieve[j] = 0;
            }
        }
    }
}
 
 
int fact[100005];
int powfact[100005];
void precomputefact(){
    fact[0] = 1;
    int ans = 1;
    for(int i = 1;i<=100005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
         powfact[i] = power(fact[i],mod-2,mod);
    }
}
 
int nCr(int n,int r){
     int at = powfact[r];
     int at2 = powfact[n-r];
     return ((fact[n]*((at*at2)%mod))%mod);
}
 
vector<int> adj[100004];
 
void bfs(){
    queue<pair<int,int>> q;
    q.push({1,0});
 
    while(!q.empty()){
        auto it = q.front();
        q.pop();
 
        int node = it.first;
        int par = it.second;
 
        cout<<node<<" ";
 
        for(auto it:adj[node]){
            if(it != par){
                q.push({it,node});
            }
        }
    }
}
 
int height;
int subtree[100005];
int lev[100005];
int parent[200005];
 
void dfs(int node, int par, int level=1){

    cout<<node<<" ";
    lev[node] = level;
    height = max(height,level);
 
    int sm = 0;
 
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
    int n;
    cin>>n;

    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void solve()
{
 
    int n,a,b;
    cin>>n>>a>>b;
    int x=b-n+1;
    if(x*x+n-1>=a&&x>0)
    {
        for(int i=0;i<n-1;i++)
        {
            cout<<1<<' ';
        }
        cout<<x<<' ';
        return;
    }
    cout<< -1;
    return;
}
 
int32_t main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//caint in solve()
   //dfs(1,0);//caint in solve()
 
   int t=1;
   int i = 1;
   while (t--)
   {
       solve();
       cout<<endl;
       ++i;
   }
   //solve();
   return 0;
}