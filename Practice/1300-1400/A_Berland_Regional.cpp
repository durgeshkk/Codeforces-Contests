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
    vector<ll> team(n);
    vector<ll> skill(n);
    enter(team);
    enter(skill);

    vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++){
        v.push_back({team[i],skill[i]});
    }

    sort(v.begin(),v.end());

    map<ll,vector<ll>> mp;
    for(ll i=0;i<n;i++){
        mp[v[i].first].push_back(v[i].second);
        // cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    ll arr[n+1] = {0};
    for(auto it:mp){
        ll val = it.first;
        vector<ll> vec = it.second;

        ll sm = accumulate(vec.begin(),vec.end(),0LL);

        ll sz = vec.size();
        for(ll i = 1;i<sz;++i){
            vec[i] += vec[i-1];
        }

        if(sz >= n){
            arr[1] += sm;
            for(ll i = 2;i<=sz;++i){
                ll sd = sm;
                if(sz%i == 0){
                    arr[i] += sd;
                }
                else{
                    ll m = sz%i;
                    sd -= vec[m-1];
                    // for(ll j = 0;j<m;++j){
                    //     sd -= vec[j];
                    // }
                    arr[i] += sd;
                }
            }
        }
        else{
            for(ll i = n;i>sz;--i){
                arr[i] += 0;
            }

            if(sz == 1){
                arr[1] += sm;
            }
            else{
                arr[1] += sm;
                arr[sz] += sm;
            }
            
            for(ll i = 2;i<sz;++i){
                ll sd = sm;
                if(sz%i == 0){
                    arr[i] += sd;
                }
                else{
                    ll m = sz%i;
                    // for(ll j = 0;j<m;++j){
                    //     sd -= vec[j];
                    // }
                    sd -= vec[m-1];
                    arr[i] += sd;
                }
            }
        }
    }

    for(ll i= 1;i<=n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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