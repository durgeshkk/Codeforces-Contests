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
 
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*
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
 
ll fact[1000005];
ll powfact[1000005];
void precomputefact(){
   fact[0] = 1;
   ll ans = 1;
   for(ll i = 1;i<=1000005;++i){
       ans = (ans*i)%mod;
       fact[i] = ans;
       powfact[i] = power(fact[i],mod-2,mod);
   }
   powfact[0] = 1;
}

ll nCr(ll n,ll r){
    ll at = powfact[r];
    ll at2 = powfact[n-r];
    at = mod_mul(at,at2,mod);
    ll ele = mod_mul(at,fact[n],mod);
    return ele;
}


//  "A" : 65, "a" : 97  (-> |) (<- &(~))
vector<string> tmp;
bool issafe(ll i,ll j,ll x,ll y){
    if(i < 0 || j<0||i>x||j>y){return 0;}
    return 1;
}

void dfs(ll i,ll j,ll x,ll y,string st) {
    if(!issafe(i,j,x,y)){
        return;
    }

    if(i == x and j == y){tmp.push_back(st);return;}

    dfs(i+1,j,x,y,st+'H');
    dfs(i,j+1,x,y,st+'V');
    return;
}

vector<string> getPath(vector<string> journey){
    vector<string> ans;
    for(ll i = 0;i<journey.size();++i){
        tmp.clear();
        ll x = journey[i][0]-'0';
        ll y = journey[i][1]-'0';
        ll k = journey[i][2]-'0';
        dfs(0,0,x,y,"");
        sort(all(tmp));
        cout<<tmp.size()<<endl;
        return ans;
        string sa = tmp[k];
        ans.push_back(sa);
    }
    return ans;
} 

void permute(string& a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else {
        // Permutations made
        for (int i = l; i <= r; i++) {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l + 1, r);
 
            // backtrack
            swap(a[l], a[i]);
        }
    }
}

void solve()
{
 
    ll n;
    cin>>n;
    vector<string> v;
    if(n == 1){
        v.push_back("HV");
        v.push_back("VH");
    }else if(n == 2){
        string st = "HHVV";
        ll ele = (fact[2*n])/(2*fact[n]);
        for(ll i = 0;i<ele;++i){
            v.push_back(st);
            next_permutation(all(st));
        }
        show(v);
    }else if(n == 3){
        string st = "HHHVVV";
        ll ele = (fact[2*n])/(2*fact[n]);
        for(ll i = 0;i<ele;++i){
            v.push_back(st);
            next_permutation(all(st));
        }
        cout<<v.size()<<endl;
        show(v);
    }else if(n == 4){

    }else if(n == 5){

    }else if(n == 6){

    }else if(n == 7){

    }else if(n == 8){
    }else if(n == 9){

    }else{

    }

    string st = "HHHVVV";
    

    // vector<string> v;
    // for(ll i = 0;i<n;++i){
    //     ll a,b,c;cin>>a>>b>>c;
    //     string st;
    //     st += to_string(a);
    //     st += to_string(b);
    //     st += to_string(c);
    //     v.push_back(st);
    // }

    // vector<string> ans = getPath(v);
    // for(auto it:ans){
    //     cout<<it<<endl;
    // }
    //for(ll i=0;i<n;i++){
       //cin>>v[i];
    //}
 
    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with ans now
   // use setprecision before ans
   precomputefact();
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