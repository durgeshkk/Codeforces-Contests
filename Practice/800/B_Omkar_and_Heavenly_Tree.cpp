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
 
vector<int> primeFactors(long long int n)
{
    vector<int> v;
 
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
 
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }
 
    if (n > 2)
        v.push_back(n);
 
    return v;
}
 
void DFS(vector<int> h[], int v, int k, bool &u, vector<bool> &visited)
{
 
    visited[v] = true;
 
    if (v == k)
    {
        u = true;
        return;
    }
 
    for (auto it : h[v])
        if (!visited[it])
        {
            DFS(h, it, k, u, visited);
        }
}
 
void solve()
{
    long long int n, N;
    cin >> n >> N;
    // vector<vector<long long int>> v;
    vector<int> v(n + 1);
    // map<long long int, long long int> m;
    // vector<int> adj[n + 1];
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[b] = 1;
    }
 
    // for (int i = 0; i < n; i++)
    // {
    //     if (m.find(i + 1) == m.end() && i + 1 != 1)
    //     {
    //         cout << 1 << " " << i + 1 << endl;
    //     }
    // }
    // vector<int> h;
    // vector<vector<long long int>> l;
    // for (int i = 0; i < v.size(); i++)
    // {
 
    //     bool l1 = false;
    //     vector<bool> visited(n + 1);
    //     DFS(adj, 1, v[i][0], l1, visited);
 
    //     if (!l1)
    //     {
    //         adj[1].push_back(v[i][0]);
    //         adj[v[i][0]].push_back(1);
    //         l.push_back({1, v[i][0]});
    //     }
    // }
 
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i][0] << " " << v[i][1] << endl;
    // }
 
    // for (int i = 0; i < l.size(); i++)
    // {
    //     cout << l[i][0] << " " << l[i][1] << endl;
    // }
    int k;
 
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == 0)
        {
            k = i;
            break;
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        if (i != k)
        {
            cout << k << " " << i << endl;
        }
    }
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
       solve();
   }
   //solve();
   return 0;
}