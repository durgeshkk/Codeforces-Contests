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
 
    ll n;
    cin>>n;

    ll u,r,d,l;
    cin>>u>>r>>d>>l;

    if(n == 2){
        if(u == 1 && d == 1 && ((l == 2 && r == 0) || (r == 2 && l == 0))){
            cout<<"YES\n";
        }
        else if(u == 0 && r == 0 && d == 0 && l == 0){
            cout<<"YES\n";
        }
        else if(u == 2 && r == 2 && d == 2 && l == 2){
            cout<<"YES\n";
        }
        else if(u == 1 && r == 1 && d == 1 && l == 1){
            cout<<"YES\n";
        }
        else if(u == 2 && r == 1 && d == 1 && l == 2){
            cout<<"YES\n";
        }
        else if(u == 1 && r == 2 && d == 2 && l == 1){
            cout<<"YES\n";
        }
        else if(u == 2 && r == 2 && d == 1 && l == 1){
            cout<<"YES\n";
        }
        else if(u == 1 && r == 1 && d == 2 && l == 2){
            cout<<"YES\n";
        }
        else if(l == 1 && r == 1 && ((u == 2 && d == 0) || (d == 2 && u == 0))){
            cout<<"YES\n";
        }

        else if(u == 1 && r == 1 && l == 0 && d == 0){
            cout<<"YES\n";
        }
        else if(d == 1 && r == 1 && l == 0 && u == 0){
            cout<<"YES\n";
        }
        else if(u == 0 && r == 0 && l == 1 && d == 1){
            cout<<"YES\n";
        }
        else if(u == 1 && l == 1 && r == 0 && d == 0){
            cout<<"YES\n";
        }
      
        else{
            cout<<"NO\n";
        }
        return;
    }

    ll val = n-2;
    if(u <= val && d <= val && r<=val && l<=val){
        cout<<"YES\n";
        return;
    }

    ll eu = 0;
    if(u > val){
        eu = u-val;
        if(eu == 2){
            if(l < 1 && r < 1){
                cout<<"NO\n";
                return;
            }
            else{
                --l,--r;
            }
        }
        else if(eu == 1){
            if(l > 1 || r > 1){
                if(l > r){
                    --l;
                }
                else{
                    --r;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }

    ll el = 0;
    if(l > val){
        el = l-val;
        if(el == 2){
            if(d < 1 && u < 1){
                cout<<"NO\n";
                return;
            }
            else{
                --u,--d;
            }
        }
        else if(el == 1){
            if(d > 1 || u > 1){
                if(d > u){
                    --d;
                }
                else{
                    --u;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }

    ll ed = 0;
    if(d > val){
        ed = d-val;
        if(ed == 2){
            if(l < 1 && r < 1){
                cout<<"NO\n";
                return;
            }
            else{
                --l;
                --r;
            }
        }
        else if(ed == 1){
            if(l > 1 || r > 1){
                if(l > r){
                    --l;
                }
                else{
                    --r;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }

    ll er = 0;
    if(r > val){
        er = u-val;
        if(er == 2){
            if(d < 1 && u < 1){
                cout<<"NO\n";
                return;
            }
            else{
                --d,--u;
            }
        }
        else if(er == 1){
            if(d > 1 || u > 1){
                if(d > u){
                    --d;
                }
                else{
                    --u;
                }
            }
            else{
                cout<<"NO\n";
                return;
            }
        }
    }

/*
    if(l > r){

        if(l >= 1 && u >= 1){
            --u,--l;
        }

        if(u >= 1 && r >= 1){
            u--;
            r--;
        }
    }
    else{
        
        if(l >= 1 && u >= 1){
            --u,--l;
        }

        if(u >= 1 && r >= 1){
            u--;
            r--;
        }
    }

    if(l > r){
        if(l >= 1 && d >= 1){
        --d,--l;
        }
        if(d >= 1 && r >= 1){
            d--;
            r--;
        }
    }
    else{
        if(d >= 1 && r >= 1){
            d--;
            r--;
        }
        if(l >= 1 && d >= 1){
            --d,--l;
        }
    }
*/
    
    if(d < 0 || r<0 || u< 0||l < 0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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