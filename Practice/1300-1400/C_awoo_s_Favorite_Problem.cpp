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

    string s,t;
    cin>>s>>t;

    if(s.size() == 1){
        if(s == t){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return;
    }

    ll f = 0;
    map <char,vector<pair<ll,ll>>> mp;

    for(ll i=0;i<n;i++){
        if(s[i] == t[i]){

        }
        else if(s[i] == 'c'){
            cout<<"NO\n";
            return;
        }
        else{

            // a-->b
            if(s[i] == 'a'){
                if(t[i] == 'b'){
                    ll j = (i+1);
                    ll val = 1;
                    for(j;j<n;++j){

                        if((s[j] == 'a' && t[j] == 'a') || (s[j] == 'b' && t[j] == 'b')){
                            continue;
                        }
                        else if(s[j] == 'a' && t[j] == 'b'){
                            val++;
                        }
                        else if(s[j] == 'b' && t[j] == 'a'){
                            val--;
                        }
                        else{
                            // cout<<j<<endl;
                            f = 1;
                            break;
                        }
                        
                        if(val == 0){
                            break;
                        }
                    }
                    i = j;
                    if((val != 0)){
                        f = 1;
                        // cout<<val<<endl;
                        // cout<<"2\n";
                    }
                }
                else{
                    // cout<<"3\n";
                    f = 1;
                }
            }
/*
                        if(s[j] == 'a'){
                            continue;
                        }
                        else if(s[j] == 'b'){
                            f2 = 1;
                            swap(s[i],s[j]);
                            break;
                        }
                        else{
                            f = 1;
                            break;
                            cout<<"02COC\n";
                        }
                    }
                        mp[s[i]].push_back({i+1,j});
                        i = (j+1);
                        if(!f2){
                            f = 1;
                            cout<<"0COC\n";
                        }
                }
                else{
                    f = 1;
                    cout<<"COC\n";
                }
            }
*/
            // b-->c
            else if(s[i] == 'b'){
                if(t[i] == 'c'){
                    ll j = (i+1);
                    ll val = 1;
                    for(j;j<n;++j){

                        if((s[j] == 'b' && t[j] == 'b') || (s[j] == 'c' && t[j] == 'c')){
                            continue;
                        }
                        else if(s[j] == 'b' && t[j] == 'c'){
                            val++;
                        }
                        else if(s[j] == 'c' && t[j] == 'b'){
                            val--;
                        }
                        else{
                            f = 1;
                        }
                        
                        if(val == 0){
                            break;
                        }
                    }
                    i = j;

                    if((val != 0)){
                        f = 1;
                    }
/*
                    for(j;j<n;++j){
                        if(s[j] == 'b'){
                            continue;
                        }
                        else if(s[j] == 'c'){
                            f2 = 1;
                            swap(s[i],s[j]);
                            break;
                        }
                        else{
                            f = 1;
                            cout<<"020COC\n";
                            break;
                        }
                    }

                        mp[s[i]].push_back({i+1,j});
                        i = (j+1);

                        if(!f2){
                            f = 1;
                            cout<<"0207COC\n";
                        }
                        */
                }
                else{
                    // cout<<i<<endl;
                    // cout<<"027COC\n";
                    f = 1;
                }
            }
        }
    }

    if(f & 1){
        cout<<"NO\n";
        return;
    }
/*
    vector<pair<ll,ll>> dk = mp['a'];
    for(auto it:dk){
        ll x = it.first,y=it.second;
        for(ll i = x;i<=y;++i){
            if(t[i] != 'a'){
                cout<<"NO\n";
                return;
            }
        }
    }

    dk = mp['b'];
    for(auto it:dk){
        ll x = it.first,y=it.second;
        for(ll i = x;i<=y;++i){
            if(t[i] != 'b'){
                cout<<"NO\n";
                return;
            }
        }
    }
*/
    cout<<"YES\n";
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