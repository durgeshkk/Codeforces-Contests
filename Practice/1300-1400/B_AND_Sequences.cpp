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
 
 
ll fact[200005];
ll powfact[100005];
void precomputefact(){
    fact[0] = 1;
    ll ans = 1;
    for(ll i = 1;i<=200005;++i){
         ans = (ans*i)%mod;
         fact[i] = ans;
        //  powfact[i] = power(fact[i],mod-2,mod);
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
 
ll facti(ll n){
    if(n == 0 || n == 1){
        return 1;
    }

    ll val = 1;
    ll ans = 1;
    while(val <= n){
        ans = ans*val;
        ans %= mod;
    }
    return ans;
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<ll> v(n);
    enter(v);

    ll mn=*min_element(v.begin(),v.end());
    ll cnt=0;
    
    for(ll i = 0;i<n;++i){
        ll x = v[i];
        if(mn==x)cnt++;

        ll val = mn&x;
        if(val!=mn){
            cout<<0<<endl;
            return;
        }
    }

    ll ak = fact[n-2];
    ll dk = (cnt*(cnt-1)*1LL)%mod;
    ll ans = (ak*dk)%mod;
    cout<<ans<<endl;
    /*

    map<ll,ll> mp;
    set<ll> s;
    for(ll i=0;i<n;i++){
        s.insert(v[i]);
        mp[v[i]]++;
    }

    if(s.size() == 1){
        ll val = fact[n];
        cout<<val<<endl;
    }

    else if(v[0] == 0 && v[n-1] == 0){
        ll val = mp[0];
        if(val == 2){
            // ll ans = facti(n-2);
            ll ans = fact[n-2];
            ans = (2*ans)%mod;
            cout<<ans<<endl;
        }
        else{
            ll ans = (val*(val-1))%mod;
            ll ak = fact[val];
            // ll ak = facti(val);
            ans = (ans*ak)%mod;
            cout<<ans<<endl;
        }
    }

    else{
        ll mn = v[0];
        ll dk = v[0];
        for(ll i = 1;i<n;++i){
            dk &= v[i];
            mn = min(v[i],mn);
        }

        if(mp.find(dk) != mp.end()){
            if(mp[dk] >= 2){

            }
            else{
                cout<<0<<endl;
                return;
            }
        }
        
        ll val = dk;

        if(dk == 0){
            ll val = mp[0];
            if(val == 2){
                // ll ans = facti(n-2);
                ll ans = fact[n-2];
                ans = (2*ans)%mod;
                cout<<ans<<endl;
            }
            else{
                ll ans = (val*(val-1))%mod;
                ll ak = fact[val];
                // ll ak = facti(val);
                ans = (ans*ak)%mod;
                cout<<ans<<endl;
            }
            return;
        }
        map<ll,ll> mp2;
        for(ll i = 0;i<n;++i){
            bitset<21> s(v[i]);

            for(ll i = 0;i<21;++i){
                if(s[i] == 1){
                    mp2[i+1]++;
                }
            }
        }

        if(val != mn){
            cout<<0<<endl;
            return;
        }
        // cout<<val<<endl;

        // for(auto it:mp2){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }

        set<ll> sb;
        bitset<21> st(val);
        // cout<<st<<endl;
        for(ll i = 0;i<21;++i){
            if(st[i] == 1){
                sb.insert(i+1);
            }
        }

        // for(auto it:sb){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        for(auto it:mp2){
            if(sb.find(it.first) != sb.end()){
                if(it.second == n){

                }
                else{
                    // cout<<it.first<<" tere ";
                    cout<<0<<endl;
                    return;
                }
            }
        }

        if(mp[val] == 2){
            ll ans = fact[(n-2)];
            // ll ans = facti[(n-2)];
            ans = (2*ans)%mod;
            cout<<ans<<endl;
        }
        else{
            ll ans = (val*(val-1))%mod;
            // ll ak = facti(val);
            ll ak = fact[val];
            ans = (ans*ak)%mod;
            cout<<ans<<endl;
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
   precomputefact();
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