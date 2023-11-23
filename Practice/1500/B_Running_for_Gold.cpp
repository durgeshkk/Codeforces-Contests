#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
 

 
ll c = 1e9 + 7;
 
void solve()
{
    ll n;
    cin >> n;
    ll arr[n][5];
 
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 1; i < n; i++)
    {
        ll c = 0;
        for (ll j = 0; j < 5; j++)
        {
            if (arr[ans][j] > arr[i][j])
            {
                c++;
            }
        }
        if (c >= 3)
        {
            ans = i;
        }
    }
 
    for (ll i = 0; i < n; i++)
    {
        ll c = 0;
        for (ll j = 0; j < 5; j++)
        {
            if (arr[ans][j] > arr[i][j])
            {
                c++;
            }
        }
        if (c >= 3)
        {
            cout << -1 << endl;
            return;
        }
    }
 
    cout << ans + 1 << endl;
}
  
/*
void solve()
{
 
    ll n;
    cin>>n;

    vector<vector<ll>> v(n,vector<ll> (5,0));
 
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<5;++j){
            cin>>v[i][j];
        }
    }

    // Use 5 sets & move ahead by lower_bound :
    multiset<pair<ll,ll>> s1;
    multiset<pair<ll,ll>> s2;
    multiset<pair<ll,ll>> s3;
    multiset<pair<ll,ll>> s4;
    multiset<pair<ll,ll>> s5;
    
    for(ll i = 0;i<n;++i){
        s1.insert({v[i][0],i+1});
    }
    for(ll i = 0;i<n;++i){
        s2.insert({v[i][1],i+1});
    }
    for(ll i = 0;i<n;++i){
        s3.insert({v[i][2],i+1});
    }
    for(ll i = 0;i<n;++i){
        s4.insert({v[i][3],i+1});
    }
    for(ll i = 0;i<n;++i){
        s5.insert({v[i][4],i+1});
    }
    
    // map<ll,map<ll,ll>> mp;
    map<ll,multiset<ll>> mp;
    set<ll> s = {1,2,3,4,5,6};
    
    for(auto it:s1){
        pair<ll,ll> p = it;
        s.erase(s.find(p.second));
        multiset<ll> ak = mp[p.second];
        for(auto it2:s){
            ak.insert(it2);
        }
        mp[p.second] = ak;
    }


    s = {1,2,3,4,5,6};
    for(auto it:s2){
        pair<ll,ll> p = it;
        s.erase(s.find(p.second));
        multiset<ll> ak = mp[p.second];
        for(auto it2:s){
            ak.insert(it2);
        }
        mp[p.second] = ak;
    }


    s = {1,2,3,4,5,6};
    for(auto it:s3){
        pair<ll,ll> p = it;
        s.erase(s.find(p.second));
        multiset<ll> ak = mp[p.second];
        for(auto it2:s){
            ak.insert(it2);
        }
        mp[p.second] = ak;
    }

    s = {1,2,3,4,5,6};
    for(auto it:s4){
        pair<ll,ll> p = it;
        s.erase(s.find(p.second));
        multiset<ll> ak = mp[p.second];
        for(auto it2:s){
            ak.insert(it2);
        }
        mp[p.second] = ak;
    }

    s = {1,2,3,4,5,6};
    for(auto it:s5){
        pair<ll,ll> p = it;
        s.erase(s.find(p.second));
        multiset<ll> ak = mp[p.second];
        for(auto it2:s){
            ak.insert(it2);
        }
        mp[p.second] = ak;
    }

    ll ans = 0,f = 0;
    for(auto it:mp){
        // cout<<it.first<<" --> ";
        map<ll,ll> ak;
        ll val = 0;
        for(auto dk:it.second){
            ak[dk]++;
            if(ak[dk] == 3){
                val++;
            }
            // cout<<dk<<" ";
        }

        if(val == (n-1) && f == 1){
            cout<< -1 <<endl;
            return;
        }
        
        if(val == (n-1) && f == 0){
            ans++;
            f = 1;
        }
        
    }

    cout<<ans<<endl;
    */
/*
        for(ll j = 0;j<n;++j){
            ll gr = (s1.order_of_key(v[j][0]));
            ll lss = (n-gr-1);
            if(lss >= 3){
                mp[j]++;
            }
        }
    // }

    // for(ll i = 0;i<5;++i){
        for(ll j = 0;j<n;++j){
            ll gr = (s2.order_of_key(v[j][1]));
            ll lss = (n-gr-1);
            if(lss >= 3){
                mp[j]++;
            }
        }
    // }
    // for(ll i = 0;i<5;++i){
        for(ll j = 0;j<n;++j){
            ll gr = (s3.order_of_key(v[j][2]));
            ll lss = (n-gr-1);
            if(lss >= 3){
                mp[j]++;
            }
        }
    // }
    // for(ll i = 0;i<5;++i){
        for(ll j = 0;j<n;++j){
            ll gr = (s4.order_of_key(v[j][3]));
            ll lss = (n-gr-1);
            if(lss >= 3){
                mp[j]++;
            }
        }
    // }

    // for(ll i = 0;i<5;++i){
        for(ll j = 0;j<n;++j){
            ll gr = (s5.order_of_key(v[j][4]));
            ll lss = (n-gr-1);
            if(lss >= 3){
                mp[j]++;
            }
        }
    // }

    ll mx = 0;
    ll ans = 0;
    for(auto it:mp){
        if(it.second > mx){
            mx = it.second;
            ans = it.first;
        }
    }

    if(mp.size() == 0){
        cout<< -1 <<endl;
        return;
    }

    cout<<ans+1<<endl;*/

/*
    ll arr[5]={0};
    map<ll,ll> mp;
    for(ll i = 0;i<5;++i){
        mp[arr[i]]++;
    }

    for(auto it:mp){
        if(it.second >= 3){
            cout<<it.first<<endl;
            return;
        }
    }
    cout<< -1 << endl;*/

    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
//     return;
// }
 
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