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
 
bool akdfs(ll n,ll m,vector<vector<ll>> v,ll x,ll y,ll x2,ll y2,ll k){
    while(y != y2){
        if(v[x][y-1] != 0 && y>y2){
            x+=k;
            if(x >= n || x<0){
                return false;
            }
        }
        else if(v[x][y+1] != 0 && y<y2){
            x+=k;
            if(x >= n || x<0){
                // cout<<"ofm\n";
                return false;
            }
        }
        else{
            if(y > y2){
                y-=k;
            }
            else{
                y+=k;
            }
            if(y >= m || y< 0){
                return false;
            }
        }        
    }
    return true;
}

void solve()
{
 
    ll n,m;
    cin>>n>>m;

    vector<ll> blocks(m);
    enter(blocks);

    ll q;
    cin>>q;
    for(ll i=0;i<q;i++){
        ll x,y,x2,y2;
        cin>>x>>y>>x2>>y2;
        ll k;
        cin>>k;

        if(x2 < x){
            swap(x,x2);
            swap(y,y2);
        }

        x--,y--,x2--,y2--;
        ll mx = max(y,y2);
        ll mn = min(y,y2);

        if(((x2-x)%k != 0) || ((mx-mn)%k != 0)){
            cout<<"NO\n";
            continue;
        }

        ll val = 0;
        for(ll i = mn+1;i<mx;++i){
            val = max(val,blocks[i]);
        }

        if(val < x){
            cout<<"YES\n";
            continue;
        }

        if(val == n){
            cout<<"NO\n";
            continue;
        }

        ll cal = val-x;
        if(cal %k == 0){
            cout<<"YES\n";
            continue;
        }

        val += (k-(cal%k));
        if(val >= n){
            cout<<"NO\n";
            continue;
        }
        else{
            cout<<"YES\n";
        }
    }
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
//    cin >> t;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}