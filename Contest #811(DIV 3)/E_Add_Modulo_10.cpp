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
 
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
//  /*
    ll f = 0;
    set<ll> s;
    for(ll i=0;i<n;i++){
        if(v[i]%10 == 5 || v[i]%10 == 0){
            f = 1;
        }
        s.insert(v[i]);
    }

    if(f == 1){
        if(s.size() == 1){
            cout<<"Yes\n";
            return;
        }
        else{
            if(s.size()> 2){
                cout<<"No\n";
                return;
            }

            ll val = *s.begin();
            ll rev = *s.rbegin();
            if(rev%10 != 0){
                cout<<"No\n";
                return;
            }
            else{
                ll diff = rev-val;
                if(diff == 5){
                    cout<<"Yes\n";
                }
                else{
                    cout<<"No\n";
                }
                return;
            }
        }
    }
    else{
        
        ll f5 = -1,f10=-1;
        set<ll> s2 = {2,6,14,20};
        set<ll> s4 = {4,8,18,20};
        set<ll> s8 = {8,14,16,20};
        set<ll> s6 = {6,8,12,20};

        sort(v.begin(),v.end());

        for(ll i = 0;i<n;++i){
            ll m = v[i]%10;
            if(m == 1){
                v[i] += 1;
            }
            else if(m == 7){
                v[i] += 7;
            }
            else if(m == 9){
                v[i] += 9;
            }
            else if(m == 3){
                v[i] += 3;
            }
        }
    
        sort(v.begin(),v.end());

        for(ll i = 0;i<n-1;++i){
            ll diff = v[i+1]-v[i];
            if(diff == 0){
                continue;
            }

            ll m = (v[i]%10);

            diff %= 20;
            if(m == 2){
                if(s2.find(diff) == s2.end()){
                    cout<<"No\n";
                    return;
                }
            }
            else if(m == 4){
                if(s4.find(diff) == s4.end()){
                    cout<<"No\n";
                    return;
                }
            }
            else if(m == 6){
                if(s6.find(diff) == s6.end()){
                    cout<<"No\n";
                    return;
                }
            }
            else if(m == 8){
                if(s8.find(diff) == s8.end()){
                    cout<<"No\n";
                    return;
                }
            }
        }

        cout<<"Yes\n";
    }
    // */
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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