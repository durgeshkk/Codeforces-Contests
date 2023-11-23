#include<bits/stdc++.h>
#include<iomanip>
#define ll long long int
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
using namespace std;
ll mod = (ll)(1e9+7);

void solve(){
 
    ll n;
    cin>>n;

    vector<ll> v(n);
    enter(v);

    if(is_sorted(v.begin(),v.end())){
        ll diff = v[1]-v[0];
        for(ll i=2;i<n;i++){
            ll val = v[i]-v[i-1];
            if(val != diff){
                cout<< -1 <<endl;
                return;
            }
        }
        cout<<0<<endl;
        return;
    }

    if(n == 1){
        cout<<0<<endl;
        return;
    }

    ll diff = v[1]-v[0];
    ll mx = *max_element(v.begin(),v.end());

    for(ll i=1;i<n;i++){
        if(v[i] >= v[i-1]){
            diff = (v[i]-v[i-1]);
            break;
        }
    }

    ll f = 0,m = INT16_MIN;
    for(ll i=1;i<n;i++){
        ll val = (v[i] - v[i-1]);

        if(val == diff){
            continue;
        }

        if(val > 0){
            cout<< -1 <<endl;
            return;
        }

        m = (v[i-1]+diff-v[i]);
        break;
    }

    if(m == INT16_MIN){
        cout<<0<<endl;
        return;
    }

    if((m <= mx)){
        cout<< -1 <<endl;
        return;
    }

    for (ll i = 1; i < n; i++){
        if (v[i] != (v[i - 1] + diff) % m){
            cout << -1 << endl;
            return;
        }
    }

    cout<<m<<" "<<diff<<endl;
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
   ll t=1;
   cin >> t;
   ll i = 1;
   while (t--)
   {
        // cout<<i<<" ";
       solve();
       ++i;
   }
   //solve();
   return 0;
}

/*
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

    set<ll> s(v.begin(),v.end());

    if(s.size() <= 1){
        cout<< 0 <<endl;
        return;
    }

    // ll mx = *max_element(v.begin(),v.end());
    // cout<<mx<<endl;
    // if((v[v.size()-1] == mx) && ()){
    //     cout<< -1 <<endl;
    //     return;
    // }

    // if(is_sorted(v.begin(),v.end())){
    //     cout<< 0 <<endl;
    //     return;
    // }

    ll c = 0;
    for(ll i=1;i<n;i++){
        if(v[i] >= v[i-1]){
            c = v[i]-v[i-1];
            break;
        }
    }


    ll m = 0;
    for(ll i=1;i<n;i++){
        if(v[i] <= v[i-1]){
            m = (v[i-1]+c-v[i]);
            break;
        }
    }

    if(c == 0 && s.size() >= 2){
        cout<< -1 <<endl;
        return;
    }

    for(ll i=1;i<n;i++){
        if(v[i] < v[i-1]){
            ll val = ((v[i-1]+c)%m);
            if(val != v[i]){
                cout<< -1 << endl;
                return;
            }
        }
        else{
            ll val = ((v[i-1]+c));
            if(val != v[i]){
                cout<< -1 << endl;
                return;
            }
        }
    }

    ll mx = *s.rbegin();

    if(m == 0 && c != 0){
        cout<< 0 <<endl;
        return;
    }

    if((s.find(m) != s.end()) || (mx >= m)){
        cout<< -1 <<endl;
        return;
    }
    cout<<m<<" "<<c<<endl;
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
   ll i = 1;
   while (t--)
   {
       solve();
   }
   //solve();
   return 0;
}
*/