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
 void yno(ll f){
    if(f & 1) cout<<"YES\n";
    else cout<<"NO\n";
    return;
 }
  
/*
Learning : 
    --> How to calc Suff_Rem using power
*/

void solve()
{
    string s;cin>>s;
    ll a,b;cin>>a>>b;

    ll n = s.size();
    vector<ll> suff_rem(n,1);
    ll curr = 0;
    for(ll i = s.size()-1;i>=0;--i){
        curr += (s[i]-'0')*(power(10,n-1-i,b));
        curr %= b;
        if(curr == 0){suff_rem[i] = 0;}
    }

    ll num = 0;
    for(ll i=0;i<n-1;i++){
        num *= 10;
        num += (s[i]-'0');
        num %= a;
        if(num == 0 and s[i+1] != '0' and suff_rem[i+1] == 0){
            yno(1);
            string ak = s.substr(0,i+1);
            string dk = s.substr(i+1,n);
            cout<<ak<<"\n"<<dk<<endl;
            return;
        }
    }
    yno(0);
    /*
    set<ll> st,st2;
    for(ll i=0;i<n;i++){
        num*=10;
        num += (s[i]-'0');
        num %= a;
        if(num == 0){st.insert(i);}
    }

    string ash = to_string(b);
    ll cnt = 0,f = 0;
    for(ll i = ash.size()-1;i>=0;--i){
        if(ash[i] == '0'){++cnt;f = 1;}
        else{break;}
    }
    // cout<<cnt<<endl;
    
    // cout<<cnt<<endl;

    if(st.empty()){
        // cout<<st.size()<<endl;
        yno(0);return;
    }

    if(cnt <= 0 and f == 1){
        ll ans = *st.begin();
        yno(1);
        // cout<<"HI\n";
        string ak,dk;
        for(ll i = 0;i<n;++i){
            if(i <= ans){
                ak += s[i];
            }else{
                dk += s[i];
            }
        }
        cout<<ak<<"\n"<<dk<<endl;
        return;
    }

    string tmp;
    // cout<<"OK\n";
    for(ll i = n-1;i>=0;--i){
        if(s[i] =='0'){
            string l;l += '0';
            l += tmp;
            tmp = l;
            continue;
        }

        ll sz = tmp.size();
        ll ok = 0;
        if(sz == 0){
            ok += (s[i]-'0');
        }else{
            ok += (s[i]-'0');
            for(ll i = 0;i<sz;++i){
                ok *= 10;
            }
            ll dk = stoll(tmp);
            ok += dk;
        }
        
        ok %= b;
        if(ok == 0){
            st2.insert(i);
            tmp.clear();continue;
        }
        tmp = to_string(ok);
        cout<<tmp<<endl;
    }

    ll ans = -1;
    for(auto it:st){
        cout<<it<<" ";
        if(st2.find(it+1) != st2.end()){
            ans = it;yno(1);break;
        }
    }
    cout<<endl;

    for(auto it:st2){
        cout<<it<<" ";
    }
    cout<<endl;

    if(ans == -1){
        yno(0);
    }else{
        string ak,dk;
        for(ll i = 0;i<n;++i){
            if(i <= ans){
                ak += s[i];
            }else{
                dk += s[i];
            }
        }
        cout<<ak<<"\n"<<dk<<endl;
    }*/
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