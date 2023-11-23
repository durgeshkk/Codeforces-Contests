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

    vector<string> v(n);
    for(ll i = 0;i<n;++i){
        string s;
        cin>>s;
        v[i]=s;
    }

    vector<ll> a,b,c,d,e;

    for(ll i=0;i<n;i++){
        string s = v[i];
        ll k = s.size();
        // cout<<s<<" ";
        // cout<<k<<endl;
        
        map<char,ll> mp;
        mp['a'] = 0;
        mp['b'] = 0;
        mp['c'] = 0;
        mp['d'] = 0;
        mp['e'] = 0;

        for(ll j = 0;j<k;++j){
            mp[s[j]]++;
        }

        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        if(mp['a'] == 0){
            a.push_back(-1*k);
        }
        else{
            ll oth = k-mp['a'];
            // cout<<oth<<endl;
            ll ak = mp['a']-oth;
            // cout<<ak<<endl;
            a.push_back(ak);
        }

        if(mp['b'] == 0){
            b.push_back(-1*k);
        }
        else{
            ll oth = k-mp['b'];
            ll ak = mp['b']-oth;
            b.push_back(ak);
        }

        if(mp['c'] == 0){
            c.push_back(-1*k);
        }
        else{
            ll oth = k-mp['c'];
            ll ak = mp['c']-oth;
            c.push_back(ak);
        }

        if(mp['d'] == 0){
            d.push_back(-1*k);
        }
        else{
            ll oth = k-mp['d'];
            ll ak = mp['d']-oth;
            d.push_back(ak);
        }

        if(mp['e'] == 0){
            e.push_back(-1*k);
        }
        else{
            ll oth = k-mp['e'];
            ll ak = mp['e']-oth;
            e.push_back(ak);
        }
    }


    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());

    // show(a);
    // show(b);
    // show(c);
    // show(d);
    // show(e);
 
    ll sm = 0;
    ll mx = 0;
    ll f = 0;
    for(ll i = 0;i<a.size();++i){
        sm += a[i];
        if(sm > 0){
            f = 1;
            mx = max(mx,i+1);
            // break;
        }
        else{
            break;
        }
    }

    if(sm > 0){
        mx = max(mx,n);
    }

    sm = 0,f = 0;
    for(ll i = 0;i<b.size();++i){
        sm += b[i];
        if(sm > 0){
            f = 1;
            mx = max(mx,i+1);
            // break;
        }
        else{
            break;
        }
    }
    if(sm > 0){
        mx = max(mx,n);
    }

    sm = 0;
    f = 0;
    for(ll i = 0;i<c.size();++i){
        sm += c[i];
        if(sm > 0){
            f = 1;
            mx = max(mx,i+1);
            // break;
        }
        else{
            break;
        }
    }
    if(sm > 0){
        mx = max(mx,n);
    }

    sm = 0;
    f = 0;
    for(ll i = 0;i<d.size();++i){
        sm += d[i];
        if(sm > 0){
            f = 1;
            mx = max(mx,i+1);
            // break;
        }
        else{
            break;
        }
    }
    if(sm > 0){
        mx = max(mx,n);
    }

    sm = 0;
    f = 0;
    for(ll i = 0;i<e.size();++i){
        sm += e[i];
        if(sm > 0){
            f = 1;
            mx = max(mx,i+1);
            // break;
        }
        else{
            break;
        }
    }

    if(sm > 0){
        mx = max(mx,n);
    }

    cout<<mx<<endl;

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