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
 
ll LCM(ll a,ll b){
   ll ans = (a*b)/__gcd(a,b);
   return ans;
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
 
void solve()
{
    string s;cin>>s;
    ll n = s.size();
    vector<ll> freq(26,0);
    for(ll i=0;i<n;i++){
        freq[s[i]-'a']++;
    }
    // show(freq);
    ll odd = 0;char ch;
    for(ll i=0;i<26;i++){
        if(freq[i] & 1){++odd;ch = ('a'+i);}
    }
    // cout<<ch<<endl;
    if(odd == 0){
        sort(all(s));
        string ak,dk;
        for(ll i = 0;i<n;i+=2){
            ak += s[i];
            dk += s[i];
        }
        reverse(all(dk));
        ak += dk;
        cout<<ak<<endl;
    }else if(odd == 1){
        string ak,dk;ll idx = -1,od = -1;
        for(ll i = 0;i<26;++i){
            if(freq[i] & 1){
                od = i;
                ll fr = freq[i];
                while(fr > 1){
                    ak += ('a'+i);
                    dk += ('a'+i);
                    fr -= 2;
                }
            }
            else{
                if(idx == -1 and od != -1){idx = i;}
                ll fr = freq[i];
                while(fr > 0){
                    ak += ('a'+i);
                    dk += ('a'+i);
                    fr -= 2;
                }
            }
        }

        string ok="",fr,rev,accha;
        if(idx > od){
            for(ll i = 0;i<26;++i){
                if(i == od){
                    while(freq[i] > 1){
                        fr += ('a'+i);
                        rev += ('a'+i);
                        freq[i]-=2;
                    }
                }else if(i< od){
                    while(freq[i] > 0){
                        fr += ('a'+i);
                        rev += ('a'+i);
                        freq[i]-=2;
                    }
                }else{
                    while(freq[i] > 0){
                        accha += ('a'+i);
                        freq[i]--;
                    }
                }
            }

            ok += fr;
            ok += accha;ok += ('a'+od);
            reverse(all(rev));
            ok += rev;
        }

        reverse(all(dk));
        ak += ch;ak += dk;
        if(ok != ""){
            ak = min(ak,ok);
        }
        cout<<ak<<endl;
    }else{
        ll flag = -1,k = -1,j = -1;
        for(ll i = 0;i<26;++i){
            if(freq[i] & 1){
                if(k == -1){k = i;}
                else if(j == -1){j = i;}
            }else{
                if((flag == -1) and (k != -1)){
                    flag = i;
                }
            }
        }
        // cout<<k<<" "<<j<<" "<<flag<<endl;
        if(j < flag){
            string ak,dk,tmp,tmp2;
            for(ll i = 0;i<26;++i){
                if(i <= j){
                    while(freq[i] > 1){
                        ak += ('a'+i);
                        dk += ('a'+i);
                        freq[i] -= 2;
                    }
                    if(i == j){
                        tmp2 += ('a'+i);
                    }
                }else{
                    while(freq[i] > 0){
                        tmp += ('a'+i);
                        tmp2 += ('a'+i);
                        freq[i]--;
                    }
                }
            }
            reverse(all(dk));
            string ak2 = ak;
            char ch = ('a'+k),ch2 = ('a'+j);
            ak += ch2;ak += tmp;ak += ch;ak += dk;
            ak2 += tmp2;ak2 += ch;ak2 += dk;
            ak = min(ak,ak2);
            cout<<ak<<endl;
            // cout<<"HI\n";
        }else{
            string ak,dk,tmp;char ch,ch2;
            for(ll i = 0;i<26;++i){
                if(i <= k){
                    while(freq[i] > 1){
                        ak += ('a'+i);
                        dk += ('a'+i);
                        freq[i] -= 2;
                    }
                    if(i == k){ch = ('a'+i);}
                }else if(i <= j){
                    while(freq[i] > 1){
                        ak += ('a'+i);
                        dk += ('a'+i);
                        freq[i] -= 2;
                    }
                    if(i == j){ch2 = ('a'+i);}
                }else{
                    while(freq[i] > 0){
                        tmp += ('a'+i);
                        freq[i] -= 1;
                    }
                }
            }
            reverse(all(dk));
            ak += ch2;ak += tmp;ak += ch;ak += dk;
            cout<<ak<<endl;
        }
    }
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
   cin >> t;
   ll i = 1;
   while (t--)
   {
       solve();
       ++i;
   }
   //solve();
   return 0;
}