#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
using namespace std;
/*
ll mod = (ll)(1e9+7);
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
}
 
bool isPrime(ll n){
   if (n <= 1)
       return false;
   for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
 
bool isPalindrome(string str)
{
    ll low = 0;
    ll high = str.length() - 1;

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
*/ 
void solve()
{
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);
 
    map<ll, vector<ll>> m1, m2;
 
    for (ll i = 0; i < v.size(); i++)
    {
        m1[v[i]].push_back(i);
    }

    vector<ll> k = v;
    sort(k.begin(), k.end());
 
    for (ll i = 0; i < k.size(); i++)
    {
        m2[k[i]].push_back(i);
    }

    ll e1 = 0;
    ll e2 = 0;
    ll o1 = 0;
    ll o2 = 0;
    ll f = 1;
    for (auto it1 : m1)
    {
        for (auto it : m1[it1.first])
        {
            if (it % 2 == 0)
            {
                e1++;
            }
            else
            {
                o1++;
            }
        }
 
        for (auto it : m2[it1.first])
        {
            if (it % 2 == 0)
            {
                e2++;
            }
            else
            {
                o2++;
            }
        }
 
        if (o1 == o2 && e1 == e2)
        {
            continue;
        }
        else
        {
            cout << "NO" << endl;
            f = 0;
            break;
        }
    }
    if (f == 1)
    {
        cout << "YES" << endl;
    }

/*
    multiset<pair<ll,ll>> ms;
    multiset<pair<ll,ll>> msi;
    map<ll,ll> mp;

    for(ll i=0;i<n;i++){
        ms.insert({v[i],i+1});
        mp[v[i]] = 0;
        msi.insert({i+1,v[i]});
    }

    for(auto it:ms){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"-------\n";

    for(ll i = 0;i<n-1;++i){

        pair<ll,ll> p1 = *(ms.begin());
        cout<<"p1 : ";
        cout<<p1.first<<" "<<p1.second<<endl;
        if(p1.first == v[i]){
            ms.erase(p1);
            cout<<"----------\n";
            continue;
        }

        pair<ll,ll> p2 = *(ms.find({v[n-1],n}));
        cout<<"p2 : ";
        cout<<p2.first<<" "<<p2.second<<endl;
        pair<ll,ll> p3 = *(ms.find({v[i],i+1}));
        cout<<"p3 : ";
        cout<<p3.first<<" "<<p3.second<<endl;
        
        ms.erase(p1);
        ms.erase(p2);
        ms.erase(p3);

        pair<ll,ll> p4,p5;
        ll val = p1.first;
        if(val & 1){
            p4.first = p3.first;
            p4.second = p1.second;
            swap(v[i],p4.first);
            mp[p4.first]++;
        }
        else{
            p4.first = p2.first;
            p4.second = p1.second;

            p5.first = p3.first;
            p5.second = p2.second;

            mp[p4.first]++;
            mp[p5.first]++;
            swap(v[i],p4.first);
            ms.insert(p4);
            ms.insert(p5);
        }
        ++val;
        cout<<"p4 : ";
        cout<<p4.first<<" "<<p4.second<<endl;
        cout<<"p5 : ";
        cout<<p5.first<<" "<<p5.second<<endl;

        cout<<"----------\n";
    }

    for(auto it:mp){
        if(it.second & 1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    */
    // if(ms & 1){
    //     cout<<"NO\n";
    // }
    // else{
    //     cout<<"YES\n";
    // }
 
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