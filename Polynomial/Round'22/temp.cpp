// Cheke D
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long int
#define M 1000000007
#define el "\n"
#define rep(i,n,m) for(ll i = n ;i<m;i++)
#define rep1(i,n,m) for(ll i = n;i>=m;i--)
#define pb push_back
#define fe first
#define se second
inline ll myceil(ll a , ll b){ if(a%b==0) return a/b ; else return a/b + 1 ; } 
#define all(x) x.begin(),x.end()
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define pr(x) cout<<x<<" ";
#define prn(x) cout<<x<<el;
#define mod 998244353

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

vector<ll> SieveOfEratosthenes(ll n,ll m) { vector<ll> ans; bool prime[m + 1]; memset(prime, true, m+1); for (ll p = 2ll; p * p <= m; p++) { if (prime[p] == true) { for (ll i = p * p; i <= m; i += p) {prime[i] = false;} } } for (ll p = n; p <= m; p++) { if (prime[p]) { ans.pb(p); } } return ans; }
void primeFactors(ll n,set<ll> &a){while (n % 2 == 0) { a.insert(2);   n = n/2;} for (ll i = 3; i <= sqrt(n); i = i + 2) { while (n % i == 0) { a.insert(i); n = n/i; } } if (n > 2) a.insert(n); }
long long calculate(long long p, long long q) { ll expo; expo = mod - 2; while (expo) {  if (expo & 1) { p = (p * q) % mod; } q = (q * q) % mod; expo >>= 1; } return p; }
void printDivisors(ll n,vector<ll> &v) { for (ll i=1; i<=sqrt(n); i++) { if (n%i == 0) {  if (n/i == i) v.pb(i); else  v.pb(i); v.pb(n/i); } } }
bool isPrime(int n) {  if (n <= 1) {return false;} for (int i = 2; i < n; i++) {if (n % i == 0){ return false; }} return true; }
unsigned int onesComplement(unsigned int n,int number_of_bits){ return ((1 << number_of_bits) - 1) ^ n;}
int binaryToDecimal(string n) { string num = n; int dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) { if (num[i] == '1') dec_value += base; base = base * 2; } return dec_value; }
int findPar(int u, vector<int> &parent) {if(u == parent[u]) return u; return parent[u] = findPar(parent[u], parent); }
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) { u = findPar(u, parent); v = findPar(v, parent); if(rank[u] < rank[v]) { parent[u] = v; } else if(rank[v] < rank[u]) { parent[v] = u; } else { parent[v] = u; rank[u]++; } }
bool isPalindrome(string S) {  string P = S; reverse(P.begin(), P.end());  if (S == P) {  return true; }  else {  return false; } }
vector<ll> primes = SieveOfEratosthenes(2,sqrt(1e7 + 10));
ll nCr(ll n, ll r) {ll p = 1, k = 1; if (n - r < r)r = n - r; if (r != 0) {while (r) {p *= n; k *= r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; return p;}

void dfs(int n,vector<vector<int>> &adj,vector<int> &vis, int &c,int &ans)
{
    vis[n] = 1;
    c++;
    ans = min(ans,n);
    for(int i = 0;i<adj[n].size();i++)
    {
        if(!vis[adj[n][i]]) dfs(adj[n][i],adj,vis,c,ans);
    }
}

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

ll Pow(ll a,ll b)
{
    rep(i,0,b)
    {
        a*=2;
    }
    return a;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));

    int c = 0;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>a[i][j];
            if(a[i][j]) c++;
        }
    }

    if(c%n!=0)
    {
        prn(-1);
        return;
    }

    set<int> don;
    int d = c/n;
    map<int,int> req,dono;
    rep(i,0,n)
    {
        c= 0;
        // set<int> tem;
        rep(j,0,m)
        {
            if(a[i][j]) {c++;}
        }

        if(c>d)
        {
            don.insert(i);
            dono[i] = c-d;
        }
        else if(c<d)
        {
            req[i] = d-c;
        }

    }

    vector<vector<int>> ans;
    for(auto i:req)
    {
        int r = i.se,l = i.fe;
        vector<int> g;
        for(auto j:don)
        {
            rep(k,0,m)
            {
                if(dono[j]==0) break;
                if(r==0) break;
                if(a[l][k]==0 && a[j][k]==1)
                {
                    ans.pb({l+1,j+1,k+1});
                    r--;
                    dono[j]--;
                    a[l][k] = 1;
                    a[j][k] = 0;
                }                
            }
                if(dono[j]==0) g.pb(j); 
                if(r==0) break;                   
        }

        for(auto p:g) don.erase(p);
        
    }

    prn(ans.size())
    for(auto i:ans)
    {
        pr(i[0])pr(i[1])prn(i[2]);
    }

    
}


int main()
{
    #ifndef ONLINE_JUDGE

    freopen("input.txt","r",stdin); //for getting input

    freopen("output.txt","w",stdout); //for getting output

    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll t = 0;
    cin >> t;

    
    for(int it=1;it<=t;it++) {
        // cout << "Case #" << it << ": ";
        solve();
        
    }
    // solve();
}