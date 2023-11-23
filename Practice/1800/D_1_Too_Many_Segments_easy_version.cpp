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
#define all(a) a.begin(),a.end()
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define forj(n) for (ll j = 0; j < n; j++)
#define show(a) for(auto e: a) cout<<e<<" "; cout<<endl;
using namespace std;
ll mod = (ll)(1e9+7);
 
/*
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 10; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return mod_add(arr[0], 0, b);} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
bool revsort(ll a, ll b) {return a > b;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0)n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
*/
 
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
 
 
vector<ll> adj[100004];
 
void tree(){
    ll n;
    cin>>n;

    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
//  "A" : 65, "a" : 97  (-> |) (<- &(~))
ll n,k;
vector<pair<ll,ll>> v;
/*
ll recur(ll idx,vector<ll> &tmp){
    if(idx == n){return 0;}

    ll a = LLONG_MAX;
    // Don't Pick this Seg
    ll b = 1+recur(idx+1,tmp);

    // Pick this Seg
    ll a = recur(idx+1,tmp);
    return min(a,b);
} 
*/
vector<ll> ok;
ll recur(ll idx,vector<ll> &tmp){
    if(idx == n){
        return 0;
    }

    ll b = 0;
    // Pick 
    vector<ll> z(tmp);
    ll a = 0,f = 1;
    for(ll i = v[idx].first;i<=v[idx].second;++i){
        tmp[i] += 1;
        if(tmp[i] > k){
            f = 0;
        }
    }
    if(f){
        a = 1+recur(idx+1,tmp);
        b = recur(idx+1,z);
    }else{
        b = recur(idx+1,z);
    }

    return max(a,b);
}

void solve()
{
 
    cin>>n>>k;
    ll mx = 0;
    for(ll i=0;i<n;i++){
        pair<ll,ll> p;
        cin>>p.first>>p.second;
        v.push_back(p);
        mx = max(mx,p.second);
    }

    // vector<ll> tmp(mx+5,0);
    // ll ans = recur(0,tmp);
    // cout<<(n-ans)<<endl;
    // show(ok);
    // /*
    vector<ll> pref(mx+5,0);
    for(auto it:v){
        pref[it.first]++;
        pref[it.second+1]--;
    }
    for(ll i = 1;i<=mx;++i){
        pref[i] += pref[i-1];
    }
    // show(pref);

    // vector<ll> excc;
    // map<ll,ll> mp;
    // forj(mx+1){
    //     if(pref[j] > k){
    //         mp[j] = (pref[j]-k);
    //         excc.push_back(j);
    //     }
    // }

    // for(auto it:mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }cout<<endl;

    vector<ll> ans(n+1,0);
    forj(mx+1){
        // if(pref[j] <= k){continue;}
        while(pref[j] > k){
            ll pos = -1;
            for(ll i = 0;i<n;++i){
                if((!ans[i]) and (v[i].second>=j && j>=v[i].first) and (pos == -1 || v[i].second > v[pos].second)){
                    pos = i;
                }
            }

            if(pos == -1){break;}
            ans[pos] = 1;
            for(ll k = v[pos].first;k<=v[pos].second;++k){
                pref[k]--;
            }
        }
    }

    ll sz = accumulate(all(ans),0ll);
    cout<<sz<<endl;
    forj(ans.size()){
        if(ans[j]){
            cout<<j+1<<" ";
        }
    }cout<<endl;
    /*
    set<ll> use;
    while(1){
        ll idx = -1,maxi = 0,s = -1,e = -1;
        for(ll i = 0;i<n;++i){
            if(use.find(i) != use.end()){continue;}
            ll cntr = 0;
            ll l = v[i].first,r = v[i].second;
            for(ll j = l;j<=r;++j){
                if(mp.find(j) != mp.end()){
                    ++cntr;
                }
            }
            if(cntr > maxi){
                maxi = cntr,idx = i;
                s = v[idx].first,e = v[idx].second;
            }else if(cntr == maxi){
                ll sz = (r-l);
                if(sz > (e-s)){
                    idx = i;
                    s = l,e = r;
                }
            }
        }
        // cout<<idx<<endl;
        ans.push_back(idx+1);
        use.insert(idx);
        ll l = v[idx].first,r = v[idx].second;
        for(ll j = l;j<=r;++j){
            if(mp.find(j) != mp.end()){
                mp[j]--;
                if(mp[j] == 0){
                    mp.find(mp.erase(j));
                }
            }
        }
        if(!mp.size()){break;}
    }
    // show(excc);
    ll sz = ans.size();
    cout<<sz<<endl;show(ans);
    */
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   //precomputefact();
   //createsieve();
   //bfs();//call in solve()
   //dfs(1,0);//call in solve()
 
   ll t=1;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}