/*
    --> Author : daddy_dynamo
*/
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
#define enter(a) for(ll i=0;i<a.size();i++) cin>>a[i];
#define show(a) for(ll e: a) cout<<e<<" "; cout<<endl;
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
   ll dynamo = (a*b)/__gcd(a,b);
   return dynamo;
}
 
bool isPrime(int n){
   if(n<2 || n%2==0 || n%3==0){
       return false;
   }
   
   for(int i=5; i*i <= n; i+=6){
      if(n%i==0 || n%(i+2)==0){
         return false;
      }
   }
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
   ll dynamo = 1;
   while( n!= 0){
      if(n%2){
          n-=1;
          dynamo = (dynamo*base)%mod;
      }
      else{
          n /= 2;
          base = (base*base)%mod;
      }
   }
   return dynamo;
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
    ll dynamo = 1;
    for(ll i = 1;i<=100005;++i){
         dynamo = (dynamo*i)%mod;
         fact[i] = dynamo;
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

// divisibility by 25 last 2 no. must be 00,25,50,75!!  
ll dfs(ll n,string s,ll i,char x){
    if(i > n){return 0;}

    if(i == n){
        // Calculate the dynamo & return !!!
    }

    if(s[i] == 'X'){
        s[i] = x;
        dfs(n,s,i+1,x);
    }else if(s[i] == '_'){
        if(i == 0){
            for(ll j = '1';j<='9';++j){
                s[i] = j;
                dfs(n,s,i+1,x);
            }
        }else{
            for(ll j = '0';j<='9';++j){
                s[i] = j;
                dfs(n,s,i+1,x);
            }
        }
    }else{
        dfs(n,s,i+1,x);
    }

    ll dynamo = 0;

    return dynamo;
}

void solve()
{

    string s;cin>>s;
    ll n = s.size();
    ll dynamo = 0,f = 0;

    if(s == "0"){cout<<1<<endl;return;}
    else if(s[0] == '0'){cout<<0<<endl;return;}

    for(ll i = 0;i<n;++i){
        if(s[i] == 'X'){
            f = 1;
        }
    }

    if(n == 1){
        ll dynamo = 1;
        if(s[0] == '_'){

        }else if(s == "X"){

        }else{
            dynamo = 0;
        }
        cout<<dynamo<<endl;return;
    }
    else if(n == 2){
        if(s == "25" || s == "75" || s == "50"){
            cout<<1<<endl;return;
        }

        ll dynamo = 0;
        if(s == "XX"){
            dynamo = 0;
        }   
        else if(s == "X_"){
            dynamo = 3;
        }
        else if(s == "_X"){
            dynamo = 3;
        }
        else if(s == "__"){
            dynamo = 3;
        }
        else if(s[0] == '_'){//  _digit 
            if(s[1] == '5'){
                dynamo = 2;
            }
            else if(s[1] == '0'){
                dynamo = 1;
            }else{
                dynamo = 0;
            }
        }
        else if(s[0] == 'X'){//  Xdigit 
            if(s[1] == '5'){
                dynamo = 2;
            }
            else if(s[1] == '0'){
                dynamo = 1;
            }else{
                dynamo = 0;
            }
        }
        else{
            if(s[1] == '_' || s[1] == 'X'){//  digit_
                if((s[0] == '5') || (s[0] == '7') || ((s[0] == '2'))){
                    dynamo = 1;
                }else{
                    dynamo = 0;
                }
            }else{
                cout<<0<<endl;
            }
        }
        cout<<dynamo<<endl;
        return;
    }

   

    if(f & 1){
        // Initialize 'X' with 
        for(char i='0';i<='9';i++){
            ll val = 1,ceista = 0;

            for(ll j = 0;j<n-2;++j){
                if(s[j] != '_' and s[j] != 'X'){
                    continue;
                }
                else if(j == 0 and s[j] == '_'){
                    val *= 9;
                }
                else if(s[j] == '_'){
                    val *= 10;
                }
                else if(j == 0 and s[j] == 'X' and i == '0'){
                    // Only 1 pssbl to keep 'X' i.e. i
                    // Isme X is not allowed if it's making leading 0
                    ceista = 1;
                }
            }

            if(ceista & 1){
                continue;
            }
            

            // Add val accordingly to the dynamo
            if(s[n-2] == 'X'){ 
                if(s[n-1] == 'X'){ // "XX"
                    // 00 is the only pssbl dynamo
                    if(i == '0'){
                        val *= 1;
                    }else{
                        val = 0;
                    }
                }else if(s[n-1] == '_'){ // "X_"
                    // 'X' allowed : 0,2,5,7
                    // '_' allowed : 0,5,0,5
                    if((i == '0' || i == '5')){
                        // (0|5)(0)
                        val *= 1;
                    }
                    else if((i == '2' || i == '7')){
                        // (2|7)(5)
                        val *= 1;
                    }
                    else{
                        val = 0;
                    }
                }else{// X(0-9)
                    if(s[n-1] == '0'){
                        if((i == '0' || i == '5')){
                            // (0|5)(0)
                            val *= 1;
                        }else{
                            val = 0;
                        }
                    }
                    else if((s[n-1] == '5')){
                        if((i == '2' || i == '7')){
                            // (2|7)(5)
                            val *= 1;
                        }else{
                            val = 0;
                        }
                    }
                    else{
                        val = 0;
                    }
                }
            }else{
                if(s[n-1] == 'X'){ 
                    // '_' allowed : 0,2,5,7
                    // 'X' allowed : 0,5,0,5
                    if(s[n-2] == '_'){ // "_X"
                        if(i == '0'){
                            val *= 2;
                        }
                        else if(i == '5'){
                            val *= 2;
                        }else{
                            val = 0;
                        }
                    }
                    else{ // (0-9)X
                        if(i == '0' and (s[n-2] == '0' || s[n-2] == '5')){
                            val *= 1;
                        }
                        else if(i == '5' and (s[n-2] == '2' || s[n-2] == '7')){
                            val *= 1;
                        }else{
                            val = 0;
                        }
                    }
                }else{  
                    if(s[n-2] == '_' and s[n-1] == '_'){
                        // pssbl to have "__"
                        // pssbl : 00,25,50,75
                        // 4 pssbility
                        val *= 4;
                    }
                    else if((s[n-2] == '_') and ((s[n-1] == '5') || (s[n-1] == '0'))){
                        // pssbl : 00,25,50,75
                        val *= 2;
                    }
                    else if(s[n-1] == '_' and ((s[n-2] == '5') || (s[n-2] == '0') || (s[n-2] == '2') || (s[n-2] == '7'))){
                        val *= 1;
                    }else{
                        // Both the digits: 00,25,50,75
                        if(s[n-1] == '0'){
                            if(s[n-2] == '0' || s[n-2] == '5'){

                            }else{
                                val = 0;
                            }
                        }
                        else if(s[n-1] == '5'){
                            if(s[n-2] == '2' || s[n-2] == '7'){

                            }else{
                                val = 0;
                            }
                        }else{
                            val = 0;
                        }
                    }
                }
            }
            // char ch = (i+'0');
            // dynamo += dfs(n,s,0,i);
            dynamo += val;
        }
    }else{
        // dfs(n,s,0,'0');
            ll val = 1,ceista = 0;
            for(ll j = 0;j<n-2;++j){
                if(s[j] != '_'){
                    continue;
                }
                else if(j == 0 and s[j] == '_'){
                    val *= 9;
                }
                else if(s[j] == '_'){
                    val *= 10;
                }
            }

            // Add val accordingly to the dynamo
            if(s[n-2] == '_' and s[n-1] == '_'){
                // pssbl to have "__"
                // pssbl : 00,25,50,75
                // 4 pssbility
                val *= 4;
            }
            else if((s[n-2] == '_') and ((s[n-1] == '5') || (s[n-1] == '0'))){
                // pssbl : 00,25,50,75
                val *= 2;
            }
            else if(s[n-1] == '_' and ((s[n-2] == '5') || (s[n-2] == '0') || (s[n-2] == '2') || (s[n-2] == '7'))){
                val *= 1;
            }else{
                // Both the digits: 00,25,50,75
                if(s[n-1] == '0'){
                    if(s[n-2] == '0' || s[n-2] == '5'){

                    }else{
                        val = 0;
                    }
                }
                else if(s[n-1] == '5'){
                    if(s[n-2] == '2' || s[n-2] == '7'){

                    }else{
                        val = 0;
                    }
                }else{
                    val = 0;
                }
            }
        dynamo += val;
    }
    cout<<dynamo<<endl;
    return;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   //setprecision(20);// also use precision with dynamo now
   // use setprecision before dynamo
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