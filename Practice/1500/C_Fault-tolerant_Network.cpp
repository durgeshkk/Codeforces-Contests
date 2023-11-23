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
 
ll helper(ll x,vector<ll> &v){
ll mn=1e18;    
    for(ll i=0;i<v.size();i++)
    {
        ll dk = abs(x-v[i]);
        mn=min(mn,dk);
    }
    return mn;
}

void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    vector<ll> cost(n);
    enter(cost);

    ll ans1 = abs(cost[0]-v[0]) + abs(cost[n-1]-v[n-1]);
    ll ans2 = abs(cost[n-1]-v[0]) + abs(cost[0]-v[n-1]);

    ll mn1=helper(v[0],cost); 
    ll mn2=helper(v[n-1],cost); 
    ll mn3=helper(cost[0],v); 
    ll mn4=helper(cost[n-1],v);

    //          |X
    ll ans3 = abs(v[0]-cost[0])+mn2+mn4;
    //          X|
    ll ans4=abs(v[n-1]-cost[n-1])+mn1+mn3;
    //          XX
    ll ans5=abs(v[0]-cost[n-1])+mn2+mn3;
    //          XX
    ll ans6=abs(v[n-1]-cost[0])+mn1+mn4;
    // Alan Walker
    ll ans7=mn1+mn2+mn3+mn4;
/*
    //          |X
    ll val1 = abs(cost[0]-v[0]);
    ll x = cost[n-1];
    ll diff = 1e18;
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-v[i]));
    }
    ll val2 = diff;

    diff = 1e18;
    ll y = v[n-1];
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-cost[i]));
    }
    ll val3 = diff;
    ll ans3 = val1+val2+val3;

    //          X|
    val1 = abs(cost[n-1]-v[n-1]);
    x = cost[0];
    diff = 1e18;
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-v[i]));
    }
    val2 = diff;

    diff = 1e18;
    y = v[0];
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-cost[i]));
    }
    val3 = diff;
    ll ans4 = val1+val2+val3;


    //          XX
    val1 = abs(cost[0]-v[n-1]);
    x = cost[n-1];
    diff = 1e18;
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-v[i]));
    }
    val2 = diff;

    diff = 1e18;
    y = v[0];
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-cost[i]));
    }
    val3 = diff;
    ll ans5 = val1+val2+val3;

    // 2nd XX from oppo side
    val1 = abs(cost[n-1]-v[0]);
    x = cost[0];
    diff = 1e18;
    for(ll i = 0;i<n;++i){
        diff = min(diff,abs(x-v[i]));
    }
    val2 = diff;

    diff = 1e18;
    y = v[n-1];
    for(ll i =0;i<n;++i){
        diff = min(diff,abs(x-cost[i]));
    }
    val3 = diff;
    ll ans6 = val1+val2+val3;

    // Alan Walker Case:
    diff = 1e18;
    for(ll i =0;i<n;++i){
        ll dk = abs(v[i]-cost[0])+abs(v[i]-cost[n-1]);
        diff = min(diff,dk);
    }

    val1 = diff;
    
    diff = 1e18;
    for(ll i =0;i<n;++i){
        ll dk = abs(v[0]-cost[i])+abs(v[n-1]-cost[i]);
        diff = min(diff,dk);
    }

    val2 = diff;
    ll ans7 = val1+val2;
*/
    vector<ll> ak;
    ak.push_back(ans1);
    ak.push_back(ans2);
    ak.push_back(ans3);
    ak.push_back(ans4);
    ak.push_back(ans5);
    ak.push_back(ans6);
    ak.push_back(ans7);
    sort(ak.begin(),ak.end());
    ll ans = ak[0];

    cout<<ans<<endl;
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