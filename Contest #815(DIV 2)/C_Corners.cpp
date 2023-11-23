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
 
    ll n,m;
    cin>>n>>m;

    char arr[n][m];
    ll ans = 0;
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == '1'){
                ++ans;
            }
        }
    }

    // for(ll i=0;i<n;i++){
    //     for(ll j = 0;j<m;++j){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<ans<<endl;

    if(ans == 0){
        cout<<0<<endl;
        return;
    }

    // cout<<m<<" "<<n<<endl;
    // cout<<"HI\n";
    ll mn= 6;
    for(ll i=0;i<n;i++){
        for(ll j = 0;j<m;++j){
            if(arr[i][j] == '1'){
                ll val = INT16_MAX;
                if(i > 0 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '1'){
                        ++val;
                    }

                    if(arr[i-1][j-1] == '1'){
                        ++val;
                    }
                mn = min(mn,val+1);
                }

                if(i > 0 && j<m-1){
                val = 0;
                    if(arr[i-1][j] == '1'){
                        ++val;
                    }

                    if(arr[i-1][j+1] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }
                
                if(j > 0 && i<n-1){
                val = 0;
                    if(arr[i+1][j] == '1'){
                        ++val;
                    }

                    if(arr[i+1][j-1] == '1'){
                        ++val;
                    }
                mn = min(mn,val+1);
                }

                // 4th :
                if(i<n-1 && j<m-1){
                val = 0;
                    if(arr[i+1][j+1] == '1'){
                        ++val;
                    }

                    if(arr[i][j+1] == '1'){
                        ++val;
                    }
                mn = min(mn,val+1);
                }

                // 5th :
                if(i > 0 && j<m-1){
                val = 0;
                    if(arr[i-1][j+1] == '1'){
                        ++val;
                    }

                    if(arr[i][j+1] == '1'){
                        ++val;
                    }
                mn = min(mn,val+1);
                }

                // 6th :
                if(i > 0 && j>0){
                val = 0;
                    if(arr[i-1][j-1] == '1'){
                        ++val;
                    }

                    if(arr[i-1][j] == '1'){
                        ++val;
                    }

                mn = min(mn,val+1);
                }

                // 7th :
                if(j > 0 && i<n-1){
                val = 0;
                    if(arr[i+1][j-1] == '1'){
                        ++val;
                    }

                    if(arr[i][j-1] == '1'){
                        ++val;
                    }

                    mn = min(mn,val+1);
                }

                // 8th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i+1][j+1] == '1'){
                        ++val;
                    }

                    if(arr[i+1][j] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }

                // 9th :
                if(i > 0 && j<m-1){
                    val = 0;
                    if(arr[i-1][j] == '1'){
                        ++val;
                    }

                    if(arr[i][j+1] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }

                // 10th :
                if(i < n-1 && j<m-1){
                    val = 0;
                    if(arr[i][j+1] == '1'){
                        ++val;
                    }

                    if(arr[i+1][j] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }

                // 11th :
                if(i < n-1 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '1'){
                        ++val;
                    }

                    if(arr[i+1][j] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }

                // 12th :
                if(i >0 && j>0){
                    val = 0;
                    if(arr[i][j-1] == '1'){
                        ++val;
                    }

                    if(arr[i-1][j] == '1'){
                        ++val;
                    }
                    mn = min(mn,val+1);
                }
            }
        }
    }
 
 /*
    ll cnt = 0;
    ll mn = 6;
    if(arr[0][0] == '1'){
        ++cnt;
    }
    if(arr[0][1] == '1'){
        ++cnt;
    }
    if(arr[1][0] == '1'){
        ++cnt;
    }
    if(arr[1][1] == '1'){
        ++cnt;
    }
    mn = min(mn,cnt);

    cnt = 0;
    if(arr[n-2][0] == '1'){
        ++cnt;
    }
    if(arr[n-2][1] == '1'){
        ++cnt;
    }
    if(arr[n-1][0] == '1'){
        ++cnt;
    }
    if(arr[n-1][1] == '1'){
        ++cnt;
    }
    mn = min(mn,cnt);

    cnt = 0;
    if(arr[n-2][m-2] == '1'){
        ++cnt;
    }
    if(arr[n-2][m-1] == '1'){
        ++cnt;
    }
    if(arr[n-1][m-2] == '1'){
        ++cnt;
    }
    if(arr[n-1][m-1] == '1'){
        ++cnt;
    }
    mn = min(mn,cnt);


    if(arr[0][m-1] == '1'){
        ++cnt;
    }
    if(arr[0][m-2] == '1'){
        ++cnt;
    }
    if(arr[1][m-1] == '1'){
        ++cnt;
    }
    if(arr[1][m-2] == '1'){
        ++cnt;
    }
    mn = min(mn,cnt);
*/

    // cout<<mn<<" ";
    if(mn == 1){
        cout<<ans<<endl;
    }
    else if(mn == 2){
        cout<<ans-1<<endl;
    }
    else{
        cout<<(ans-2)<<endl;
    }

    //ordered_set o_set; //use karte samay yaad rhe tree fxn remove karna h
 
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