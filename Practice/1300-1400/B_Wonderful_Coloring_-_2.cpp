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

    ll k;
    cin>>k;

    vector<ll> v(n),ak;
    enter(v);

    map<ll,ll> mp,mp2;
    vector<pair<ll,ll>> p;
    for(ll i=0;i<n;i++){
        mp[v[i]]++;
        p.push_back({v[i],i});
    }

    sort(p.begin(),p.end());

    // for(auto it:p){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }


    ll prev = 1;
    for(ll i = 0;i<n;++i){
        // cout<<prev<<" "<<mp2[p[i].first]<<endl;
        prev %= (k+1);
        // cout<<p[i].first<<" --> ";
        if(mp2[p[i].first] < k || mp2.find(p[i].first) == mp2.end()){
            mp2[p[i].first]++;
            p[i].first = prev;
            prev++;
            if(prev == k+1){
                prev = 1;
            }
        }
        else{
            mp2[p[i].first]++;
            p[i].first = 0;
        }
        // cout<<p[i].first<<endl;
    }

    /*
    cout<<"--------------------\n";
    for(auto it:mp2){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"--------------------\n";
    for(auto it:p){
        cout<<it.first<<" "<<it.second<<endl;
    }
    */

    map<ll,ll> color;
    for(auto it:p){
        color[it.first]++;
    }
/*
    cout<<endl;

    for(auto it:color){
        cout<<it.first<<" "<<it.second<<endl;
    }
*/

    ll mn = INT_MAX;
    for(auto it:color){
        if(it.second < mn && it.first != 0){
            mn = it.second;
        }
    }

    // cout<<"MN : "<<mn<<endl;
    // cout<<"--------------------\n";
    // for(auto it:color){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    // cout<<"--------------------\n";
    
    for(auto &it:p){
        // cout<<it.first<<" "<<it.second<<endl;
        if(it.first == 0){
            continue;
        }

        if(color[it.first] > mn){
            // cout<<"aslkn "<<it.first<<" 1 \n";
            color[it.first]--;
            it.first = 0;
            // cout<<"aslkn "<<it.first<<" 1 \n";
        }
    }
    // cout<<"--------------------\n";

    // for(auto it:color){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<"--------askdakb------------\n";*/
/*
    vector<ll> ans;
    for(ll i = 0;i<n;++i){
        if(mp2.find(v[i]) == mp.end()){
            ans.push_back(mp2[v[i]]+1);
        }
        else if(mp2[v[i]] < k){
            ans.push_back(mp2[v[i]]+1);
        }
        else if(mp2[v[i]] >= k){
            ans.push_back(0);
        }
        mp2[v[i]]++;
    }
    show(ans);*/
    
    // cout<<endl;
    // for(auto it:p){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // cout<<endl;

// /*
    for(auto &it:p){
        swap(it.first,it.second);
    }


    // for(auto it:p){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    sort(p.begin(),p.end());

    for(auto it:p){
        ak.push_back(it.second);
    }
    show(ak);
    // */
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