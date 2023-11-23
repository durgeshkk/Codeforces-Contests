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
 
void recur(vector<ll> &v,vector<ll> &dp,ll n,ll s,ll e){
    if(e == n){
        return;
    }

    if(s>e){
        e++;
        recur(v,dp,n,0,e);
    }
    else{
        ll sm = 0;
        for(ll i = s;i<=e;++i){
            sm += v[i];
        }
        ll sz = (e-s+1);
        dp[sz] = max(dp[sz],sm);
        recur(v,dp,n,s+1,e);
    }
}

void solve()
{
 
    ll k,n;
    cin>>n>>k;
    vector<ll> v(n);
    enter(v);
    vector<ll> ak(n+1,-1e18);

    ll mx = 0;
    ak[0] = 0;
    for(ll i=0;i<n;++i){
        ll sm = 0;
        mx = max(mx,v[i]);
        for(ll j=i;j<n;++j){
            sm += v[j];
            ll dis = (j-i+1);
            ak[dis] = max(ak[dis],sm);                
        }
    }

    // ak[0] = mx;
    // show(ak);

    vector<ll> dk(n+1,0);
    for (ll i = 0; i<=n;i++){
        ll ans = -1e6;
        for (ll j = 0; j<=n;j++){
            ans = max(ans,ak[j] + min(i,j)*k);
        }
        dk[i] = ans;
    }

    show(dk);
/*
    bool f = 0;
    for(auto it:v){
        if(it<0){
            f = 1;
            break;
        }
    }

    if(f == 0){
        ll sm = accumulate(v.begin(),v.end(),0LL);
        vector<ll> ans(n+1,sm);
        for(ll i = 1;i<=n;++i){
            ans[i] += (i*k);
        }
        show(ans);
        return;
    }

    ll mx = *max_element(v.begin(),v.end());
    vector<ll> dp(n+1,-1*(1e5));

    if(mx < 0){
        mx = 0;
    }

    dp[0] = mx;
    recur(v,dp,n,0,0);
    // show(dp);

    for(ll i = 1;i<=n;++i){
        dp[i] += (i*k); 
    }
    // show(dp);

    mx = dp[0];
    for(ll i = 1;i<=n;++i){
        if(mx < dp[i]){
            mx = dp[i];
        }
        else{
            dp[i] = mx;
        }
    }
    show(dp);*/
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
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
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}