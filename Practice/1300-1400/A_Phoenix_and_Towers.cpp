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
 
    ll n,m,x;
    cin>>n>>m>>x;

    vector<pair<ll,ll>> v(n);
    
    for(ll i=0;i<n;i++){
        ll val;
        cin>>val;
        v.push_back({val,i});
    }

    sort(v.begin(),v.end(),greater<> ());
    
    // for(ll i= 0;i<n;++i){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    vector<vector<ll>> ak(m);

    set<pair<ll,ll>> s;
    for(ll i = 0;i<m;++i){
        pair<ll,ll> p = v[i];
        s.insert({p.first,i});
        ak[i].push_back(p.second);
    }

    // for(auto it:s){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<"----------------\n";
    for(ll i = m;i<n;++i){
        pair<ll,ll> p = v[i];
        pair<ll,ll> p2 = *s.begin();
        /*
        cout<<p.first<<" "<<p.second<<endl;
        cout<<p2.first<<" "<<p2.second<<endl;
        cout<<"\n";
     
        cout<<"---------I1-------\n";
        for(auto it:s){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<"---------I1-------\n";
        cout<<"\n";

        cout<<"---------I2-------\n";
        for(auto it:s){
            cout<<it.first<<" "<<it.second<<endl;
        }
        cout<<"---------I2-------\n";*/
        s.erase(s.find(p2));
        p2.first += p.first;
        s.insert(p2);
        ak[p2.second].push_back(p.second);
    }

    // for(auto it:s){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<"----------------\n";

    ll mn = INT16_MAX,mx = INT16_MIN;
    pair<ll,ll> pmn = *s.begin();
    pair<ll,ll> pmx = *s.rbegin();
    mn = pmn.first;
    mx = pmx.first;

    // cout<<mn<<" "<<mx<<endl;

    if(mx-mn > x){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    vector<ll> ans(n);
    for(ll i = 0;i<m;++i){
        for(ll j = 0;j<ak[i].size();++j){
            ans[ak[i][j]] = (i+1);
        }
    }
    show(ans);
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