#include<bits/stdc++.h>
#include<iomanip>
#include <deque>
#include <bitset>
#include <cstdint>
#define ll long long int
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
 
bool compare(const pair<ll, ll> &x, const pair<ll, ll> &y) {
    if(x.first == y.first){
        if(x.second > y.second){
            return true;
        }
        else{
            return false;
        }
    }
    return x.first < y.first;
}

void solve()
{
 
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    ll w = 0;
    bool W = 0;
    ll ans = 0;

    ll cur  = 0;
    vector<ll> v;//store len of segs

    for(char c:s){
        if(c == 'W'){
            if(cur){
                v.push_back(cur);
                cur = 0;
            }
            w++;
            ans++;
            if(W){
                ans++;
            }
            W = 1;
        }
        else{
            W = 0;
            if(w){
                ++cur;
            }
        }
    }

    if(!w){
        cout<<max(2*k-1,0LL)<<endl;
        return;
    }

    k = min(k,n-w);
    ans += (2*k);
    sort(v.begin(),v.end());
    for(auto x:v){
        if(x<=k){
            ans++;
            k -= x;
        }
    }
    cout<<ans<<endl;
/*
    vector<pair<ll,ll>> v;
    ll sc=0;

    ll loss = 0;
    if(s[0] == 'W'){
        sc++;
    }
    else{
        loss++;
    }

    for(ll i=1;i<n;i++){
        if(s[i] == 'L'){
            loss++;
            continue;
        }

        if(s[i] == 'W' && s[i-1] == 'L'){
            v.push_back({loss,(i)});
            sc++;
            loss=0;
        }
        else{
           if(s[i] == 'W' && s[i-1] == 'W'){
                sc+=2;
           } 
        }
    }

    if(loss > 0){
        v.push_back({loss,(n)});
    }

    sort(v.begin(),v.end(),compare);
    for(auto it:v){
        // cout<<it.first<<" "<<it.second<<endl;
    }

    // cout<<sc<<endl;
    vector<ll> sl;
    for(ll i = 0;i<v.size();++i){
        
        if(k <= 0){
            cout<<sc<<endl;
            return;
        }

        if(k < v[i].first){
            if((v[i].second-v[i].first) != 0){
                if(v[i].second == n){
                    // sc += ((v[i].first*2));
                    sl.push_back((k*2));
                }
                else{
                    sl.push_back(1+(k*2));
                    // sc += (1+(v[i].first*2));
                }   
            }
            else{
                sl.push_back((k*2)-1);
                // sc += ((v[i].first*2)-1);
            }

            // sort(sl.begin(),sl.end());
            // reverse(sl.begin(),sl.end());

            // for(ll i = 0;i<sl.size();++i){
            //     cout<<sl[i]<<" ";
            // }
            // cout<<endl;

            ll tt = k;
            for(ll i = 0;i<sl.size();++i){
                if(tt <= 0){
                    cout<<sc<<endl;
                    return;
                }
                sc += sl[i];
                tt--;
            }
            sl.erase(sl.begin(),sl.end());
            cout<<sc<<endl;
            return;
        }

// ELSE
        if((v[i].second-v[i].first) != 0){
            if(v[i].second == n){
                // sc += ((v[i].first*2));
                sl.push_back((v[i].first*2));
            }
            else{
                sl.push_back(1+(v[i].first*2));
                // sc += (1+(v[i].first*2));
            }
        }
        else{
            if(v[i].second == n){
                // sc += ((v[i].first*2));
                sl.push_back((v[i].first*2)-1);
            }
            else{
                sl.push_back((v[i].first*2));
                // sc += (1+(v[i].first*2));
            }
            // sc += ((v[i].first*2)-1);
        }

        sort(sl.begin(),sl.end());
        reverse(sl.begin(),sl.end());

        for(ll i = 0;i<sl.size();++i){
            cout<<sl[i]<<" ";
        }
        cout<<endl;

        ll tt = k;
        for(ll i = 0;i<sl.size();++i){
            if(tt <= 0){
                cout<<sc<<endl;
                return;
            }
            sc += sl[i];
            tt--;
        }

        sl.erase(sl.begin(),sl.end());
        cout<<sc<<endl;
        k -= v[i].first;
        cout<<k<<endl;
    }
    
    cout<<sc<<endl;*/
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