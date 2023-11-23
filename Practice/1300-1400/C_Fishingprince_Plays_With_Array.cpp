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
 
void solve()
{
 
    ll n,k;
    cin>>n>>k;

    vector<ll> ff(n);
    enter(ff);
    
    ll m;
    cin>>m;
    vector<ll> ss(m);
    enter(ss);

    // show(ff);
    // show(ss);

    vector<ll> ak(n,1),dk(m,1);
    for(ll i = 0;i<n;++i){
        while(ff[i]%k == 0){
            ff[i] /= k;
            ak[i] *= k;
        }
    }
    
    for(ll i = 0;i<m;++i){
        while(ss[i]%k == 0){
            ss[i] /= k;
            dk[i] *= k;
        }
    }

    ll i = 0,j=0,sm = 0;
    while(i != n && j!=m){

        if(ff[i] != ss[j]){
            cout<<"No\n";
            return;
        }
        
        if(ak[i] > dk[j]){
            ak[i] -= dk[j];
            j++;
        }
        else if(ak[i] < dk[j]){
            dk[j] -= ak[i];
            i++;
        }
        else{
            ++i,++j;
        }

        
    }

    if ((i == n && j != m) || (j == m && i != n)) {
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
/*
    for(ll i=1;i<n;i++){
        if(ff[i] == prev){
            sm += ff[i];
            continue;
        }

        if(ff[i]%k == 0){
            ll val = ff[i]/k;
            if((val%prev == 0 || (prev%val ==0)) && (val != 1)){
                sm += ff[i];
                prev = min(prev,ff[i]);
            }
            else{
                v.push_back(sm);
                sm = ff[i];
                prev = ff[i]/k;
            }
        }
        else{
            if(ff[i] < k){
                ll z = (i+3);
                prev = ff[i];
                for(i;i<z;++i){
                    if(ff[i] != prev){

                    }
                    sm += ff[i];
                }
            }
        }
    }*/
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